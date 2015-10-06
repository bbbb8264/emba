#include "deletebutton.h"

DeleteButton::DeleteButton(conditionset* parent)
{
    this->parent = parent;
    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::red);
    setText("X");
    setPalette(palette);
    setFrameShape(QFrame::Panel);
    setFrameShadow(QFrame::Plain);
    setAlignment(Qt::AlignCenter);
    setMinimumHeight(25);
    setMinimumWidth(25);
    setMaximumHeight(40);
    setMaximumWidth(30);
}
void DeleteButton::mousePressEvent(QMouseEvent * ev)
{
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
}
void DeleteButton::mouseReleaseEvent(QMouseEvent * ev)
{
    setFrameStyle(QFrame::Panel | QFrame::Raised);
    emit click(parent);
}
