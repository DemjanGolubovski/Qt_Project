#ifndef FILLDATAPAGE_H
#define FILLDATAPAGE_H

#include <QWidget>
#include <QAudioDeviceInfo>
#include <QStandardItemModel>
#include <QStandardItem>
#include <qdatetime.h>

#include "User.h"

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

    void static_fill_listviews(int start, int end, QStandardItem *root, QStandardItemModel *model);

private slots:
    void on_btn_join_member_clicked();

    void on_btn_join_leader_clicked();

private:
    Ui::FillDataPage *ui;
};

#endif // FILLDATAPAGE_H
