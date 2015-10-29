#ifndef ADDANEWTEACHER
#define ADDANEWTEACHER

#endif // ADDANEWTEACHER

#include <QtWidgets>
#include <QtSql>
class AddANewTeacher : public QFrame{
    Q_OBJECT
public slots:
    void submit();
public:
    AddANewTeacher();
private:
    void init();
    void setdepartment();
    QFormLayout* formlayout;
    QFrame* formwidget;
    QHBoxLayout* mainlayout;
    QLineEdit* teachernumberinput;
    QLineEdit* teachernameinput;
    QLineEdit* emailinput;
    QComboBox* departmentinput;
    QLineEdit* phoneinput;
    QPushButton* submitbutton;
};
