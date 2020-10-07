#include <QStandardItemModel>
#include <QStandardItem>
#include <QAbstractItemView>
#include <QGraphicsDropShadowEffect>

#include "delegate.h"
#include "choirdelegate.h"

#include "filldatapage.h"
#include "ui_filldatapage.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "choirpage.h"
#include "ui_choirpage.h"

FillDataPage::FillDataPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FillDataPage)
{
    ui->setupUi(this);

    // Setting up the images
    QPixmap ins_img(":/Images/Images/black_mic.png");
    ui->label_5->setPixmap(ins_img.scaled(25, 25, Qt::KeepAspectRatio));
    ui->Image_OR->setPixmap(QPixmap(":/Images/Images/TextImage.png"));

    ins_img.load(":/Images/Images/speaker.png");
    ui->label_6->setPixmap(ins_img.scaled(20, 20, Qt::KeepAspectRatio));

    ins_img.load(":/Images/Images/headphones.png");
    ui->label_8->setPixmap(ins_img.scaled(25, 25, Qt::KeepAspectRatio));

    ins_img.load(":/Images/Images/speaker.png");
    ui->label_7->setPixmap(ins_img.scaled(20, 20, Qt::KeepAspectRatio));

    ui->label_10->setPixmap(QPixmap(":/Images/Images/play_icon.png"));

    // Adding the instruments
    ui->comboBox->addItem("Sopranos");
    ui->comboBox->addItem("Altos");
    ui->comboBox->addItem("Tenors");
    ui->comboBox->addItem("Basses");

    // Adjusting sizes of widgets
    ui->progressBar->setFixedHeight(7);
    ui->progressBar_2->setFixedHeight(7);
    ui->horizontalSlider->setFixedHeight(15);
    ui->horizontalSlider_2->setFixedHeight(15);

    // Add static values
    ui->comboBox_2->addItem("Blue Yeti");
    ui->comboBox_3->addItem("Realtek");

    // Add shadow effect to the buttons
    QGraphicsDropShadowEffect *effect_btn_member = new QGraphicsDropShadowEffect(this);
    effect_btn_member->setBlurRadius(5);
    effect_btn_member->setXOffset(5);
    effect_btn_member->setYOffset(5);
    effect_btn_member->setColor(Qt::black);

    ui->pushButton->setGraphicsEffect(effect_btn_member);

    QGraphicsDropShadowEffect *effect_btn_leader = new QGraphicsDropShadowEffect(this);
    effect_btn_leader->setBlurRadius(5);
    effect_btn_leader->setXOffset(5);
    effect_btn_leader->setYOffset(5);
    effect_btn_leader->setColor(Qt::black);

    ui->pushButton_2->setGraphicsEffect(effect_btn_leader);
}

FillDataPage::~FillDataPage()
{
    delete ui;
}

Ui::FillDataPage *FillDataPage::getUi() const
{
    return ui;
}

void FillDataPage::setUi(Ui::FillDataPage *value)
{
    ui = value;
}

void FillDataPage::on_pushButton_clicked()
{
    // As Choir Member
    MainWindow *win=(MainWindow *)QApplication::activeWindow();
    win->getUi()->stackedWidget->insertWidget(2, new ChoirPage()); // This is added to reload the page, everything that was hidden is not hidden
    win->getUi()->stackedWidget->setCurrentIndex(2);
    win->getUi()->statusBar->show();

    win->getMic_img_choir()->setHidden(true);

    // Tool bar
    QLabel *lbl_tool_bar=new QLabel("Demo - Choir Member", this);
    win->getUi()->toolBar->addWidget(lbl_tool_bar);
    win->getUi()->toolBar->show();

    // Hide widgets
    ChoirPage *choirpage=static_cast<ChoirPage *>(win->getUi()->stackedWidget->widget(2));
    choirpage->getUi()->label_3->setText("Participants:");
    choirpage->getUi()->horizontalSlider->setHidden(true);
    choirpage->getUi()->label_2->setHidden(true);
    choirpage->getUi()->label_5->setHidden(true);
    choirpage->getUi()->lineEdit->setHidden(true);
    choirpage->getUi()->label->setHidden(true);
    choirpage->getUi()->horizontalSpacer->changeSize(0,0);
    choirpage->getUi()->horizontalSpacer_7->changeSize(0,0);
    choirpage->getUi()->horizontalSpacer_8->changeSize(0,0);

    // Connecting ListView with Model
    QStandardItemModel *model=new QStandardItemModel(this);

    choirpage->getUi()->listView->setModel(model);
    choirpage->getUi()->listView_2->setModel(model);
    choirpage->getUi()->listView_3->setModel(model);
    choirpage->getUi()->listView_4->setModel(model);

    // Connecting list view with delegate
    ChoirDelegate *delegate=new ChoirDelegate(this);

    delegate->setContentsMargins(8, 8, 8, 8);
//    delegate->setIconSize(15, 15);
    delegate->setHorizontalSpacing(8);
    delegate->setVerticalSpacing(4);

    choirpage->getUi()->listView->setItemDelegate(delegate);
    choirpage->getUi()->listView_2->setItemDelegate(delegate);
    choirpage->getUi()->listView_3->setItemDelegate(delegate);
    choirpage->getUi()->listView_4->setItemDelegate(delegate);

    QStandardItem *root=model->invisibleRootItem();
    for(int i=0; i<4; i++){
        QStandardItem *ins_item=new QStandardItem(QString("Demo User"));
        ins_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        root->appendRow(ins_item);
    }
}

void FillDataPage::on_pushButton_2_clicked()
{
    // As Choir Leader
    MainWindow *win=(MainWindow *)QApplication::activeWindow();
    win->getUi()->stackedWidget->insertWidget(2, new ChoirPage()); // This is added to reload the page, everything that was hidden is not hidden
    win->getUi()->stackedWidget->setCurrentIndex(2);
    win->getUi()->statusBar->show();

    win->getMic_img_choir()->show();

    // Tool bar
    QLabel *lbl_tool_bar=new QLabel("Demo - Choir Leader", this);
    win->getUi()->toolBar->addWidget(lbl_tool_bar);
    win->getUi()->toolBar->show();

    // Removing some wigets
    ChoirPage *choirpage=static_cast<ChoirPage *>(win->getUi()->stackedWidget->widget(2));
    choirpage->getUi()->groupBox_6->setHidden(true);
    choirpage->getUi()->groupBox_9->setHidden(true);
    choirpage->getUi()->horizontalSpacer_2->changeSize(0, 0);
    choirpage->getUi()->horizontalSpacer_9->changeSize(0, 0);

    // Connecting the ListViews with the model and the delegate
    QStandardItemModel *model=new QStandardItemModel(this);
    choirpage->getUi()->listView->setModel(model);
    choirpage->getUi()->listView_2->setModel(model);
    choirpage->getUi()->listView_3->setModel(model);
    choirpage->getUi()->listView_4->setModel(model);
    Delegate *delegate=new Delegate(this);

    delegate->setContentsMargins(8, 8, 8, 8);
    delegate->setIconSize(15, 15);
    delegate->setHorizontalSpacing(8);
    delegate->setVerticalSpacing(4);

    choirpage->getUi()->listView->setItemDelegate(delegate);
    choirpage->getUi()->listView_2->setItemDelegate(delegate);
    choirpage->getUi()->listView_3->setItemDelegate(delegate);
    choirpage->getUi()->listView_4->setItemDelegate(delegate);

    // Add static items to the all the Views
    QStandardItem *item = new QStandardItem(QIcon(QPixmap(":/Images/Images/speaker.png")), "");
    item->setFlags(Qt::ItemIsEditable | Qt::ItemIsEnabled);
    static_cast<QStandardItemModel *>(model)->appendRow(item);

    QStandardItem *item_2 = new QStandardItem(QIcon(QPixmap(":/Images/Images/speaker.png")), "");
    item_2->setFlags(Qt::ItemIsEditable | Qt::ItemIsEnabled);
    static_cast<QStandardItemModel *>(model)->appendRow(item_2);

    QStandardItem *item_3 = new QStandardItem(QIcon(QPixmap(":/Images/Images/speaker.png")), "");
    item_3->setFlags(Qt::ItemIsEditable | Qt::ItemIsEnabled);
    static_cast<QStandardItemModel *>(model)->appendRow(item_3);

    QStandardItem *item_4 = new QStandardItem(QIcon(QPixmap(":/Images/Images/speaker.png")), "");
    item_4->setFlags(Qt::ItemIsEditable | Qt::ItemIsEnabled);
    static_cast<QStandardItemModel *>(model)->appendRow(item_4);

    choirpage->getUi()->listView->scrollToBottom();
}
