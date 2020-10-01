#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    model=new QDirModel(this);
    model->setReadOnly(false);
    model->setSorting(QDir::Name | QDir::DirsFirst | QDir::IgnoreCase);
    ui->treeView->setModel(model);

    QModelIndex index=model->index("C:/");
    ui->treeView->expand(index);
    ui->treeView->setCurrentIndex(index);
    ui->treeView->scrollTo(index);
    ui->treeView->resizeColumnToContents(0);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_2_clicked()
{
    // add
    QModelIndex index=ui->treeView->currentIndex();
    if(!index.isValid()) return;

    QString name=QInputDialog::getText(this, "Name", "Add a name");
    if(name.isEmpty()) return;

    model->mkdir(index, name);
}

void Dialog::on_pushButton_clicked()
{
    // delete
    QModelIndex index=ui->treeView->currentIndex();
    if(!index.isValid()) return;

    if(model->fileInfo(index).isDir())
        model->rmdir(index);
    else
        model->remove(index);
}
