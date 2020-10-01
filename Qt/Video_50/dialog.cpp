#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    delegate=new Delegate(this);
    model=new QStandardItemModel(4, 2, this);

    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            QModelIndex index=model->index(i, j, QModelIndex());
            model->setData(index, 1);
        }
    }

    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(delegate); // Ako ova ne se setira togash kje go koristi default-niot delegate
}

Dialog::~Dialog()
{
    delete ui;
}

