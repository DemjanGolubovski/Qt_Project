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
    ui->img_microphone->setPixmap(ins_img.scaled(25, 25, Qt::KeepAspectRatio));

    ins_img.load(":/Images/Images/headphones.png");
    ui->img_headphones->setPixmap(ins_img.scaled(25, 25, Qt::KeepAspectRatio));

    ins_img.load(":/Images/Images/speaker.png");
    ui->img_headphones_volume->setPixmap(ins_img.scaled(20, 20, Qt::KeepAspectRatio));
    ui->img_session_volume->setPixmap(ins_img.scaled(20, 20, Qt::KeepAspectRatio));
    ui->img_microphone_volume->setPixmap(ins_img.scaled(20, 20, Qt::KeepAspectRatio));

    // Adjusting sizes of widgets
    ui->progressBar_microphone->setFixedHeight(7);
    ui->horizontalSlider_session->setFixedHeight(15);
    ui->horizontalSlider_microphone->setFixedHeight(15);
    ui->horizontalSlider_headphones->setFixedHeight(15);

    // Adding some static values
    ui->lbl_num_members->setText("16");
    ui->txt_leader_name->setText("Demo Leader");
    ui->txt_leader_name->setReadOnly(true);
    ui->lbl_choir_leader->setText("Demo Leader");

    ui->comboBox_section->addItem("Sopranos");
    ui->comboBox_section->addItem("Altos");
    ui->comboBox_section->addItem("Tenors");
    ui->comboBox_section->addItem("Basses");

    // Add values to the comboBox widgets
    // Audio inputs in the OS
    const auto deviceInfos_input = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    int list_size = 0;
    for (const QAudioDeviceInfo& deviceInfo : deviceInfos_input) {
        ui->comboBox_audio_inputs->addItem(deviceInfo.deviceName());
        list_size++;
        if (list_size == deviceInfos_input.size() / 2)
            break;
    }

    // Audio outputs in the OS
    const auto deviceInfos_output = QAudioDeviceInfo::availableDevices(QAudio::AudioOutput);
    list_size = 0;
    for (const QAudioDeviceInfo& deviceInfo : deviceInfos_output) {
        ui->comboBox_audio_output->addItem(deviceInfo.deviceName());
        list_size++;
        if (list_size == deviceInfos_output.size() / 2)
            break;
    }
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
