#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    dirmodel=new QFileSystemModel(this);
    dirmodel->setRootPath("C:/");
    dirmodel->setFilter(QDir::NoDotDot | QDir::AllDirs);

    ui->treeView->setModel(dirmodel);

    filemodel=new QFileSystemModel(this);
    filemodel->setRootPath("C:/");
    filemodel->setFilter(QDir::NoDotDot | QDir::Files);

    ui->listView->setModel(filemodel);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_treeView_clicked(const QModelIndex &index)
{
    QString path=dirmodel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(filemodel->setRootPath(path));
}
