#ifndef CHOIRDELEGATE_H
#define CHOIRDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>

class ChoirDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ChoirDelegate(QObject *parent = nullptr);

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

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    inline QRect timestampBox(const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;
    inline qreal timestampFontPointSize(const QFont &f) const;
    inline QRect messageBox(const QStyleOptionViewItem &option) const;

private:
    QMargins margins;
    int spacingHorizontal;
    int spacingVertical;
    static int num_users;
};

#endif // CHOIRDELEGATE_H
