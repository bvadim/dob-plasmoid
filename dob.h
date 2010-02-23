// Here we avoid loading the header multiple times
#ifndef DOB_HEADER
#define DOB_HEADER

//#include <KLocale>
#include <QTimer>

#include <QFont>
#include <QString>
#include <QPainter>
#include <KConfigDialog>
#include <QNetworkAccessManager>
#include <QGraphicsLinearLayout>

#include <QDebug>

#include "config.h"
#include "options.h"
#include "WebManager.h"
#include "DobHtmlParser.h"

#include <KIcon>
#include <Plasma/Applet>
//#include <Plasma/Svg>

namespace Plasma {
    class ToolButton;
    class Label;
}

class dob : public Plasma::Applet
{
    Q_OBJECT
    public:
        dob ( QObject *parent, const QVariantList &args );
        ~dob();

        void init();
        void createConfigurationInterface ( KConfigDialog *parent );
        //void paintInterface ( QPainter *painter,
                //const QStyleOptionGraphicsItem *option,
                //const QRect& contentsRect );

    public slots:
        void dialogConfigAccepted ();
        void draw_result ();
        void draw_cant_login ();
        void updateInfo ();

    private:
        QTimer *m_timer;
        Config *m_configDialog;
        WebManager *wm;
        DobHtmlParser *hp;
        QString m_status_message;
        Options m_options;

        bool loadConfiguration ();
        void applyConfig ( bool reload = true );
        void saveConfiguration ();
        void initialize ();
        void updateConfiguration ();

        Plasma::ToolButton *updateBtn;
        Plasma::Label *pLabel;
        KIcon m_icon;
};


// This is the command that links your applet to the .desktop file
K_EXPORT_PLASMA_APPLET ( dob, dob )

#endif
