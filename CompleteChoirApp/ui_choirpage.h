/********************************************************************************
** Form generated from reading UI file 'choirpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOIRPAGE_H
#define UI_CHOIRPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChoirPage
{
public:
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_leader;
    QHBoxLayout *horizontalLayout_17;
    QLabel *lbl_choir_leader;
    QGroupBox *groupBox_session;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_session_leader;
    QLineEdit *txt_leader_name;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_choir_volume;
    QLabel *img_session_volume;
    QSlider *horizontalSlider_session;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_members;
    QLabel *lbl_num_members;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_sopranos;
    QVBoxLayout *verticalLayout;
    QListView *listView_sopranos;
    QGroupBox *groupBox_altos;
    QVBoxLayout *verticalLayout_2;
    QListView *listView_altos;
    QGroupBox *groupBox_tenors;
    QVBoxLayout *verticalLayout_3;
    QListView *listView_tenors;
    QGroupBox *groupBox_basses;
    QVBoxLayout *verticalLayout_4;
    QListView *listView_basses;
    QHBoxLayout *horizontalLayout_16;
    QGroupBox *groupBox_you;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbl_name;
    QLineEdit *txt_username;
    QHBoxLayout *horizontalLayout_15;
    QLabel *lbl_section;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *comboBox_section;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox_microphone;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_14;
    QLabel *img_microphone;
    QHBoxLayout *horizontalLayout_10;
    QComboBox *comboBox_audio_inputs;
    QSpacerItem *horizontalSpacer_5;
    QProgressBar *progressBar_microphone;
    QHBoxLayout *horizontalLayout_9;
    QLabel *img_microphone_volume;
    QSlider *horizontalSlider_microphone;
    QGroupBox *groupBox_headphones;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_13;
    QLabel *img_headphones;
    QHBoxLayout *horizontalLayout_11;
    QComboBox *comboBox_audio_output;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *img_headphones_volume;
    QSlider *horizontalSlider_headphones;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *ChoirPage)
    {
        if (ChoirPage->objectName().isEmpty())
            ChoirPage->setObjectName(QString::fromUtf8("ChoirPage"));
        ChoirPage->resize(907, 607);
        ChoirPage->setStyleSheet(QString::fromUtf8("font-family: \"Comic Sans MS\";"));
        verticalLayout_8 = new QVBoxLayout(ChoirPage);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        groupBox_leader = new QGroupBox(ChoirPage);
        groupBox_leader->setObjectName(QString::fromUtf8("groupBox_leader"));
        horizontalLayout_17 = new QHBoxLayout(groupBox_leader);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        lbl_choir_leader = new QLabel(groupBox_leader);
        lbl_choir_leader->setObjectName(QString::fromUtf8("lbl_choir_leader"));

        horizontalLayout_17->addWidget(lbl_choir_leader);


        horizontalLayout_5->addWidget(groupBox_leader);

        groupBox_session = new QGroupBox(ChoirPage);
        groupBox_session->setObjectName(QString::fromUtf8("groupBox_session"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_session);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lbl_session_leader = new QLabel(groupBox_session);
        lbl_session_leader->setObjectName(QString::fromUtf8("lbl_session_leader"));

        horizontalLayout->addWidget(lbl_session_leader);

        txt_leader_name = new QLineEdit(groupBox_session);
        txt_leader_name->setObjectName(QString::fromUtf8("txt_leader_name"));

        horizontalLayout->addWidget(txt_leader_name);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(48, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lbl_choir_volume = new QLabel(groupBox_session);
        lbl_choir_volume->setObjectName(QString::fromUtf8("lbl_choir_volume"));

        horizontalLayout_2->addWidget(lbl_choir_volume);

        img_session_volume = new QLabel(groupBox_session);
        img_session_volume->setObjectName(QString::fromUtf8("img_session_volume"));

        horizontalLayout_2->addWidget(img_session_volume);

        horizontalSlider_session = new QSlider(groupBox_session);
        horizontalSlider_session->setObjectName(QString::fromUtf8("horizontalSlider_session"));
        horizontalSlider_session->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0px;\n"
"	background-color: rgb(48, 48, 48);\n"
"    height: 2px;\n"
"    margin: 0px;\n"
"    }\n"
"QSlider::handle:horizontal { \n"
"	image: url(:/Images/Images/handle.png);\n"
"	border: 0px;\n"
"    height: 20px;\n"
"    width: 20px;\n"
"    margin: -15px 0px;\n"
"}"));
        horizontalSlider_session->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_session);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lbl_members = new QLabel(groupBox_session);
        lbl_members->setObjectName(QString::fromUtf8("lbl_members"));

        horizontalLayout_3->addWidget(lbl_members);

        lbl_num_members = new QLabel(groupBox_session);
        lbl_num_members->setObjectName(QString::fromUtf8("lbl_num_members"));

        horizontalLayout_3->addWidget(lbl_num_members);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_5->addWidget(groupBox_session);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        horizontalSpacer_9 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);


        verticalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        groupBox_sopranos = new QGroupBox(ChoirPage);
        groupBox_sopranos->setObjectName(QString::fromUtf8("groupBox_sopranos"));
        verticalLayout = new QVBoxLayout(groupBox_sopranos);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listView_sopranos = new QListView(groupBox_sopranos);
        listView_sopranos->setObjectName(QString::fromUtf8("listView_sopranos"));
        listView_sopranos->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(listView_sopranos);


        horizontalLayout_6->addWidget(groupBox_sopranos);

        groupBox_altos = new QGroupBox(ChoirPage);
        groupBox_altos->setObjectName(QString::fromUtf8("groupBox_altos"));
        verticalLayout_2 = new QVBoxLayout(groupBox_altos);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listView_altos = new QListView(groupBox_altos);
        listView_altos->setObjectName(QString::fromUtf8("listView_altos"));
        listView_altos->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(listView_altos);


        horizontalLayout_6->addWidget(groupBox_altos);

        groupBox_tenors = new QGroupBox(ChoirPage);
        groupBox_tenors->setObjectName(QString::fromUtf8("groupBox_tenors"));
        verticalLayout_3 = new QVBoxLayout(groupBox_tenors);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        listView_tenors = new QListView(groupBox_tenors);
        listView_tenors->setObjectName(QString::fromUtf8("listView_tenors"));
        listView_tenors->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(listView_tenors);


        horizontalLayout_6->addWidget(groupBox_tenors);

        groupBox_basses = new QGroupBox(ChoirPage);
        groupBox_basses->setObjectName(QString::fromUtf8("groupBox_basses"));
        verticalLayout_4 = new QVBoxLayout(groupBox_basses);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        listView_basses = new QListView(groupBox_basses);
        listView_basses->setObjectName(QString::fromUtf8("listView_basses"));
        listView_basses->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(listView_basses);


        horizontalLayout_6->addWidget(groupBox_basses);


        verticalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        groupBox_you = new QGroupBox(ChoirPage);
        groupBox_you->setObjectName(QString::fromUtf8("groupBox_you"));
        verticalLayout_5 = new QVBoxLayout(groupBox_you);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lbl_name = new QLabel(groupBox_you);
        lbl_name->setObjectName(QString::fromUtf8("lbl_name"));

        horizontalLayout_7->addWidget(lbl_name);

        txt_username = new QLineEdit(groupBox_you);
        txt_username->setObjectName(QString::fromUtf8("txt_username"));

        horizontalLayout_7->addWidget(txt_username);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        lbl_section = new QLabel(groupBox_you);
        lbl_section->setObjectName(QString::fromUtf8("lbl_section"));

        horizontalLayout_15->addWidget(lbl_section);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        comboBox_section = new QComboBox(groupBox_you);
        comboBox_section->setObjectName(QString::fromUtf8("comboBox_section"));

        horizontalLayout_8->addWidget(comboBox_section);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        horizontalLayout_15->addLayout(horizontalLayout_8);


        verticalLayout_5->addLayout(horizontalLayout_15);


        horizontalLayout_16->addWidget(groupBox_you);

        groupBox_microphone = new QGroupBox(ChoirPage);
        groupBox_microphone->setObjectName(QString::fromUtf8("groupBox_microphone"));
        verticalLayout_6 = new QVBoxLayout(groupBox_microphone);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        img_microphone = new QLabel(groupBox_microphone);
        img_microphone->setObjectName(QString::fromUtf8("img_microphone"));

        horizontalLayout_14->addWidget(img_microphone);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        comboBox_audio_inputs = new QComboBox(groupBox_microphone);
        comboBox_audio_inputs->setObjectName(QString::fromUtf8("comboBox_audio_inputs"));

        horizontalLayout_10->addWidget(comboBox_audio_inputs);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);


        horizontalLayout_14->addLayout(horizontalLayout_10);


        verticalLayout_6->addLayout(horizontalLayout_14);

        progressBar_microphone = new QProgressBar(groupBox_microphone);
        progressBar_microphone->setObjectName(QString::fromUtf8("progressBar_microphone"));
        progressBar_microphone->setStyleSheet(QString::fromUtf8("border: 0px ;\n"
"background-color: rgb(70, 215, 0);"));
        progressBar_microphone->setValue(24);
        progressBar_microphone->setTextVisible(false);

        verticalLayout_6->addWidget(progressBar_microphone);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        img_microphone_volume = new QLabel(groupBox_microphone);
        img_microphone_volume->setObjectName(QString::fromUtf8("img_microphone_volume"));

        horizontalLayout_9->addWidget(img_microphone_volume);

        horizontalSlider_microphone = new QSlider(groupBox_microphone);
        horizontalSlider_microphone->setObjectName(QString::fromUtf8("horizontalSlider_microphone"));
        horizontalSlider_microphone->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0px;\n"
"	background-color: rgb(48, 48, 48);\n"
"    height: 2px;\n"
"    margin: 0px;\n"
"    }\n"
"QSlider::handle:horizontal { \n"
"	image: url(:/Images/Images/handle.png);\n"
"	border: 0px;\n"
"    height: 20px;\n"
"    width: 20px;\n"
"    margin: -15px 0px;\n"
"}"));
        horizontalSlider_microphone->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(horizontalSlider_microphone);


        verticalLayout_6->addLayout(horizontalLayout_9);


        horizontalLayout_16->addWidget(groupBox_microphone);

        groupBox_headphones = new QGroupBox(ChoirPage);
        groupBox_headphones->setObjectName(QString::fromUtf8("groupBox_headphones"));
        verticalLayout_7 = new QVBoxLayout(groupBox_headphones);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        img_headphones = new QLabel(groupBox_headphones);
        img_headphones->setObjectName(QString::fromUtf8("img_headphones"));

        horizontalLayout_13->addWidget(img_headphones);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        comboBox_audio_output = new QComboBox(groupBox_headphones);
        comboBox_audio_output->setObjectName(QString::fromUtf8("comboBox_audio_output"));

        horizontalLayout_11->addWidget(comboBox_audio_output);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_4);


        horizontalLayout_13->addLayout(horizontalLayout_11);


        verticalLayout_7->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        img_headphones_volume = new QLabel(groupBox_headphones);
        img_headphones_volume->setObjectName(QString::fromUtf8("img_headphones_volume"));

        horizontalLayout_12->addWidget(img_headphones_volume);

        horizontalSlider_headphones = new QSlider(groupBox_headphones);
        horizontalSlider_headphones->setObjectName(QString::fromUtf8("horizontalSlider_headphones"));
        horizontalSlider_headphones->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0px;\n"
"	background-color: rgb(48, 48, 48);\n"
"    height: 2px;\n"
"    margin: 0px;\n"
"    }\n"
"QSlider::handle:horizontal { \n"
"	image: url(:/Images/Images/handle.png);\n"
"	border: 0px;\n"
"    height: 20px;\n"
"    width: 20px;\n"
"    margin: -15px 0px;\n"
"}"));
        horizontalSlider_headphones->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(horizontalSlider_headphones);


        verticalLayout_7->addLayout(horizontalLayout_12);


        horizontalLayout_16->addWidget(groupBox_headphones);

        horizontalSpacer_3 = new QSpacerItem(248, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_3);


        verticalLayout_8->addLayout(horizontalLayout_16);


        retranslateUi(ChoirPage);

        QMetaObject::connectSlotsByName(ChoirPage);
    } // setupUi

    void retranslateUi(QWidget *ChoirPage)
    {
        ChoirPage->setWindowTitle(QCoreApplication::translate("ChoirPage", "Form", nullptr));
        groupBox_leader->setTitle(QCoreApplication::translate("ChoirPage", "Leader", nullptr));
        lbl_choir_leader->setText(QCoreApplication::translate("ChoirPage", "leaderName", nullptr));
        groupBox_session->setTitle(QCoreApplication::translate("ChoirPage", "Session", nullptr));
        lbl_session_leader->setText(QCoreApplication::translate("ChoirPage", "Leader:", nullptr));
        lbl_choir_volume->setText(QCoreApplication::translate("ChoirPage", "Choir volume:", nullptr));
        img_session_volume->setText(QCoreApplication::translate("ChoirPage", "volImg", nullptr));
        lbl_members->setText(QCoreApplication::translate("ChoirPage", "Members:", nullptr));
        lbl_num_members->setText(QCoreApplication::translate("ChoirPage", "Num", nullptr));
        groupBox_sopranos->setTitle(QCoreApplication::translate("ChoirPage", "Sopranos", nullptr));
        groupBox_altos->setTitle(QCoreApplication::translate("ChoirPage", "Altos", nullptr));
        groupBox_tenors->setTitle(QCoreApplication::translate("ChoirPage", "Tenors", nullptr));
        groupBox_basses->setTitle(QCoreApplication::translate("ChoirPage", "Basses", nullptr));
        groupBox_you->setTitle(QCoreApplication::translate("ChoirPage", "You", nullptr));
        lbl_name->setText(QCoreApplication::translate("ChoirPage", "Name:", nullptr));
        lbl_section->setText(QCoreApplication::translate("ChoirPage", "Section:", nullptr));
        groupBox_microphone->setTitle(QCoreApplication::translate("ChoirPage", "Microphone", nullptr));
        img_microphone->setText(QCoreApplication::translate("ChoirPage", "micImg", nullptr));
        img_microphone_volume->setText(QCoreApplication::translate("ChoirPage", "speakImg", nullptr));
        groupBox_headphones->setTitle(QCoreApplication::translate("ChoirPage", "Headphones", nullptr));
        img_headphones->setText(QCoreApplication::translate("ChoirPage", "setImg", nullptr));
        img_headphones_volume->setText(QCoreApplication::translate("ChoirPage", "speakImg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChoirPage: public Ui_ChoirPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOIRPAGE_H
