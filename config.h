#ifndef __CONFIG__H__
#define __CONFIG__H__

#include <QObject>
#include <Plasma/Applet>
#include "ui_settings.h"
#include "options.h"

class KConfigDialog;

class Config : public QObject
{
	Q_OBJECT
	public:
		Config ( KConfigDialog * );
		~Config ();
		
		// Settings
		/*
		QString user_name () const {return m_settings.user_name->text(); }
		QString user_password () const {return m_settings.user_password->text(); }
		QString info_url () const {return m_settings.info_url->text(); }
		QString login_url () const {return m_settings.login_url->text(); }
		QString logout_url () const {return m_settings.logout_url->text(); }
		QString data_xpath () const {return m_settings.date_xpath->text(); }
		QString is_login_regexp () const {return m_settings.is_login_regexp->text(); }
		int time_out () const {return m_settings.time_out->value(); }
		*/
		
		void fillOptions ( Options & ) const;
		void fillFromOptions ( const Options & );
	
	private slots:
		void updateUI ();
	
	private:
		Ui::Settings m_settings;
		KConfigDialog *m_parent;
};

#endif
