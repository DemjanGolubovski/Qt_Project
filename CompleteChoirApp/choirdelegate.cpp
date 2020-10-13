#include "choirdelegate.h"
#include <QApplication>
#include <QPainter>
#include <QDebug>
#include <QStandardItemModel>

#include "filldatapage.h"
#include "ui_filldatapage.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

ChoirDelegate::ChoirDelegate(QObject *parent):
    QStyledItemDelegate(parent),
    margins(0, 0, 0, 0),
    spacingHorizontal(0),
    spacingVertical(0)
{

}

QMargins ChoirDelegate::contentsMargins() const
{
    return margins;
}

void ChoirDelegate::setContentsMargins(int left, int top, int right, int bottom)
{
    margins = QMargins(left, top, right, bottom);
}

int ChoirDelegate::horizontalSpacing() const
{
    return spacingHorizontal;
}

void ChoirDelegate::setHorizontalSpacing(int spacing)
{
    spacingHorizontal = spacing;
}

int ChoirDelegate::verticalSpacing() const
{
    return spacingVertical;
}

void ChoirDelegate::setVerticalSpacing(int spacing)
{
    spacingVertical = spacing;
}

void ChoirDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                     const QModelIndex &index) const
{
    QStyleOptionViewItem opt(option);
    initStyleOption(&opt, index);

    const QPalette &palette(opt.palette);
    const QRect &rect(opt.rect);
    const QRect &contentRect(rect.adjusted(margins.left(),
                                               margins.top(),
                                               margins.right(),
                                               margins.bottom()));
    QFont f(opt.font);

    f.setPointSize(fontPointSize(opt.font));

    painter->save();
    painter->setClipping(true);
    painter->setClipRect(rect);
    painter->setFont(opt.font);

    // Draw background
    painter->fillRect(rect, opt.state & QStyle::State_Selected ?
                          palette.highlight().color() :
                          palette.light().color());

    // Draw bottom line
    if ((index.row() + 1) % 3 == 0) {
        painter->setPen(palette.dark().color());
        painter->drawLine(rect.left()+5, rect.bottom(), rect.right()-5, rect.bottom());
    }

    // Draw message text
    QRect messageRect(messageBox(opt));

    messageRect.moveTo(margins.left() + 15
                       + spacingHorizontal-30, contentRect.top());

    painter->setFont(opt.font);
    painter->setPen(palette.windowText().color());
    painter->drawText(messageRect, Qt::TextSingleLine, opt.text);

    painter->restore();
}

QSize ChoirDelegate::sizeHint(const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    QStyleOptionViewItem opt(option);
    initStyleOption(&opt, index);

    int textHeight = textBox(opt, index).height()
            + spacingVertical + messageBox(opt).height();
    int iconHeight = 15;
    int h = textHeight > iconHeight ? textHeight : iconHeight;

    return QSize(opt.rect.width(), margins.top() + h
                 + margins.bottom());
}

void ChoirDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    const QRect &contentRect(option.rect.adjusted(margins.left(),
                                               margins.top(),
                                               margins.right(),
                                               margins.bottom()));
    editor->setGeometry(margins.left() + 50 + spacingHorizontal+55,contentRect.top(),45,5);
}

QRect ChoirDelegate::textBox(const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    QFont f(option.font);

    f.setPointSizeF(fontPointSize(option.font));

    return QFontMetrics(f).boundingRect(index.data(Qt::UserRole).toString())
            .adjusted(0, 0, 1, 1);
}

qreal ChoirDelegate::fontPointSize(const QFont &f) const
{
    return 0.85*f.pointSize();
}

QRect ChoirDelegate::messageBox(const QStyleOptionViewItem &option) const
{
    return option.fontMetrics.boundingRect(option.text).adjusted(0, 0, 1, 1);
}
