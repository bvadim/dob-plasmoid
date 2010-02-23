#include <QWidget>
#include <QButtonGroup>
#include <KConfigDialog>
#include <KDebug>
#include <KUrl>
#include <KUrlRequester>
#include <KLocale>
#include <KCharsets>
#include "config.h"
#include "options.h"

Config::Config ( KConfigDialog *par )/*{{{*/
{
	m_parent = par;

	QWidget *set = new QWidget;

	m_settings.setupUi ( set );

	par->addPage ( set, i18n ( "Settings" ), "configure" );
/*
	connect(m_settings.radioCommand, SIGNAL(toggled(bool)), this, SLOT(updateUI()));
	connect(m_settings.radioFile, SIGNAL(toggled(bool)), this, SLOT(updateUI()));
	connect(m_settings.radioFirst, SIGNAL(toggled(bool)), this, SLOT(updateUI()));
	connect(m_settings.radioLast, SIGNAL(toggled(bool)), this, SLOT(updateUI()));
	connect(m_theme.chkFixed, SIGNAL(toggled(bool)), this, SLOT(updateUI()));
*/
}/*}}}*/
Config::~Config (){}
void Config::updateUI (){}
void Config::fillOptions ( Options &o ) const/*{{{*/
{
	o.post_data = m_settings.post_data->text();
	o.fontstylesheet = m_settings.fontstylesheet->text();
	o.info_url = m_settings.info_url->text();
	o.login_url = m_settings.login_url->text();
	o.logout_url = m_settings.logout_url->text();
	o.data_xpath = m_settings.data_xpath->text();
	o.is_login_regexp = m_settings.is_login_regexp->text();
	o.time_out = m_settings.time_out->value();
/*
	o.color = color ();
	o.alignment = Qt::Alignment ( alignment () );
	o.background = Plasma::Applet::BackgroundHints ( background () );
	o.breakLines = breakLines ();
	o.isFixed = isFixed ();
	
	o.timer = timer ();
	o.skip = m_settings.intSkip->value ();
	o.lines = lines ();
	o.isCommand = isCommand ();
	o.action = action ();
	
	o.codec = m_settings.comboEncoding->currentText ();
	o.first = m_settings.radioFirst->isChecked ();
	o.reverse = m_settings.chkReverse->isChecked ();
	o.partial = m_settings.chkPartial->isChecked ();

	switch ( m_settings.comboShow->currentIndex () )
	{
		case 0: o.show = Options::StdOut; break;
		case 1: o.show = Options::StdErr; break;
		case 2: o.show = Options::StdOut | Options::StdErr; break;
		case 3: o.show = Options::StdOut | Options::StdErr | Options::Separate; break;
		default: o.show = Options::StdOut;
	}

	if ( m_settings.chkExitStatus->isChecked () )
		o.show |= Options::Status;

	o.commandHistory = m_settings.comboCommand->historyItems ();
*/
}/*}}}*/
void Config::fillFromOptions ( const Options &o )/*{{{*/
{
	m_settings.post_data->setText (o.post_data);

	m_settings.fontstylesheet->setText (o.fontstylesheet);
	
	m_settings.info_url->setText (o.info_url);
	m_settings.login_url->setText (o.login_url);
	m_settings.logout_url->setText (o.logout_url);
	
	m_settings.data_xpath->setText (o.data_xpath);
	m_settings.is_login_regexp->setText (o.is_login_regexp);
	
	m_settings.time_out->setValue (o.time_out);
/*	
	m_settings.intTimer->setValue ( o.timer );
	m_settings.intSkip->setValue ( o.skip );
	m_settings.intLines->setValue ( o.lines );
	
	updateUI (); // Just in case...
*/
}/*}}}*/
