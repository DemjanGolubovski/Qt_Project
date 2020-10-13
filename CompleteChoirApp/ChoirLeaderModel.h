#pragma once
#include <qabstractitemmodel.h>
#include "User.h"
class ChoirLeaderModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ChoirLeaderModel(QObject* parent = 0);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex& index) const;

    void appendUser(const User &u);
private:
    QList<User> active_users;
};

