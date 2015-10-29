#ifndef STUDENTPERSONALWINDOWMENU
#define STUDENTPERSONALWINDOWMENU

#endif // STUDENTPERSONALWINDOWMENU

#include <QtWidgets>
class PersonalWindowMenuButton;
class StudentPersonalWindowMenu : public QWidget{
public:
    StudentPersonalWindowMenu();
    PersonalWindowMenuButton* browsestudentdatalabel;
    PersonalWindowMenuButton* modifystudentdatalabel;
    PersonalWindowMenuButton* browsecourserecordlabel;
    PersonalWindowMenuButton* browsethesisrecordlabel;
    PersonalWindowMenuButton* backlabel;
private:
    void init();
    void setlabelattribute(QLabel*);
    QFormLayout* mainlayout;
};
