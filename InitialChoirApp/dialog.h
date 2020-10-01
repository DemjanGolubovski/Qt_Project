#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFrame>
#include "seconddialog.h"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    SecondDialog *sec_dialog;
    User user;
};
#endif // DIALOG_H
