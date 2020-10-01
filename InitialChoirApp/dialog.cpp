#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    // Loged in as choir leader
    user.setUser_role("leader");
    sec_dialog=new SecondDialog(user);

    sec_dialog->show();
    hide();
}

void Dialog::on_pushButton_2_clicked()
{
    // loged in as choir member
    if(ui->lineEdit->text()!=""){
        user.setIp_address_login(ui->lineEdit->text());
        user.setUser_role("member");
        sec_dialog=new SecondDialog(user);

        sec_dialog->show();
        hide();
    }
}
