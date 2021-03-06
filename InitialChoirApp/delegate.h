#ifndef DELEGATE_H
#define DELEGATE_H

#include <QStyledItemDelegate>
#include "user.h"

class Delegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit Delegate(User u,QObject *parent = nullptr);

    QSize iconSize() const;
    void setIconSize(int width, int height);

    QMargins contentsMargins() const;
    void setContentsMargins(int left, int top, int right, int bottom);

    int horizontalSpacing() const;
    void setHorizontalSpacing(int spacing);

    int verticalSpacing() const;
    void setVerticalSpacing(int spacing);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;

    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    inline QRect timestampBox(const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;
    inline qreal timestampFontPointSize(const QFont &f) const;
    inline QRect messageBox(const QStyleOptionViewItem &option) const;

private:
    QSize iconsize;
    QMargins margins;
    int spacingHorizontal;
    int spacingVertical;
    User user;
};

#endif // DELEGATE_H
