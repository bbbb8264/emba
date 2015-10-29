#ifndef TEACHERPERSONALWINDOWMENU
#define TEACHERPERSONALWINDOWMENU

#endif // TEACHERPERSONALWINDOWMENU

#include <QtWidgets>
class PersonalWindowMenuButton;
class TeacherPersonalWindowMenu : public QWidget{
public:
    TeacherPersonalWindowMenu();
    PersonalWindowMenuButton* modifyteacherdatalabel;
    PersonalWindowMenuButton* browsecourserecordlabel;
    PersonalWindowMenuButton* browsethesisrecordlabel;
    PersonalWindowMenuButton* backlabel;
private:
    void init();
    void setlabelattribute(QLabel*);
    QFormLayout* mainlayout;
};
