#include "personalwindowmenubutton.h"

void PersonalWindowMenuButton::mousePressEvent(QMouseEvent * ev)
{
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
}
void PersonalWindowMenuButton::mouseReleaseEvent(QMouseEvent * ev)
{
    setFrameStyle(QFrame::Panel | QFrame::Raised);
    emit clicked();
}
