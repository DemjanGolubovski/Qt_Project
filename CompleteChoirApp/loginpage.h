#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QDebug>


namespace Ui {
class LogInPage;
}

class LogInPage : public QWidget
{
    Q_OBJECT

public:
    explicit LogInPage(QWidget *parent = nullptr);
    ~LogInPage();

private slots:
    void on_btn_start_leader_clicked();

    void on_btn_start_member_clicked();

private:
    Ui::LogInPage *ui;
};

#endif // LOGINPAGE_H
