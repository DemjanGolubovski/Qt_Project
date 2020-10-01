#include "delegate.h"
#include <QApplication>
#include <QPainter>
#include <QStandardItemModel>

Delegate::Delegate(User u,QObject *parent) :
    QStyledItemDelegate(parent),
    iconsize(16, 16),
    margins(0, 0, 0, 0),
    spacingHorizontal(0),
    spacingVertical(0),
    user(u)
{

}

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

    // Draw background
    painter->fillRect(rect, opt.state & QStyle::State_Selected ?
                          palette.highlight().color() :
                          palette.light().color());

    // Draw bottom line
    painter->setPen(lastIndex ? palette.dark().color()
                              : palette.mid().color());
    painter->drawLine(lastIndex ? rect.left() : margins.left(),
                      bottomEdge, rect.right(), bottomEdge);

    // Draw message icon
    if (hasIcon)
        painter->drawPixmap(margins.left() + iconsize.width()
                            + spacingHorizontal+60, contentRect.top()-2,
                            opt.icon.pixmap(iconsize));

//    // Draw timestamp
//    QRect timeStampRect(timestampBox(opt, index));

//    timeStampRect.moveTo(margins.left() + iconsize.width()
//                         + spacingHorizontal, contentRect.top());

//    painter->setFont(f);
//    painter->setPen(palette.text().color());
//    painter->drawText(timeStampRect, Qt::TextSingleLine,
//                      index.data(Qt::UserRole).toString());

    int value=index.data().toInt();

    // Draw message text
    QRect messageRect(messageBox(opt));

    messageRect.moveTo(margins.left() + iconsize.width()
                       + spacingHorizontal-30, contentRect.top());

    painter->setFont(opt.font);
    painter->setPen(palette.windowText().color());
    painter->drawText(messageRect, Qt::TextSingleLine, user.getName());

    painter->restore();

    QRect r=option.rect;


    int x,y,w,h;
//    x = r.left() + r.width()-55;//the X coordinate
//    y = r.top()+20;//the Y coordinate
    w = 50;//button width
    h = 10;//button height

    QStyleOptionSlider slider;
    slider.rect=QRect(margins.left() + w + spacingHorizontal+55,contentRect.top()+3,w,h);
    slider.minimum=0;
    slider.maximum=20;
    slider.sliderValue=value;
    slider.sliderPosition=value;

    QApplication::style()->drawComplexControl(QStyle::CC_Slider, &slider, painter);

    QStyleOptionProgressBar bar;
    bar.rect=QRect(margins.left() + iconsize.width()
                   + spacingHorizontal+60,contentRect.top()+15,w+30,7);
    bar.minimum=0;
    bar.maximum=20;
    bar.progress=10;
    QApplication::style()->drawControl(QStyle::CE_ProgressBar, &bar, painter);


    // My Code
//        QStyleOptionButton button;
//        QRect r = option.rect;//getting the rect of the cell
//        int x,y,w,h;
//        x = messageRect.right() + horizontalSpacing();
//        y = messageRect.y() - 15;
//        w = 30;//button width
//        h = 30;//button height
//        button.rect = QRect(x,y,w,h);
//        button.text = "=^.^=";
//        button.state = QStyle::State_Enabled;

//        QApplication::style()->drawControl( QStyle::CE_PushButton, &button, painter);

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
    QSlider *slider=new QSlider(parent);
    slider->setMinimum(0);
    slider->setMaximum(20);
    slider->setOrientation(Qt::Horizontal);
    slider->setAutoFillBackground(true);

    return slider;
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QSlider *slider=static_cast<QSlider *>(editor);
    slider->setValue(index.data().toInt());
}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSlider *slider=static_cast<QSlider *>(editor);
    model->setData(index, slider->value());
}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    const QRect &contentRect(option.rect.adjusted(margins.left(),
                                               margins.top(),
                                               margins.right(),
                                               margins.bottom()));
    editor->setGeometry(margins.left() + 50 + spacingHorizontal+55,contentRect.top()+3,50,10);
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
    return option.fontMetrics.boundingRect(user.getName()).adjusted(0, 0, 1, 1);
}
