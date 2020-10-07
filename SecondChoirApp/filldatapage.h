#ifndef FILLDATAPAGE_H
#define FILLDATAPAGE_H

#include <QWidget>

namespace Ui {
class FillDataPage;
}

class FillDataPage : public QWidget
{
    Q_OBJECT

public:
    explicit FillDataPage(QWidget *parent = nullptr);
    ~FillDataPage();

    Ui::FillDataPage *getUi() const;
    void setUi(Ui::FillDataPage *value);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FillDataPage *ui;
};

#endif // FILLDATAPAGE_H
