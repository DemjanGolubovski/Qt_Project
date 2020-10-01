#include "delegate.h"

Delegate::Delegate(QObject *parent): QItemDelegate(parent)
{

}

QWidget * Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    // So ova se kreira editorot/delegate
    QSpinBox *editor=new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(20);
    return editor;
}
void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    // od view gi stavame promenite vo editorot/delegate
    int value=index.model()->data(index, Qt::EditRole).toInt();
    QSpinBox *sbox=static_cast<QSpinBox*>(editor);
    sbox->setValue(value);
}
void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const{
    // od editorot/delegate gi stavame podatocite vo modelot
    QSpinBox *sbox=static_cast<QSpinBox*>(editor);
    sbox->interpretText();
    int value=sbox->value();
    model->setData(index, value, Qt::EditRole);
}
void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    // ova se koristi za da se namesti ubavo da izgleda koga menuvame vred
    editor->setGeometry(option.rect);
}
