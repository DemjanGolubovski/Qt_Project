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

#include "User.h"
#include "ChoirLeaderModel.h"

FillDataPage::FillDataPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FillDataPage)
{
    ui->setupUi(this);

    // Setting up the images
    QPixmap ins_img(":/Images/Images/black_mic.png");
    ui->img_microphone->setPixmap(ins_img.scaled(25, 25, Qt::KeepAspectRatio));
    ui->img_OR->setPixmap(QPixmap(":/Images/Images/TextImage.png"));

    ins_img.load(":/Images/Images/speaker.png");
    ui->img_microphone_volume->setPixmap(ins_img.scaled(20, 20, Qt::KeepAspectRatio));

    ins_img.load(":/Images/Images/headphones.png");
    ui->img_headphones->setPixmap(ins_img.scaled(25, 25, Qt::KeepAspectRatio));

    ins_img.load(":/Images/Images/speaker.png");
    ui->img_headphones_volume->setPixmap(ins_img.scaled(20, 20, Qt::KeepAspectRatio));

    ui->label_10->setPixmap(QPixmap(":/Images/Images/play_icon.png"));

    // Adding the instruments
    ui->comboBox_section->addItem("Sopranos");
    ui->comboBox_section->addItem("Altos");
    ui->comboBox_section->addItem("Tenors");
    ui->comboBox_section->addItem("Basses");

    // Adjusting sizes of widgets
    ui->progressBar_microphone->setFixedHeight(7);
    ui->progressBar_headphones->setFixedHeight(7);
    ui->horizontalSlider_headphones->setFixedHeight(15);
    ui->horizontalSlider_microphone->setFixedHeight(15);

    // Add values to the comboBox widgets
    // Audio inputs in the OS
    QList<QAudioDeviceInfo> deviceInfos_input;
    deviceInfos_input = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    int list_size = 0;
    for (const QAudioDeviceInfo& deviceInfo : deviceInfos_input) {
        ui->comboBox_audio_inputs->addItem(deviceInfo.deviceName());
        list_size++;
        if (list_size == deviceInfos_input.size() / 2)
            break;
    }

    // Audio outputs in the OS
    QList<QAudioDeviceInfo> deviceInfos_output;
    deviceInfos_output = QAudioDeviceInfo::availableDevices(QAudio::AudioOutput);
    list_size = 0;
    for (const QAudioDeviceInfo& deviceInfo : deviceInfos_output) {
        ui->comboBox_audio_outputs->addItem(deviceInfo.deviceName());
        list_size++;
        if (list_size == deviceInfos_output.size() / 2)
            break;
    }

    // Add shadow effect to the buttons
    QGraphicsDropShadowEffect *effect_btn_member = new QGraphicsDropShadowEffect(this);
    effect_btn_member->setBlurRadius(5);
    effect_btn_member->setXOffset(5);
    effect_btn_member->setYOffset(5);
    effect_btn_member->setColor(Qt::black);

    ui->btn_join_member->setGraphicsEffect(effect_btn_member);

    QGraphicsDropShadowEffect *effect_btn_leader = new QGraphicsDropShadowEffect(this);
    effect_btn_leader->setBlurRadius(5);
    effect_btn_leader->setXOffset(5);
    effect_btn_leader->setYOffset(5);
    effect_btn_leader->setColor(Qt::black);

    ui->btn_join_leader->setGraphicsEffect(effect_btn_leader);
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

void FillDataPage::on_btn_join_member_clicked()
{
    // As Choir Member
    MainWindow *win=(MainWindow *)QApplication::activeWindow();
    win->getUi()->stackedWidget->insertWidget(2, new ChoirPage()); // This is added to reload the page, everything that was hidden is not hidden
    win->getUi()->stackedWidget->setCurrentIndex(2);
    win->getUi()->statusBar->show();

    win->getMic_img_choir()->setHidden(true);

    // Tool bar
    QLabel *lbl_tool_bar=new QLabel("Demo - Choir Member", this);
    lbl_tool_bar->setStyleSheet("font-family: Comic Sans MS;");
    win->getUi()->toolBar->addWidget(lbl_tool_bar);
    win->getUi()->toolBar->show();

    // Hide widgets
    ChoirPage *choirpage=static_cast<ChoirPage *>(win->getUi()->stackedWidget->widget(2));
    choirpage->getUi()->lbl_members->setText("Participants:");
    choirpage->getUi()->horizontalSlider_session->setHidden(true);
    choirpage->getUi()->img_session_volume->setHidden(true);
    choirpage->getUi()->lbl_choir_volume->setHidden(true);
    choirpage->getUi()->txt_leader_name->setHidden(true);
    choirpage->getUi()->lbl_session_leader->setHidden(true);
    choirpage->getUi()->horizontalSpacer->changeSize(0,0);
    choirpage->getUi()->horizontalSpacer_7->changeSize(0,0);
    choirpage->getUi()->horizontalSpacer_8->changeSize(0,0);

    // Connecting ListView with Model
    QStandardItemModel *model_sopranos=new QStandardItemModel(this);
    QStandardItemModel *model_altos=new QStandardItemModel(this);
    QStandardItemModel *model_tenors=new QStandardItemModel(this);
    QStandardItemModel *model_basses=new QStandardItemModel(this);

    choirpage->getUi()->listView_sopranos->setModel(model_sopranos);
    choirpage->getUi()->listView_altos->setModel(model_altos);
    choirpage->getUi()->listView_tenors->setModel(model_tenors);
    choirpage->getUi()->listView_basses->setModel(model_basses);

    // Connecting list view with delegate
    ChoirDelegate *delegate=new ChoirDelegate(this);

    delegate->setContentsMargins(8, 4, 4, 4);
    delegate->setHorizontalSpacing(8);
    delegate->setVerticalSpacing(4);

    choirpage->getUi()->listView_sopranos->setItemDelegate(delegate);
    choirpage->getUi()->listView_altos->setItemDelegate(delegate);
    choirpage->getUi()->listView_tenors->setItemDelegate(delegate);
    choirpage->getUi()->listView_basses->setItemDelegate(delegate);

    // Addint static items(usernames)
    QStandardItem *root_sopranos=model_sopranos->invisibleRootItem();
    QStandardItem *root_altos=model_altos->invisibleRootItem();
    QStandardItem *root_basses=model_basses->invisibleRootItem();
    QStandardItem *root_tenors=model_tenors->invisibleRootItem();

   static_fill_listviews(0, 4, root_altos, model_altos);
   static_fill_listviews(4, 6,root_basses, model_basses);
   static_fill_listviews(6, 12, root_tenors, model_tenors);
   static_fill_listviews(12, 16, root_sopranos, model_sopranos);
}

void FillDataPage::static_fill_listviews(int start, int end, QStandardItem *root, QStandardItemModel *model){
    QStringList list_names;
    list_names<<"Emma"<<"Olivia"<<"Mery"<<"Mark"<<"Gary"<<"Brad"<<"Charltte"<<"Anabel"<<"Jane"<<"Tracy"<<"Jack"<<"Mike"<<"Top"<<"Sindy"<<
                "Emily"<<"Bella";
    root=model->invisibleRootItem();
    for(int i=start; i<end; i++){
        QStandardItem *ins_item=new QStandardItem(list_names[i]);
        ins_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        root->appendRow(ins_item);
    }
}

void FillDataPage::on_btn_join_leader_clicked()
{
    // As Choir Leader
    MainWindow *win=(MainWindow *)QApplication::activeWindow();
    win->getUi()->stackedWidget->insertWidget(2, new ChoirPage()); // This is added to reload the page, everything that was hidden is not hidden
    win->getUi()->stackedWidget->setCurrentIndex(2);
    win->getUi()->statusBar->show();

    win->getMic_img_choir()->show();

    // Tool bar
    QLabel *lbl_tool_bar=new QLabel("Demo - Choir Leader", this);
    lbl_tool_bar->setStyleSheet("font-family: Comic Sans MS;");
    win->getUi()->toolBar->addWidget(lbl_tool_bar);
    win->getUi()->toolBar->show();

    // Removing some wigets
    ChoirPage *choirpage=static_cast<ChoirPage *>(win->getUi()->stackedWidget->widget(2));
    choirpage->getUi()->groupBox_you->setHidden(true);
    choirpage->getUi()->groupBox_leader->setHidden(true);
    choirpage->getUi()->horizontalSpacer_2->changeSize(0, 0);
    choirpage->getUi()->horizontalSpacer_9->changeSize(0, 0);

    // Connecting the ListViews with the model and the delegate

    ChoirLeaderModel* model = new ChoirLeaderModel(this);
    ChoirLeaderModel* model_1 = new ChoirLeaderModel(this);
    ChoirLeaderModel* model_2 = new ChoirLeaderModel(this);
    ChoirLeaderModel* model_3 = new ChoirLeaderModel(this);

    choirpage->getUi()->listView_sopranos->setModel(model);
    choirpage->getUi()->listView_altos->setModel(model_1);
    choirpage->getUi()->listView_tenors->setModel(model_2);
    choirpage->getUi()->listView_basses->setModel(model_3);

    // Filling the models with static values/users
    model->appendUser(User("Charles", 0));
    model->appendUser(User("Lars", 0));
    model->appendUser(User("Boby", 0));

    model_1->appendUser(User("Jimmy", 0));
    model_1->appendUser(User("Amy", 0));
    model_1->appendUser(User("Emily", 0));
    model_1->appendUser(User("Bella", 0));

    model_2->appendUser(User("Justin", 0));
    model_2->appendUser(User("Calvin", 0));

    model_3->appendUser(User("Jon", 0));
    model_3->appendUser(User("Jerry", 0));
    model_3->appendUser(User("Zack", 0));
    model_3->appendUser(User("Brad", 0));
    model_3->appendUser(User("Jennifer", 0));
    model_3->appendUser(User("Kim", 0));
    model_3->appendUser(User("Demi", 0));

    Delegate* delegate = new Delegate(this);

    delegate->setContentsMargins(8, 8, 8, 8);
    delegate->setIconSize(15, 15);
    delegate->setHorizontalSpacing(8);
    delegate->setVerticalSpacing(4);

    choirpage->getUi()->listView_sopranos->setItemDelegate(delegate);
    choirpage->getUi()->listView_altos->setItemDelegate(delegate);
    choirpage->getUi()->listView_tenors->setItemDelegate(delegate);
    choirpage->getUi()->listView_basses->setItemDelegate(delegate);

    choirpage->getUi()->listView_sopranos->scrollToBottom();
}
