#include "seconddialog.h"
#include "ui_seconddialog.h"
#include "thirddialog.h"

SecondDialog::SecondDialog(User u, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondDialog)
{
    ui->setupUi(this);
    user=u;
    if(u.getUser_role()=="leader")
    {
        ui->comboBox->setHidden(true);
        ui->label_4->setHidden(true);

        int w,h;
        w=ui->groupBox->width();
        h=ui->groupBox->height();
        ui->groupBox->resize(w, h-17);

    }
    else{
        ui->label_10->setHidden(true);
        ui->line_2->setHidden(true);
        ui->line_3->setHidden(true);
        ui->label_11->setHidden(true);
        ui->label_12->setHidden(true);
        ui->label_13->setHidden(true);
        ui->pushButton_2->setHidden(true);
    }
}

SecondDialog::~SecondDialog()
{
    delete ui;
}

User SecondDialog::getUser() const
{
    return user;
}

void SecondDialog::setUser(User value)
{
    user = value;
}

void SecondDialog::on_pushButton_clicked()
{
    user.setName(ui->lblName->text());
    third_dial=new ThirdDialog(user);
    third_dial->show();
}
