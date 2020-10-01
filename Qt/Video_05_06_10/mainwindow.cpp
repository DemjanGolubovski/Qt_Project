#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_Window_triggered()
{
//    Model approach
//    Dialog d;
//    d.setModal(true);
//    d.exec();

//    Modelless approach = deklariran e pointer od Dialog vo mainwindow.h
    d=new Dialog();
    d->show();
}
