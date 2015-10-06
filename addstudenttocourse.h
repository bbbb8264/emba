#ifndef ADDSTUDENTTOCOURSE
#define ADDSTUDENTTOCOURSE

#endif // ADDSTUDENTTOCOURSE

#include <QtWidgets>
struct conditionset;
class ChooseStudentToCourseCourseModel;
class CheckBoxIdentityModel;
class AddStudentToCourse : public QWidget
{
    Q_OBJECT
public slots:
    void addacondition();
    void deleteacondition(conditionset*& con);
private:
    void addtolinkedlist(conditionset* temp);
    void addatlast(conditionset* temp);
    bool addatmiddle(conditionset* temp);
    void init();
    void setfont();
    void setcondition(conditionset*);
    void scanconditionset();
    void makefilter(conditionset* temp);
    bool makecondition(conditionset*& temp);
    QString maketotalfilter();
public:
    QStringList conditions;
    QString filter;
    ChooseStudentToCourseCourseModel* model;
    CheckBoxIdentityModel* proxy;
    AddStudentToCourse();
    QHBoxLayout* mainlayout;
    QFrame* conditionwidget;
    QVBoxLayout* conditionlayout;
    QFrame* conditionsettingwidget;
    QHBoxLayout* conditionsettinglayout;
    QComboBox* conditionsetting;
    QLineEdit* conditionsettingexpression;
    QFrame* conditionshowwidget;
    QVBoxLayout* conditionshowlayout;
    conditionset* conditionlast;
    QWidget* resultwidget;
    QVBoxLayout* resultlayout;
    QWidget* resultaddwidget;
    QHBoxLayout* resultaddlayout;
    QWidget* resultshowwidget;
    QPushButton* submitbutton;
    QHBoxLayout* controlllayout;
    QWidget* controllwidget;
};
