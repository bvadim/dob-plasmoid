#ifndef DOBHTMLPARSER_H
#define DOBHTMLPARSER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QByteArray>

#include <QDebug>

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/HTMLparser.h>
#include <libxml/HTMLtree.h>
#include <libxml/xpath.h>

class DobHtmlParser// : public QObject
{
    // Have a vtable linker error if make this class inheritance from QObject
    //Q_OBJECT

    public:
        DobHtmlParser ();
        DobHtmlParser ( QString *document, QString *data_xpath );
        virtual ~DobHtmlParser ();

        void setDoc ( QString *document );
        void setXpath ( QString *data_xpath );

        QStringList parse ();

    private:
        QStringList list;

        htmlDocPtr doc;
        xmlChar *xpath;

        void getlastpost ();
        xmlXPathObjectPtr getnodeset ();
};

#endif
