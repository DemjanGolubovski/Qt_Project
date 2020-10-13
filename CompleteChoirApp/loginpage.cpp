#include "loginpage.h"
#include "ui_loginpage.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "filldatapage.h"
#include "ui_filldatapage.h"

#include <QGraphicsDropShadowEffect>

LogInPage::LogInPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogInPage)
{
    ui->setupUi(this);

    // Add shadow effect to the buttons
    QGraphicsDropShadowEffect *effect_btn_leader = new QGraphicsDropShadowEffect(this);
    effect_btn_leader->setBlurRadius(5);
    effect_btn_leader->setXOffset(5);
    effect_btn_leader->setYOffset(5);
    effect_btn_leader->setColor(Qt::black);

    ui->btn_start_leader->setGraphicsEffect(effect_btn_leader);

    QGraphicsDropShadowEffect *effect_btn_member = new QGraphicsDropShadowEffect(this);
    effect_btn_member->setBlurRadius(5);
    effect_btn_member->setXOffset(5);
    effect_btn_member->setYOffset(5);
    effect_btn_member->setColor(Qt::black);

    ui->btn_start_member->setGraphicsEffect(effect_btn_member);
}

LogInPage::~LogInPage()
{
    delete ui;
}

void LogInPage::on_btn_start_leader_clicked()
{
    // Log in as Choir Leader
    MainWindow *win=(MainWindow *)QApplication::activeWindow();
    win->getUi()->stackedWidget->setCurrentIndex(1);

    FillDataPage *nextPage=static_cast<FillDataPage *>(win->getUi()->stackedWidget->widget(1));
    nextPage->getUi()->comboBox_section->setHidden(true);
    nextPage->getUi()->lbl_section->setHidden(true);
}

void LogInPage::on_btn_start_member_clicked()
{
    // Log in as Choir Member
    MainWindow *win=(MainWindow *)QApplication::activeWindow();
    win->getUi()->stackedWidget->setCurrentIndex(1);

    FillDataPage *nextPage=static_cast<FillDataPage *>(win->getUi()->stackedWidget->widget(1));
    nextPage->getUi()->img_OR->setHidden(true);
    nextPage->getUi()->lbl_new_session->setHidden(true);
    nextPage->getUi()->lbl_choir_leader->setHidden(true);
    nextPage->getUi()->btn_join_leader->setHidden(true);
}
