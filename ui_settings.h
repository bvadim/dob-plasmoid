/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Mon Feb 22 20:11:14 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_01;
    QLabel *user_name_label;
    QLineEdit *post_data;
    QHBoxLayout *horizontalLayout_02;
    QLabel *fontstylesheet_label;
    QLineEdit *fontstylesheet;
    QHBoxLayout *horizontalLayout_03;
    QLabel *info_url_label;
    QLineEdit *info_url;
    QHBoxLayout *horizontalLayout_04;
    QLabel *login_url_label;
    QLineEdit *login_url;
    QHBoxLayout *horizontalLayout_05;
    QLabel *logout_url_label;
    QLineEdit *logout_url;
    QHBoxLayout *horizontalLayout_06;
    QLabel *data_xpath_label;
    QLineEdit *data_xpath;
    QHBoxLayout *horizontalLayout_07;
    QLabel *is_login_regexp_label;
    QLineEdit *is_login_regexp;
    QHBoxLayout *horizontalLayout_08;
    QLabel *time_out_label;
    QSpinBox *time_out;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->setMinimumSize(QSize(525, 0));
        verticalLayout = new QVBoxLayout(Settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_01 = new QHBoxLayout();
        horizontalLayout_01->setObjectName(QString::fromUtf8("horizontalLayout_01"));
        user_name_label = new QLabel(Settings);
        user_name_label->setObjectName(QString::fromUtf8("user_name_label"));

        horizontalLayout_01->addWidget(user_name_label);

        post_data = new QLineEdit(Settings);
        post_data->setObjectName(QString::fromUtf8("post_data"));

        horizontalLayout_01->addWidget(post_data);


        verticalLayout->addLayout(horizontalLayout_01);

        horizontalLayout_02 = new QHBoxLayout();
        horizontalLayout_02->setObjectName(QString::fromUtf8("horizontalLayout_02"));
        fontstylesheet_label = new QLabel(Settings);
        fontstylesheet_label->setObjectName(QString::fromUtf8("fontstylesheet_label"));

        horizontalLayout_02->addWidget(fontstylesheet_label);

        fontstylesheet = new QLineEdit(Settings);
        fontstylesheet->setObjectName(QString::fromUtf8("fontstylesheet"));

        horizontalLayout_02->addWidget(fontstylesheet);


        verticalLayout->addLayout(horizontalLayout_02);

        horizontalLayout_03 = new QHBoxLayout();
        horizontalLayout_03->setObjectName(QString::fromUtf8("horizontalLayout_03"));
        info_url_label = new QLabel(Settings);
        info_url_label->setObjectName(QString::fromUtf8("info_url_label"));

        horizontalLayout_03->addWidget(info_url_label);

        info_url = new QLineEdit(Settings);
        info_url->setObjectName(QString::fromUtf8("info_url"));

        horizontalLayout_03->addWidget(info_url);


        verticalLayout->addLayout(horizontalLayout_03);

        horizontalLayout_04 = new QHBoxLayout();
        horizontalLayout_04->setObjectName(QString::fromUtf8("horizontalLayout_04"));
        login_url_label = new QLabel(Settings);
        login_url_label->setObjectName(QString::fromUtf8("login_url_label"));

        horizontalLayout_04->addWidget(login_url_label);

        login_url = new QLineEdit(Settings);
        login_url->setObjectName(QString::fromUtf8("login_url"));

        horizontalLayout_04->addWidget(login_url);


        verticalLayout->addLayout(horizontalLayout_04);

        horizontalLayout_05 = new QHBoxLayout();
        horizontalLayout_05->setObjectName(QString::fromUtf8("horizontalLayout_05"));
        logout_url_label = new QLabel(Settings);
        logout_url_label->setObjectName(QString::fromUtf8("logout_url_label"));

        horizontalLayout_05->addWidget(logout_url_label);

        logout_url = new QLineEdit(Settings);
        logout_url->setObjectName(QString::fromUtf8("logout_url"));

        horizontalLayout_05->addWidget(logout_url);


        verticalLayout->addLayout(horizontalLayout_05);

        horizontalLayout_06 = new QHBoxLayout();
        horizontalLayout_06->setObjectName(QString::fromUtf8("horizontalLayout_06"));
        data_xpath_label = new QLabel(Settings);
        data_xpath_label->setObjectName(QString::fromUtf8("data_xpath_label"));

        horizontalLayout_06->addWidget(data_xpath_label);

        data_xpath = new QLineEdit(Settings);
        data_xpath->setObjectName(QString::fromUtf8("data_xpath"));

        horizontalLayout_06->addWidget(data_xpath);


        verticalLayout->addLayout(horizontalLayout_06);

        horizontalLayout_07 = new QHBoxLayout();
        horizontalLayout_07->setObjectName(QString::fromUtf8("horizontalLayout_07"));
        is_login_regexp_label = new QLabel(Settings);
        is_login_regexp_label->setObjectName(QString::fromUtf8("is_login_regexp_label"));

        horizontalLayout_07->addWidget(is_login_regexp_label);

        is_login_regexp = new QLineEdit(Settings);
        is_login_regexp->setObjectName(QString::fromUtf8("is_login_regexp"));

        horizontalLayout_07->addWidget(is_login_regexp);


        verticalLayout->addLayout(horizontalLayout_07);

        horizontalLayout_08 = new QHBoxLayout();
        horizontalLayout_08->setObjectName(QString::fromUtf8("horizontalLayout_08"));
        time_out_label = new QLabel(Settings);
        time_out_label->setObjectName(QString::fromUtf8("time_out_label"));

        horizontalLayout_08->addWidget(time_out_label);

        time_out = new QSpinBox(Settings);
        time_out->setObjectName(QString::fromUtf8("time_out"));
        time_out->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        time_out->setMinimum(60);
        time_out->setMaximum(3600);
        time_out->setValue(60);

        horizontalLayout_08->addWidget(time_out);


        verticalLayout->addLayout(horizontalLayout_08);

        verticalSpacer = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Form", 0, QApplication::UnicodeUTF8));
        user_name_label->setText(QApplication::translate("Settings", "Post data", 0, QApplication::UnicodeUTF8));
        fontstylesheet_label->setText(QApplication::translate("Settings", "Font style", 0, QApplication::UnicodeUTF8));
        info_url_label->setText(QApplication::translate("Settings", "Info URL", 0, QApplication::UnicodeUTF8));
        login_url_label->setText(QApplication::translate("Settings", "Login URL", 0, QApplication::UnicodeUTF8));
        logout_url_label->setText(QApplication::translate("Settings", "Logout URL", 0, QApplication::UnicodeUTF8));
        data_xpath_label->setText(QApplication::translate("Settings", "Data xpath", 0, QApplication::UnicodeUTF8));
        is_login_regexp_label->setText(QApplication::translate("Settings", "'Is login?' regexp", 0, QApplication::UnicodeUTF8));
        time_out_label->setText(QApplication::translate("Settings", "Time out", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        time_out->setToolTip(QApplication::translate("Settings", "Tooltip", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        time_out->setSuffix(QApplication::translate("Settings", " Sec", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
