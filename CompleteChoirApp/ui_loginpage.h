/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogInPage
{
public:
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_start_leader;
    QLabel *lbl_choir_leader;
    QPushButton *btn_start_leader;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_start_member;
    QLabel *lbl_choir_member;
    QLineEdit *ip_address_member_login;
    QPushButton *btn_start_member;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *LogInPage)
    {
        if (LogInPage->objectName().isEmpty())
            LogInPage->setObjectName(QString::fromUtf8("LogInPage"));
        LogInPage->resize(773, 559);
        horizontalLayout_4 = new QHBoxLayout(LogInPage);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lbl_start_leader = new QLabel(LogInPage);
        lbl_start_leader->setObjectName(QString::fromUtf8("lbl_start_leader"));
        lbl_start_leader->setStyleSheet(QString::fromUtf8("font-size: 35px;\n"
"font-family: \"Comic Sans MS\";\n"
"font: bold;"));

        verticalLayout_2->addWidget(lbl_start_leader);

        lbl_choir_leader = new QLabel(LogInPage);
        lbl_choir_leader->setObjectName(QString::fromUtf8("lbl_choir_leader"));
        lbl_choir_leader->setStyleSheet(QString::fromUtf8("font-size: 15px;\n"
"font-family: \"Comic Sans MS\";\n"
"font: bold;\n"
"color: purple"));

        verticalLayout_2->addWidget(lbl_choir_leader);

        btn_start_leader = new QPushButton(LogInPage);
        btn_start_leader->setObjectName(QString::fromUtf8("btn_start_leader"));
        btn_start_leader->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"font-family: \"Comic Sans MS\";\n"
"font: bold;\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 1px;\n"
"background-color: rgb(85, 0, 255);\n"
"/*For getting optimal results i will add an Image as background fot the button*/"));

        verticalLayout_2->addWidget(btn_start_leader);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 308, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_3);

        line = new QFrame(LogInPage);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbl_start_member = new QLabel(LogInPage);
        lbl_start_member->setObjectName(QString::fromUtf8("lbl_start_member"));
        lbl_start_member->setStyleSheet(QString::fromUtf8("font-size: 35px;\n"
"font-family: \"Comic Sans MS\";\n"
"font: bold;"));

        verticalLayout->addWidget(lbl_start_member);

        lbl_choir_member = new QLabel(LogInPage);
        lbl_choir_member->setObjectName(QString::fromUtf8("lbl_choir_member"));
        lbl_choir_member->setStyleSheet(QString::fromUtf8("font-size: 15px;\n"
"font-family: \"Comic Sans MS\";\n"
"font: bold;\n"
"color: purple"));

        verticalLayout->addWidget(lbl_choir_member);

        ip_address_member_login = new QLineEdit(LogInPage);
        ip_address_member_login->setObjectName(QString::fromUtf8("ip_address_member_login"));

        verticalLayout->addWidget(ip_address_member_login);

        btn_start_member = new QPushButton(LogInPage);
        btn_start_member->setObjectName(QString::fromUtf8("btn_start_member"));
        btn_start_member->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"font-family: \"Comic Sans MS\";\n"
"font: bold;\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 1px;\n"
"background-color: rgb(85, 0, 255);\n"
"/*For getting optimal results i will add an Image as background fot the button*/"));

        verticalLayout->addWidget(btn_start_member);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 278, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);


        horizontalLayout_3->addLayout(verticalLayout_4);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(LogInPage);

        QMetaObject::connectSlotsByName(LogInPage);
    } // setupUi

    void retranslateUi(QWidget *LogInPage)
    {
        LogInPage->setWindowTitle(QCoreApplication::translate("LogInPage", "Form", nullptr));
        lbl_start_leader->setText(QCoreApplication::translate("LogInPage", "1. Start", nullptr));
        lbl_choir_leader->setText(QCoreApplication::translate("LogInPage", "As Choir Leader", nullptr));
        btn_start_leader->setText(QCoreApplication::translate("LogInPage", "Start", nullptr));
        lbl_start_member->setText(QCoreApplication::translate("LogInPage", "2. Start", nullptr));
        lbl_choir_member->setText(QCoreApplication::translate("LogInPage", "As Choir Member", nullptr));
        ip_address_member_login->setPlaceholderText(QCoreApplication::translate("LogInPage", "IP address", nullptr));
        btn_start_member->setText(QCoreApplication::translate("LogInPage", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogInPage: public Ui_LogInPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
