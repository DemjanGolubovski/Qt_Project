#include "delegate.h"
#include <QApplication>
#include <QPainter>
#include <QDebug>
#include <QStandardItemModel>

#include "filldatapage.h"
#include "ui_filldatapage.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

Delegate::Delegate(QObject *parent) :
    QStyledItemDelegate(parent),
    iconsize(16, 16),
    margins(0, 0, 0, 0),
    spacingHorizontal(0),
    spacingVertical(0)
{

}
int Delegate::num_users=0;

QSize Delegate::iconSize() const
{
    return iconsize;
}

void Delegate::setIconSize(int width, int height)
{
    iconsize = QSize(width, height);
}

QMargins Delegate::contentsMargins() const
{
    return margins;
}

void Delegate::setContentsMargins(int left, int top, int right, int bottom)
{
    margins = QMargins(left, top, right, bottom);
}

int Delegate::horizontalSpacing() const
{
    return spacingHorizontal;
}

void Delegate::setHorizontalSpacing(int spacing)
{
    spacingHorizontal = spacing;
}

int Delegate::verticalSpacing() const
{
    return spacingVertical;
}

void Delegate::setVerticalSpacing(int spacing)
{
    spacingVertical = spacing;
}

void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
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

    // Draw message icon
    if (hasIcon)
        painter->drawPixmap(margins.left() + iconsize.width()
                            + spacingHorizontal+60, contentRect.top()-2,
                            opt.icon.pixmap(iconsize));

    int value=index.data().toInt();

    // Draw message text
    QRect messageRect(messageBox(opt));

    messageRect.moveTo(margins.left() + iconsize.width()
                       + spacingHorizontal-30, contentRect.top());

    painter->setFont(opt.font);
    painter->setPen(palette.windowText().color());
    painter->drawText(messageRect, Qt::TextSingleLine, fill_data_page->getUi()->lblName->text());

    painter->restore();

    // Draw slider
    painter->drawPixmap(margins.left() + 50 + spacingHorizontal+55,contentRect.top()+5,45,2,QPixmap(":/Images/Images/groove.png"));
    painter->drawPixmap(margins.left() + 50 + spacingHorizontal+55+value/3,contentRect.top()-4, 20, 20, QPixmap(":/Images/Images/handle.png"));

    int w = 50, h = 10;

    // Draw progress bar
    QStyleOptionProgressBar bar;
    bar.rect=QRect(margins.left() + iconsize.width()
                   + spacingHorizontal+60,contentRect.top()+15,w+30,7);
    bar.minimum=0;
    bar.maximum=20;
    bar.progress=10;
    QApplication::style()->drawControl(QStyle::CE_ProgressBar, &bar, painter);
}

QSize Delegate::sizeHint(const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    QStyleOptionViewItem opt(option);
    initStyleOption(&opt, index);

    int textHeight = timestampBox(opt, index).height()
            + spacingVertical + messageBox(opt).height();
    int iconHeight = iconsize.height();
    int h = textHeight > iconHeight ? textHeight : iconHeight;

    return QSize(opt.rect.width(), margins.top() + h
                 + margins.bottom());
}

QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    num_users=0;
    QSlider *slider=new QSlider(parent);
    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setOrientation(Qt::Horizontal);
    slider->setAutoFillBackground(true);

    slider->setStyleSheet("QSlider::groove:horizontal {"
                          "border: 0px;"
                          "background-color: rgb(48, 48, 48);"
                          "height: 2px;"
                          "margin: 0px;"
                          "}"
                      "QSlider::handle:horizontal { "
                          "image: url(:/Images/Images/handle.png);"
                          "border: 0px;"
                          "height: 20px;"
                          "width: 20px;"
                          "margin: -10px 0px;"
                      "}");
    slider->setFixedHeight(12);
    return slider;
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    num_users=0;
    QSlider *slider=static_cast<QSlider *>(editor);
    slider->setValue(index.data().toInt());
}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    num_users=0;
    QSlider *slider=static_cast<QSlider *>(editor);
    model->setData(index, slider->value());
}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    num_users=0;
    const QRect &contentRect(option.rect.adjusted(margins.left(),
                                               margins.top(),
                                               margins.right(),
                                               margins.bottom()));
    editor->setGeometry(margins.left() + 50 + spacingHorizontal+55,contentRect.top(),45,5);
}

QRect Delegate::timestampBox(const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    QFont f(option.font);

    f.setPointSizeF(timestampFontPointSize(option.font));

    return QFontMetrics(f).boundingRect(index.data(Qt::UserRole).toString())
            .adjusted(0, 0, 1, 1);
}

qreal Delegate::timestampFontPointSize(const QFont &f) const
{
    return 0.85*f.pointSize();
}

QRect Delegate::messageBox(const QStyleOptionViewItem &option) const
{
    MainWindow *win=(MainWindow *)QApplication::activeWindow();
    FillDataPage *fill_data_page=static_cast<FillDataPage *>(win->getUi()->stackedWidget->widget(1));

    return option.fontMetrics.boundingRect(fill_data_page->getUi()->lblName->text()).adjusted(0, 0, 1, 1);
}
