#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QtGui>
#include <QSpacerItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    log_in_page=new LogInPage(this);
    fill_data_page=new FillDataPage(this);
    choir_page=new ChoirPage(this);

    ui->stackedWidget->insertWidget(0, log_in_page);
    ui->stackedWidget->insertWidget(1, fill_data_page);
    ui->stackedWidget->insertWidget(2, choir_page);

    ui->stackedWidget->setCurrentIndex(0);

    QPushButton *btn=new QPushButton("Exit", this);
    mic_img_me=new CustomLabel(this);
    mic_img_choir=new CustomLabel(this);
    QLabel *spacer=new QLabel("", this);

    spacer->setStyleSheet("background-color: #D3D3D3;");

    QPixmap ins_img(":/Images/Images/white_mic.png");
    mic_img_me->setPixmap(ins_img.scaled(60, 60, Qt::KeepAspectRatio));
    mic_img_me->setStyleSheet("background-color: #D3D3D3;");

    QPixmap ins_img_choir(":/Images/Images/white_mic_choir.png");
    mic_img_choir->setPixmap(ins_img_choir.scaled(75, 75, Qt::KeepAspectRatio));
    mic_img_choir->setStyleSheet("background-color: #D3D3D3;");

    btn->setStyleSheet("background-color: red;border: 0px; color: white; font-size: 15px;font-family: Comic Sans MS;font: bold; padding-top: 3px;"
                       "padding-bottom: 3px; padding-left: 40px; padding-right: 40px;");


    ui->statusBar->insertWidget(0, mic_img_me);
    ui->statusBar->insertWidget(1, mic_img_choir);
    ui->statusBar->insertWidget(2, spacer, ui->statusBar->width()-ui->statusBar->width()*0.2);
    ui->statusBar->insertWidget(3, btn);
    ui->statusBar->setStyleSheet("background-color: #D3D3D3; padding: 10px");

    ui->statusBar->setHidden(true);
    ui->toolBar->setHidden(true);

    // Adding functionality to the buttons on the status bar
    connect(btn, &QPushButton::clicked, this, &MainWindow::exit_clicked);
    connect(mic_img_me, &CustomLabel::Mouse_Pressed, this, &MainWindow::mouse_pressed_img_me);
    connect(mic_img_choir, &CustomLabel::Mouse_Pressed, this, &MainWindow::mouse_pressed_img_choir);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Initializing static flags
int MainWindow::img_me_flag=-1;
int MainWindow::img_choir_flag=-1;

Ui::MainWindow *MainWindow::getUi() const
{
    return ui;
}

void MainWindow::setUi(Ui::MainWindow *value)
{
    ui = value;
}

void MainWindow::mouse_pressed_img_me()
{
    if(img_me_flag==-1){
        // set the image Unmute me
        QPixmap ins_img(":/Images/Images/mute_mic.png");
        mic_img_me->setPixmap(ins_img.scaled(70, 70, Qt::KeepAspectRatio));
        mic_img_me->setStyleSheet("background-color: #D3D3D3;");
    }
    else{
        // set the image Mute me
        QPixmap ins_img(":/Images/Images/white_mic.png");
        mic_img_me->setPixmap(ins_img.scaled(60, 60, Qt::KeepAspectRatio));
        mic_img_me->setStyleSheet("background-color: #D3D3D3;");
    }
    img_me_flag*=-1;
}

void MainWindow::mouse_pressed_img_choir()
{
    if(img_choir_flag==-1){
        // set the image Unmute me
        QPixmap ins_img(":/Images/Images/mute_mic_choir.png");
        mic_img_choir->setPixmap(ins_img.scaled(77, 77, Qt::KeepAspectRatio));
        mic_img_choir->setStyleSheet("background-color: #D3D3D3;");
    }
    else{
        // set the image Mute me
        QPixmap ins_img(":/Images/Images/white_mic_choir.png");
        mic_img_choir->setPixmap(ins_img.scaled(75, 75, Qt::KeepAspectRatio));
        mic_img_choir->setStyleSheet("background-color: #D3D3D3;");
    }
    img_choir_flag*=-1;
}

void MainWindow::exit_clicked()
{

    // Got an sigsegv segmentation fault error
//    QMessageBox::StandardButton reply;
//    reply = QMessageBox::question(0, "Test", "Quit?", QMessageBox::Yes|QMessageBox::No);
//    if (reply == QMessageBox::Yes) {
//        ui->statusBar->setHidden(true);
//        ui->toolBar->setHidden(true);
//        ui->toolBar->clear();
//        ui->stackedWidget->setCurrentIndex(1);
//    }

    ui->statusBar->setHidden(true);
    ui->toolBar->setHidden(true);
    ui->toolBar->clear();
    ui->stackedWidget->setCurrentIndex(1);
}

QLabel *MainWindow::getMic_img_choir() const
{
    return mic_img_choir;
}

void MainWindow::setMic_img_choir(CustomLabel *value)
{
    mic_img_choir = value;
}
