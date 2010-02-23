#include "DobHtmlParser.h"


DobHtmlParser::DobHtmlParser () {
    doc = NULL;
}
DobHtmlParser::DobHtmlParser (QString *document, QString *data_xpath )/*{{{*/
{
    doc = NULL;
    setDoc ( document );
    setXpath ( data_xpath );
}/*}}}*/
DobHtmlParser::~DobHtmlParser ()/*{{{*/
{
    if ( doc )
        xmlFreeDoc( doc );
    if ( xpath )
        xmlFree(xpath);
    xmlCleanupParser ();
}/*}}}*/
void DobHtmlParser::setDoc ( QString *document )/*{{{*/
{
    if ( doc )
        xmlFreeDoc ( doc );
    doc = htmlReadMemory ( document->toLatin1(), document->size(), "noname.html", NULL, 0 ); 
}/*}}}*/
void DobHtmlParser::setXpath ( QString *data_xpath )/*{{{*/
{
    QByteArray a = data_xpath->toLatin1();
    xpath = xmlCharStrdup ( a.data() );
}/*}}}*/
QStringList DobHtmlParser::parse ()/*{{{*/
{
    getlastpost ();
    //qDebug() << list;
    return list; 
}/*}}}*/
void DobHtmlParser::getlastpost ()/*{{{*/
{
    int i;

	xmlNodeSetPtr nodeset;
	xmlXPathObjectPtr result;
	xmlChar *keyword;

    list.clear();

	result = getnodeset ();	

	if ( result ){
		nodeset = result->nodesetval;
		for ( i = 0; i < nodeset->nodeNr; i++ )
        {
			keyword = xmlNodeListGetString ( doc, nodeset->nodeTab[i]->xmlChildrenNode, 1 );
			if ( keyword )
                list << QString::fromUtf8( ( char *) keyword );
			xmlFree ( keyword );
		}
		xmlXPathFreeObject ( result );
	}
}/*}}}*/
xmlXPathObjectPtr DobHtmlParser::getnodeset()/*{{{*/
{
	xmlXPathContextPtr context;
	xmlXPathObjectPtr result;

	context = xmlXPathNewContext ( doc );
	if ( context == NULL ){
		qDebug() << "Error in xmlXPathNewContext";
		return NULL;
	}
	result = xmlXPathEvalExpression ( xpath, context );
	xmlXPathFreeContext ( context );
	if ( result == NULL ){
		qDebug() << "Error in xmlXPathEvalExpression";
		return NULL;
	}
	if ( xmlXPathNodeSetIsEmpty ( result->nodesetval ) ){
		xmlXPathFreeObject ( result );
		qDebug() << "No result";
		return NULL;
	}
	return result;
}/*}}}*/
