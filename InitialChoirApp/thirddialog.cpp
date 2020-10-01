#include "thirddialog.h"
#include "ui_thirddialog.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include "delegate.h"

ThirdDialog::ThirdDialog(User u, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdDialog),
    user(u)
{
    ui->setupUi(this);

    ui->label_7->setText(user.getName());

    QStandardItemModel *model=new QStandardItemModel(this);
    ui->listView->setModel(model);
    Delegate *delegate=new Delegate(user, this);

    delegate->setContentsMargins(8, 8, 8, 8);
    delegate->setIconSize(15, 15);
    delegate->setHorizontalSpacing(8);
    delegate->setVerticalSpacing(4);

    ui->listView->setModel(model);
    ui->listView->setItemDelegate(delegate);

    QStandardItem *item = new QStandardItem(QIcon(QPixmap(":/Images/Images/speaker.png")), user.getName());

    item->setFlags(Qt::ItemIsEditable | Qt::ItemIsEnabled);//|Qt::ItemIsSelectable

    static_cast<QStandardItemModel *>(model)->appendRow(item);

//    QStandardItem *item2 = new QStandardItem(QIcon(QPixmap(":/Images/Images/speaker.png")), user.getName());

//    item2->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable);

//    static_cast<QStandardItemModel *>(model)->appendRow(item2);
    ui->listView->scrollToBottom();
}

ThirdDialog::~ThirdDialog()
{
    delete ui;
}

User ThirdDialog::getUser() const
{
    return user;
}

void ThirdDialog::setUser(const User &value)
{
    user = value;
}
