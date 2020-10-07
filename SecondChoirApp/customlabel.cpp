#include "customlabel.h"

CustomLabel::CustomLabel(QWidget *parent) : QLabel(parent)
{

}

void CustomLabel::mousePressEvent(QMouseEvent *ev)
{
    emit Mouse_Pressed();
}
