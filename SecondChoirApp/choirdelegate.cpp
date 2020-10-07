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
//    iconsize(16, 16),
    margins(0, 0, 0, 0),
    spacingHorizontal(0),
    spacingVertical(0)
{

}
int ChoirDelegate::num_users=0;

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
    const bool lastIndex = (index.model()->rowCount() - 1) == index.row();
    const bool hasIcon = !opt.icon.isNull();
    const int bottomEdge = rect.bottom();
    QFont f(opt.font);

    f.setPointSize(timestampFontPointSize(opt.font));

    painter->save();
    painter->setClipping(true);
    painter->setClipRect(rect);
    painter->setFont(opt.font);

    MainWindow *win=(MainWindow *)QApplication::activeWindow();
    FillDataPage *fill_data_page=static_cast<FillDataPage *>(win->getUi()->stackedWidget->widget(1));


    // Draw background
    painter->fillRect(rect, opt.state & QStyle::State_Selected ?
                          palette.highlight().color() :
                          palette.light().color());

    // Draw bottom line - Not working properly
    // If the number of times the paint event has been called is greater than the number of users then the counter needs to restart so it can
    // draw the bottom line in the proper place
//    if(num_users>3){
//        num_users=0;
//    }
//    num_users++;
//    // Causing some problems with the positioning of the line
//    if(num_users%3==0){
//    painter->setPen(lastIndex ? palette.dark().color()
//                              : palette.mid().color());
//    painter->drawLine(lastIndex ? rect.left() : margins.left(),
//                      bottomEdge, rect.right(), bottomEdge);
//    }

//    // Draw message icon
//    if (hasIcon)
//        painter->drawPixmap(margins.left() + iconsize.width()
//                            + spacingHorizontal+60, contentRect.top()-2,
//                            opt.icon.pixmap(iconsize));

//    int value=index.data().toInt();

    // Draw message text
    QRect messageRect(messageBox(opt));

    messageRect.moveTo(margins.left() + 15
                       + spacingHorizontal-30, contentRect.top());

    painter->setFont(opt.font);
    painter->setPen(palette.windowText().color());
    painter->drawText(messageRect, Qt::TextSingleLine, fill_data_page->getUi()->lblName->text());

    painter->restore();
}

QSize ChoirDelegate::sizeHint(const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    QStyleOptionViewItem opt(option);
    initStyleOption(&opt, index);

    int textHeight = timestampBox(opt, index).height()
            + spacingVertical + messageBox(opt).height();
    int iconHeight = 15;
    int h = textHeight > iconHeight ? textHeight : iconHeight;

    return QSize(opt.rect.width(), margins.top() + h
                 + margins.bottom());
}

void ChoirDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    num_users=0;
    const QRect &contentRect(option.rect.adjusted(margins.left(),
                                               margins.top(),
                                               margins.right(),
                                               margins.bottom()));
    editor->setGeometry(margins.left() + 50 + spacingHorizontal+55,contentRect.top(),45,5);
}

QRect ChoirDelegate::timestampBox(const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    QFont f(option.font);

    f.setPointSizeF(timestampFontPointSize(option.font));

    return QFontMetrics(f).boundingRect(index.data(Qt::UserRole).toString())
            .adjusted(0, 0, 1, 1);
}

qreal ChoirDelegate::timestampFontPointSize(const QFont &f) const
{
    return 0.85*f.pointSize();
}

QRect ChoirDelegate::messageBox(const QStyleOptionViewItem &option) const
{
    MainWindow *win=(MainWindow *)QApplication::activeWindow();
    FillDataPage *fill_data_page=static_cast<FillDataPage *>(win->getUi()->stackedWidget->widget(1));

    return option.fontMetrics.boundingRect(fill_data_page->getUi()->lblName->text()).adjusted(0, 0, 1, 1);
}
