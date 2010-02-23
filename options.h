#ifndef __OPTIONS__H__
#define __OPTIONS__H__

#include <QString>

struct Options {

	QString post_data;
	QString fontstylesheet;
	QString info_url;
	QString login_url;
	QString logout_url;
	QString data_xpath;
	QString is_login_regexp;

    QString cookies;

	int time_out;
};

#endif
