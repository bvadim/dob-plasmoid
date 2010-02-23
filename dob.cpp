#include "dob.h"
#include <plasma/widgets/toolbutton.h>
#include <plasma/widgets/label.h>

dob::dob ( QObject *parent, const QVariantList &args ) /*{{{*/
        : Plasma::Applet ( parent, args ),
        m_configDialog ( 0 ),
        updateBtn ( 0 ),
        pLabel ( 0 ),
        m_icon ( "view-refresh" )
{
    updateBtn = NULL;
    setHasConfigurationInterface ( true );
    resize ( 300, 20 );
    setAspectRatioMode(Plasma::IgnoreAspectRatio);
    wm = NULL;
}/*}}}*/
dob::~dob() /*{{{*/
{
    if ( hasFailedToLaunch() )
    {
        delete m_configDialog;
        delete hp;
        delete updateBtn;
        delete pLabel;

        qDebug() << "dob: quit with errors";
    }
    else
    {
        saveConfiguration ();
        qDebug() << "dob: quit without problems";
    }
}/*}}}*/
void dob::init() /*{{{*/
{

    m_timer = new QTimer(this);
    connect ( m_timer, SIGNAL ( timeout () ), this, SLOT ( updateInfo () ) );
    m_timer->start(120000);
    
    QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(this);
    layout->setOrientation(Qt::Horizontal);
    
    pLabel = new Plasma::Label(this);
    pLabel->setStyleSheet( QString ( "font: 12px Arial;" ) );
    updateBtn = new Plasma::ToolButton(this);
    
    updateBtn->setIcon(m_icon);
    updateBtn->widget()->setDisabled(true);
    connect ( updateBtn, SIGNAL ( clicked() ), this, SLOT ( updateInfo() ) );

    layout->addItem(pLabel);
    layout->addItem(updateBtn);
    //layout->setAlignment(pLabel, Qt::AlignLeft); 
    //layout->setAlignment(updateBtn, Qt::AlignRight); 

    hp = new DobHtmlParser();
    wm = new WebManager ();
    connect ( wm, SIGNAL ( page_ready () ), this, SLOT ( draw_result () ) );
    connect ( wm, SIGNAL ( cant_login () ), this, SLOT ( draw_cant_login () ) );

    if ( !loadConfiguration() )
    {
        updateConfiguration ();
        wm->init();
    }
}/*}}}*/
void dob::draw_result ()/*{{{*/
{
    QString a = wm->get_page();
    hp->setDoc(&a);
    m_status_message = "";
    QStringList qsl = hp->parse();
    for ( int i = 0; i < qsl.size(); i++)
       m_status_message += qsl.at(i) + " "; 
    pLabel->setText( m_status_message );
    updateBtn->widget()->setDisabled(false);
    update();
}/*}}}*/
void dob::updateInfo ()/*{{{*/
{
    if ( updateBtn )
        updateBtn->widget()->setDisabled(true);
    if ( wm )
        wm->load_info (); 
}/*}}}*/
void dob::draw_cant_login ()/*{{{*/
{
    m_status_message = "Can't login, please check configuration.";
    pLabel->setText( m_status_message );
    update();
}/*}}}*/
void dob::applyConfig ( bool reload ) /*{{{*/
{
    setConfigurationRequired (  m_options.post_data == "_ca=login&remember=0&username=JhonSilver&password=" ||
                                m_options.post_data == "" ||  
                                m_options.login_url == "" ||  
                                m_options.info_url == "" ||  
                                m_options.data_xpath == "" ||  
                                m_options.is_login_regexp == "" ||  
                                m_options.fontstylesheet == "" );
   //qDebug() << "configurationRequired:" << configurationRequired(); 
    if ( configurationRequired () )
        return;
    updateConfiguration ();
    updateInfo ();
}/*}}}*/
bool dob::loadConfiguration () /*{{{*/
{
    KConfigGroup cfg = config();
    m_options.post_data = cfg.readEntry ( "post_data" , QString ( "_ca=login&remember=0&username=JhonSilver&password=gold" ) );
    m_options.fontstylesheet = cfg.readEntry ( "fontstylesheet" , QString ( "font: 12px Arial; color: #555555;" ) );
    m_options.info_url = cfg.readEntry ( "info_url" , QString ( "https://support.example.ru/staff/index.php?_m=tickets&_a=manage" ) );
    m_options.login_url = cfg.readEntry ( "login_url" , QString ( "https://support.example.ru/staff/index.php" ) );
    m_options.logout_url = cfg.readEntry ( "logout_url" , QString ( "https://support.example.ru/staff/index.php?_ca=logout" ) );
    m_options.data_xpath = cfg.readEntry ( "data_xpath" , QString ( "//tr[@id][1]/td[@width=130][1] | //tr[@id][1]/td[@width=100]/span" ) );
    m_options.is_login_regexp = cfg.readEntry ( "is_login_regexp" , QString ( ".*swiftmabutton.*" ) );
    m_options.cookies = cfg.readEntry ( "cookies" , QString ( "" ) );

    m_options.time_out = cfg.readEntry ( "time_out" , 60 );

    applyConfig ();
    return configurationRequired ();
}/*}}}*/
void dob::createConfigurationInterface ( KConfigDialog *parent ) /*{{{*/
{
    if ( m_configDialog )
        delete m_configDialog;
    m_configDialog = new Config ( parent );
    m_configDialog->fillFromOptions ( m_options );
    connect ( parent, SIGNAL ( okClicked() ), this, SLOT ( dialogConfigAccepted () ) );
    connect ( parent, SIGNAL ( okClicked() ), this, SLOT ( updateInfo () ) );
    connect ( parent, SIGNAL ( applyClicked() ), this, SLOT ( dialogConfigAccepted () ) );
}/*}}}*/
void dob::dialogConfigAccepted () /*{{{*/
{
    m_configDialog->fillOptions ( m_options );
    applyConfig ();

    saveConfiguration ();
    delete m_configDialog;
    m_configDialog = 0;
}/*}}}*/
void dob::saveConfiguration () /*{{{*/
{
    KConfigGroup cfg = config ();
    cfg.writeEntry ( "post_data", m_options.post_data );
    cfg.writeEntry ( "fontstylesheet", m_options.fontstylesheet );
    cfg.writeEntry ( "info_url", m_options.info_url );
    cfg.writeEntry ( "login_url", m_options.login_url );
    cfg.writeEntry ( "logout_url", m_options.logout_url );
    cfg.writeEntry ( "is_login_regexp", m_options.is_login_regexp );
    cfg.writeEntry ( "data_xpath", m_options.data_xpath );
    cfg.writeEntry ( "cookies", m_options.cookies );

    cfg.writeEntry ( "time_out", ( int ) m_options.time_out );

    cfg.sync ();
}/*}}}*/
void dob::updateConfiguration ()/*{{{*/
{
    wm->setOptions ( &m_options );
    hp->setXpath ( &m_options.data_xpath );
    pLabel->setStyleSheet( m_options.fontstylesheet );
    m_timer->setInterval( m_options.time_out*1000 );
}/*}}}*/

#include "dob.moc"
