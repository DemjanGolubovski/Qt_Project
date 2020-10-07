#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

#include "loginpage.h"
#include "filldatapage.h"
#include "choirpage.h"
#include "customlabel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *getUi() const;
    void setUi(Ui::MainWindow *value);

    QLabel *getMic_img_choir() const;
    void setMic_img_choir(CustomLabel *value);

private slots:
    void exit_clicked();
    void mouse_pressed_img_me();
    void mouse_pressed_img_choir();

private:
    Ui::MainWindow *ui;
    LogInPage *log_in_page;
    FillDataPage *fill_data_page;
    ChoirPage *choir_page;
    CustomLabel *mic_img_choir;
    CustomLabel *mic_img_me;
    static int img_me_flag;
    static int img_choir_flag;
};
#endif // MAINWINDOW_H
