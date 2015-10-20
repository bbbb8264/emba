#ifndef STUDENTPERSONALWINDOWMENUBUTTON
#define STUDENTPERSONALWINDOWMENUBUTTON

#endif // STUDENTPERSONALWINDOWMENUBUTTON

#include <QtWidgets>
class StudentPersonalWindowMenuButton : public QLabel{
    Q_OBJECT
    void mousePressEvent(QMouseEvent * ev) override;
    void mouseReleaseEvent(QMouseEvent * ev) override;
public:
signals:
    void clicked();
};
