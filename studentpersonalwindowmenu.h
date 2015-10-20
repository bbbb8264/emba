#ifndef STUDENTPERSONALWINDOWMENU
#define STUDENTPERSONALWINDOWMENU

#endif // STUDENTPERSONALWINDOWMENU

#include <QtWidgets>
class StudentPersonalWindowMenuButton;
class StudentPersonalWindowMenu : public QWidget{
public:
    StudentPersonalWindowMenu();
    StudentPersonalWindowMenuButton* browsestudentdatalabel;
    StudentPersonalWindowMenuButton* modifystudentdatalabel;
    StudentPersonalWindowMenuButton* browsecourserecordlabel;
    StudentPersonalWindowMenuButton* browsethesisrecordlabel;
    StudentPersonalWindowMenuButton* backlabel;
private:
    void init();
    void setlabelattribute(QLabel*);
    QFormLayout* mainlayout;
};
