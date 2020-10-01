#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H

#include <QDialog>
#include "user.h"

namespace Ui {
class ThirdDialog;
}

class ThirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdDialog(User u, QWidget *parent = nullptr);
    ~ThirdDialog();

    User getUser() const;
    void setUser(const User &value);

private:
    Ui::ThirdDialog *ui;
    User user;
};

#endif // THIRDDIALOG_H
