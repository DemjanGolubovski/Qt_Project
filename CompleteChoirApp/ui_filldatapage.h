/********************************************************************************
** Form generated from reading UI file 'filldatapage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILLDATAPAGE_H
#define UI_FILLDATAPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FillDataPage
{
public:
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_6;
    QLabel *lbl_get_ready;
    QGroupBox *groupBox_You;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_name;
    QLabel *lbl_section;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *txt_username_input;
    QComboBox *comboBox_section;
    QGroupBox *groupBox_Microphone;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *img_microphone;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_audio_inputs;
    QSpacerItem *horizontalSpacer_3;
    QProgressBar *progressBar_microphone;
    QGridLayout *gridLayout_3;
    QLabel *img_microphone_volume;
    QSlider *horizontalSlider_microphone;
    QGroupBox *groupBox_Headphones;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *img_headphones;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox_audio_outputs;
    QSpacerItem *horizontalSpacer_4;
    QProgressBar *progressBar_headphones;
    QHBoxLayout *horizontalLayout_7;
    QLabel *img_headphones_volume;
    QSlider *horizontalSlider_headphones;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_9;
    QLabel *label_10;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QFrame *line;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *btn_join_member;
    QLabel *lbl_choir_member;
    QLineEdit *ip_address_join_member;
    QLabel *lbl_join_choir;
    QLabel *img_OR;
    QGridLayout *gridLayout;
    QLabel *lbl_new_session;
    QLabel *lbl_choir_leader;
    QPushButton *btn_join_leader;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *FillDataPage)
    {
        if (FillDataPage->objectName().isEmpty())
            FillDataPage->setObjectName(QString::fromUtf8("FillDataPage"));
        FillDataPage->resize(734, 553);
        horizontalLayout_10 = new QHBoxLayout(FillDataPage);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lbl_get_ready = new QLabel(FillDataPage);
        lbl_get_ready->setObjectName(QString::fromUtf8("lbl_get_ready"));
        lbl_get_ready->setStyleSheet(QString::fromUtf8("font-size: 30px;\n"
"font-family: \"Comic Sans MS\";\n"
"font: bold;"));

        verticalLayout_6->addWidget(lbl_get_ready);

        groupBox_You = new QGroupBox(FillDataPage);
        groupBox_You->setObjectName(QString::fromUtf8("groupBox_You"));
        groupBox_You->setStyleSheet(QString::fromUtf8("font-family: \"Comic Sans MS\";"));
        horizontalLayout = new QHBoxLayout(groupBox_You);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lbl_name = new QLabel(groupBox_You);
        lbl_name->setObjectName(QString::fromUtf8("lbl_name"));
        lbl_name->setStyleSheet(QString::fromUtf8("font-family: \"Comic Sans MS\";"));

        verticalLayout_2->addWidget(lbl_name);

        lbl_section = new QLabel(groupBox_You);
        lbl_section->setObjectName(QString::fromUtf8("lbl_section"));

        verticalLayout_2->addWidget(lbl_section);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        txt_username_input = new QLineEdit(groupBox_You);
        txt_username_input->setObjectName(QString::fromUtf8("txt_username_input"));

        verticalLayout_3->addWidget(txt_username_input);

        comboBox_section = new QComboBox(groupBox_You);
        comboBox_section->setObjectName(QString::fromUtf8("comboBox_section"));

        verticalLayout_3->addWidget(comboBox_section);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_6->addWidget(groupBox_You);

        groupBox_Microphone = new QGroupBox(FillDataPage);
        groupBox_Microphone->setObjectName(QString::fromUtf8("groupBox_Microphone"));
        groupBox_Microphone->setStyleSheet(QString::fromUtf8("font-family: \"Comic Sans MS\";"));
        verticalLayout_4 = new QVBoxLayout(groupBox_Microphone);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        img_microphone = new QLabel(groupBox_Microphone);
        img_microphone->setObjectName(QString::fromUtf8("img_microphone"));

        horizontalLayout_3->addWidget(img_microphone);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboBox_audio_inputs = new QComboBox(groupBox_Microphone);
        comboBox_audio_inputs->setObjectName(QString::fromUtf8("comboBox_audio_inputs"));

        horizontalLayout_2->addWidget(comboBox_audio_inputs);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        progressBar_microphone = new QProgressBar(groupBox_Microphone);
        progressBar_microphone->setObjectName(QString::fromUtf8("progressBar_microphone"));
        progressBar_microphone->setStyleSheet(QString::fromUtf8("border: 0px ;\n"
"background-color: rgb(70, 215, 0);"));
        progressBar_microphone->setValue(24);
        progressBar_microphone->setTextVisible(false);

        verticalLayout_4->addWidget(progressBar_microphone);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        img_microphone_volume = new QLabel(groupBox_Microphone);
        img_microphone_volume->setObjectName(QString::fromUtf8("img_microphone_volume"));

        gridLayout_3->addWidget(img_microphone_volume, 0, 0, 1, 1);

        horizontalSlider_microphone = new QSlider(groupBox_Microphone);
        horizontalSlider_microphone->setObjectName(QString::fromUtf8("horizontalSlider_microphone"));
        horizontalSlider_microphone->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 0px;\n"
"	\n"
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

        gridLayout_3->addWidget(horizontalSlider_microphone, 0, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_3);


        verticalLayout_6->addWidget(groupBox_Microphone);

        groupBox_Headphones = new QGroupBox(FillDataPage);
        groupBox_Headphones->setObjectName(QString::fromUtf8("groupBox_Headphones"));
        groupBox_Headphones->setStyleSheet(QString::fromUtf8("font-family: \"Comic Sans MS\";"));
        verticalLayout_5 = new QVBoxLayout(groupBox_Headphones);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        img_headphones = new QLabel(groupBox_Headphones);
        img_headphones->setObjectName(QString::fromUtf8("img_headphones"));

        horizontalLayout_5->addWidget(img_headphones);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        comboBox_audio_outputs = new QComboBox(groupBox_Headphones);
        comboBox_audio_outputs->setObjectName(QString::fromUtf8("comboBox_audio_outputs"));

        horizontalLayout_4->addWidget(comboBox_audio_outputs);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_5);

        progressBar_headphones = new QProgressBar(groupBox_Headphones);
        progressBar_headphones->setObjectName(QString::fromUtf8("progressBar_headphones"));
        progressBar_headphones->setStyleSheet(QString::fromUtf8("border: 0px ;\n"
"background-color: rgb(70, 215, 0);"));
        progressBar_headphones->setValue(24);
        progressBar_headphones->setTextVisible(false);

        verticalLayout_5->addWidget(progressBar_headphones);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        img_headphones_volume = new QLabel(groupBox_Headphones);
        img_headphones_volume->setObjectName(QString::fromUtf8("img_headphones_volume"));

        horizontalLayout_7->addWidget(img_headphones_volume);

        horizontalSlider_headphones = new QSlider(groupBox_Headphones);
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

        horizontalLayout_7->addWidget(horizontalSlider_headphones);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);

        label_9 = new QLabel(groupBox_Headphones);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_8->addWidget(label_9);


        horizontalLayout_9->addLayout(horizontalLayout_8);

        label_10 = new QLabel(groupBox_Headphones);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_9->addWidget(label_10);


        verticalLayout_5->addLayout(horizontalLayout_9);


        verticalLayout_6->addWidget(groupBox_Headphones);

        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        horizontalLayout_10->addLayout(verticalLayout_6);

        horizontalSpacer = new QSpacerItem(54, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        line = new QFrame(FillDataPage);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_10->addWidget(line);

        horizontalSpacer_2 = new QSpacerItem(54, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btn_join_member = new QPushButton(FillDataPage);
        btn_join_member->setObjectName(QString::fromUtf8("btn_join_member"));
        btn_join_member->setEnabled(true);
        btn_join_member->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"font-family: \"Comic Sans MS\";\n"
"font: bold;\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 1px;\n"
"background-color: rgb(85, 0, 255);\n"
"/*For getting optimal results i will add an Image as background fot the button*/"));

        gridLayout_2->addWidget(btn_join_member, 3, 1, 1, 1);

        lbl_choir_member = new QLabel(FillDataPage);
        lbl_choir_member->setObjectName(QString::fromUtf8("lbl_choir_member"));
        lbl_choir_member->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"font-family: \"Comic Sans MS\";\n"
"font: bold;\n"
"color: purple"));

        gridLayout_2->addWidget(lbl_choir_member, 2, 0, 1, 1);

        ip_address_join_member = new QLineEdit(FillDataPage);
        ip_address_join_member->setObjectName(QString::fromUtf8("ip_address_join_member"));

        gridLayout_2->addWidget(ip_address_join_member, 1, 0, 1, 2);

        lbl_join_choir = new QLabel(FillDataPage);
        lbl_join_choir->setObjectName(QString::fromUtf8("lbl_join_choir"));
        lbl_join_choir->setStyleSheet(QString::fromUtf8("font-size: 30px;\n"
"font-family: \"Comic Sans MS\";\n"
"font: bold"));

        gridLayout_2->addWidget(lbl_join_choir, 0, 0, 1, 2);


        verticalLayout->addLayout(gridLayout_2);

        img_OR = new QLabel(FillDataPage);
        img_OR->setObjectName(QString::fromUtf8("img_OR"));

        verticalLayout->addWidget(img_OR);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lbl_new_session = new QLabel(FillDataPage);
        lbl_new_session->setObjectName(QString::fromUtf8("lbl_new_session"));
        lbl_new_session->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"font-family: \"Comic Sans MS\";\n"
"font: bold"));

        gridLayout->addWidget(lbl_new_session, 0, 0, 1, 2);

        lbl_choir_leader = new QLabel(FillDataPage);
        lbl_choir_leader->setObjectName(QString::fromUtf8("lbl_choir_leader"));
        lbl_choir_leader->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"font-family: \"Comic Sans MS\";\n"
"font: bold;\n"
"color: purple"));

        gridLayout->addWidget(lbl_choir_leader, 1, 0, 1, 1);

        btn_join_leader = new QPushButton(FillDataPage);
        btn_join_leader->setObjectName(QString::fromUtf8("btn_join_leader"));
        btn_join_leader->setEnabled(true);
        btn_join_leader->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"font-family: \"Comic Sans MS\";\n"
"font: bold;\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 1px;\n"
"background-color: rgb(85, 0, 255);\n"
"/*For getting optimal results i will add an Image as background fot the button*/"));

        gridLayout->addWidget(btn_join_leader, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_7->addLayout(verticalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);


        horizontalLayout_10->addLayout(verticalLayout_7);


        retranslateUi(FillDataPage);

        QMetaObject::connectSlotsByName(FillDataPage);
    } // setupUi

    void retranslateUi(QWidget *FillDataPage)
    {
        FillDataPage->setWindowTitle(QCoreApplication::translate("FillDataPage", "Form", nullptr));
        lbl_get_ready->setText(QCoreApplication::translate("FillDataPage", "1. Get ready", nullptr));
        groupBox_You->setTitle(QCoreApplication::translate("FillDataPage", "1. You", nullptr));
        lbl_name->setText(QCoreApplication::translate("FillDataPage", "Name:", nullptr));
        lbl_section->setText(QCoreApplication::translate("FillDataPage", "Section:", nullptr));
        txt_username_input->setText(QCoreApplication::translate("FillDataPage", "Demo User", nullptr));
        txt_username_input->setPlaceholderText(QString());
        groupBox_Microphone->setTitle(QCoreApplication::translate("FillDataPage", "2. Microphone", nullptr));
        img_microphone->setText(QCoreApplication::translate("FillDataPage", "micImg", nullptr));
        img_microphone_volume->setText(QCoreApplication::translate("FillDataPage", "volImg1", nullptr));
        groupBox_Headphones->setTitle(QCoreApplication::translate("FillDataPage", "3. Headphones", nullptr));
        img_headphones->setText(QCoreApplication::translate("FillDataPage", "setImg", nullptr));
        img_headphones_volume->setText(QCoreApplication::translate("FillDataPage", "volImg2", nullptr));
        label_9->setText(QCoreApplication::translate("FillDataPage", "Test audio:", nullptr));
        label_10->setText(QCoreApplication::translate("FillDataPage", "Play_img", nullptr));
        btn_join_member->setText(QCoreApplication::translate("FillDataPage", "Join", nullptr));
        lbl_choir_member->setText(QCoreApplication::translate("FillDataPage", "As Choir Member", nullptr));
        ip_address_join_member->setPlaceholderText(QCoreApplication::translate("FillDataPage", "IP address", nullptr));
        lbl_join_choir->setText(QCoreApplication::translate("FillDataPage", "2. Join a Choir room", nullptr));
        img_OR->setText(QCoreApplication::translate("FillDataPage", "Image_OR_placeholder", nullptr));
        lbl_new_session->setText(QCoreApplication::translate("FillDataPage", "3. Start a New Session", nullptr));
        lbl_choir_leader->setText(QCoreApplication::translate("FillDataPage", "As Choir Leader", nullptr));
        btn_join_leader->setText(QCoreApplication::translate("FillDataPage", "Join", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FillDataPage: public Ui_FillDataPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILLDATAPAGE_H
