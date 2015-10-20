#include "studentpersonalwindowmenubutton.h"

void StudentPersonalWindowMenuButton::mousePressEvent(QMouseEvent * ev)
{
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
}
void StudentPersonalWindowMenuButton::mouseReleaseEvent(QMouseEvent * ev)
{
    setFrameStyle(QFrame::Panel | QFrame::Raised);
    emit clicked();
}
