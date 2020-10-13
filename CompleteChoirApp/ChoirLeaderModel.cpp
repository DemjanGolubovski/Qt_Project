#include "ChoirLeaderModel.h"
#include <qdebug.h>
ChoirLeaderModel::ChoirLeaderModel(QObject* parent) : QAbstractListModel(parent)
{

}

int ChoirLeaderModel::rowCount(const QModelIndex& parent) const
{
    return active_users.size();
}

QVariant ChoirLeaderModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        QStringList return_user;
        return_user << active_users[index.row()].getUsername();
        return_user << QString::number(active_users[index.row()].getVolumeValue());
        return return_user;
    }
    return QVariant();
}

void ChoirLeaderModel::appendUser(const User& u)
{
    active_users.append(u);
}

bool ChoirLeaderModel::setData(const QModelIndex& index, const QVariant& value, int role) 
{
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();
        User *update_user = &active_users[row]; 
        update_user->setUsername(value.toStringList()[0]);
        update_user->setVolumeValue(value.toStringList()[1].toInt());
        active_users.replace(row, *update_user);
        emit(dataChanged(index, index));
        return true;
    }
    return false;
}

Qt::ItemFlags ChoirLeaderModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::ItemIsSelectable;
    else
        return Qt::ItemIsEditable | Qt::ItemIsEnabled; //Qt::ItemIsSelectable
}