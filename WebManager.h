#ifndef _H_WEB_MANAGER
#define _H_WEB_MANAGER

#include <options.h>

#include <QObject>
#include <QRegExp>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QDebug>

//class dob;

class WebManager : public QObject
{
    Q_OBJECT

    public:
        WebManager ();
        ~WebManager ();

        void login ();
        QString get_page ();

    public slots:
        void replyReady ( QNetworkReply *r );
        void load_info ();
        void setOptions ( Options *options );
        void init ();

    signals:
        void page_ready ();
        void cant_login ();

    private:
        void GET ( QString *url );
        void POST ( QString *url, QString *data );

        QNetworkAccessManager *m_network_manager;
        QNetworkRequest *m_request;

        QString m_page;
        Options *m_options;

        bool is_login ();
        bool isNeedLogin (QNetworkReply *r = NULL);

        int try_counter;

};

#endif
