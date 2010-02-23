
#include "WebManager.h"

WebManager::WebManager () /*{{{*/
{
    m_options = NULL;
    m_page = QString("");
    try_counter = 0;
	m_network_manager = new QNetworkAccessManager ( this );
	m_request = new QNetworkRequest ();

	m_request->setRawHeader ( "User-Agent","Dob's WebManager v1.5" );
	m_request->setRawHeader ( "Accept-Charset","utf-8" );

    connect ( m_network_manager,
            SIGNAL ( finished ( QNetworkReply * ) ),
            this,
            SLOT ( replyReady ( QNetworkReply * ) )
            );
    
}/*}}}*/
void WebManager::init ()/*{{{*/
{
    if ( !m_options )
        return;
    if ( isNeedLogin() )
        login (); 
    else
    {
        m_request->setRawHeader ( "Cookie", m_options->cookies.toLatin1() );
        load_info ();
    } 
}/*}}}*/
void WebManager::setOptions ( Options *options )/*{{{*/
{
	m_options = options;

}/*}}}*/
void WebManager::login () /*{{{*/
{
	POST ( &m_options->login_url, &m_options->post_data );
}/*}}}*/
void WebManager::load_info () /*{{{*/
{
	GET ( &m_options->info_url );
}/*}}}*/
void WebManager::GET ( QString *url ) /*{{{*/
{
	m_request->setUrl ( *url );
	m_network_manager->get ( *m_request );

}/*}}}*/
void WebManager::POST ( QString *url, QString *data ) /*{{{*/
{
	m_request->setUrl ( *url );
	m_network_manager->post ( *m_request, data->toAscii() );
}/*}}}*/
QString WebManager::get_page () /*{{{*/
{
    return m_page;
}/*}}}*/
void WebManager::replyReady ( QNetworkReply *r )/*{{{*/
{
    //qDebug() << "our:" << m_options->cookies;
    //qDebug() << "r:" << r->rawHeader( "Set-Cookie" );

    if ( r->hasRawHeader ( "Set-Cookie" ) )
    {
        m_options->cookies = r->rawHeader ( "Set-Cookie" );
        m_request->setRawHeader ( "Cookie", m_options->cookies.toAscii() );
    }else{
        QRegExp re ( ".*sessionid20.*" ); 
        if ( ! re.exactMatch ( m_options->cookies ) ){
            login ();
            r->deleteLater ();
            return;
        }
    }

    if ( isNeedLogin ( r ) ) 
    {
        login ();   
        r->deleteLater ();
        return;
    }

    m_page = r->readAll ();

    //qDebug() << "page" << m_page;

    if ( ! is_login () ){
        if ( try_counter >= 3 )
        {
            emit cant_login ();
            try_counter = 0;
        }
        else{
            load_info ();
            try_counter++;
        }
    }
    else
        emit page_ready ();

    r->deleteLater ();
}/*}}}*/
bool WebManager::isNeedLogin ( QNetworkReply *r )/*{{{*/
{
    if ( m_options->cookies == "" ) 
        return true;

    QRegExp re ( ".*sessionid20=deleted.*" );
    if ( re.exactMatch ( m_options->cookies ) )
        return true;

    if ( r != NULL)
    {
        if ( re.exactMatch ( r->rawHeader ( "Set-Cookie" ) ) )
            return true;
    }

    return false;
}/*}}}*/
bool WebManager::is_login () /*{{{*/
{
    QRegExp re ( m_options->is_login_regexp );
    return re.exactMatch ( m_page );
}/*}}}*/
WebManager::~WebManager ()/*{{{*/
{
	delete m_network_manager;
	delete m_request;
}/*}}}*/
