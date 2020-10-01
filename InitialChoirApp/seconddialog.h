#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include <QDialog>
#include <QDebug>
#include "user.h"
#include "thirddialog.h"

namespace Ui {
class SecondDialog;
}

class SecondDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecondDialog(User u, QWidget *parent = nullptr);
    ~SecondDialog();

    User getUser() const;
    void setUser(User value);

private slots:
    void on_pushButton_clicked();

private:
    Ui::SecondDialog *ui;
    User user;
    ThirdDialog *third_dial;
};

#endif // SECONDDIALOG_H
