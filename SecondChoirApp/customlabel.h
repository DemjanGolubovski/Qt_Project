#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QObject>
#include <QLabel>
#include <QEvent>
#include <QMouseEvent>

class CustomLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CustomLabel(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *ev) override;
signals:
    void Mouse_Pressed();
};

#endif // CUSTOMLABEL_H
