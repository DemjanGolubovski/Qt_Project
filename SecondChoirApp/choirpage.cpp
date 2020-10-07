#include "choirpage.h"
#include "ui_choirpage.h"

#include <QtDebug>

ChoirPage::ChoirPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChoirPage)
{
    ui->setupUi(this);

    // Setting up the images    
    QPixmap ins_img(":/Images/Images/black_mic.png");
    ui->label_8->setPixmap(ins_img.scaled(25, 25, Qt::KeepAspectRatio));

    ins_img.load(":/Images/Images/headphones.png");
    ui->label_10->setPixmap(ins_img.scaled(25, 25, Qt::KeepAspectRatio));

    ins_img.load(":/Images/Images/speaker.png");
    ui->label_11->setPixmap(ins_img.scaled(20, 20, Qt::KeepAspectRatio));
    ui->label_2->setPixmap(ins_img.scaled(20, 20, Qt::KeepAspectRatio));
    ui->label_9->setPixmap(ins_img.scaled(20, 20, Qt::KeepAspectRatio));

    // Adjusting sizes of widgets
    ui->progressBar->setFixedHeight(7);
    ui->horizontalSlider->setFixedHeight(15);
    ui->horizontalSlider_2->setFixedHeight(15);
    ui->horizontalSlider_3->setFixedHeight(15);

    // Adding some static values
    ui->label_4->setText("16");
    ui->lineEdit->setText("Demo Leader");
    ui->lineEdit->setReadOnly(true);
    ui->label_12->setText("Demo Leader");

    ui->comboBox->addItem("Sopranos");
    ui->comboBox->addItem("Altos");
    ui->comboBox->addItem("Tenors");
    ui->comboBox->addItem("Basses");

    ui->comboBox_2->addItem("Blue Yeti");
    ui->comboBox_3->addItem("Realtek");
}

ChoirPage::~ChoirPage()
{
    delete ui;
}

Ui::ChoirPage *ChoirPage::getUi() const
{
    return ui;
}

void ChoirPage::setUi(Ui::ChoirPage *value)
{
    ui = value;
}
