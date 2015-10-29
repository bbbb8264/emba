#ifndef TEACHERPERSONALCOURSEDATA
#define TEACHERPERSONALCOURSEDATA

#endif // TEACHERPERSONALCOURSEDATA

#include <QtWidgets>
#include <QtSql>

class TeacherPersonalWindowCourseData : public QFrame{
public:
    TeacherPersonalWindowCourseData(QString);
    QPushButton* backbutton;
private:
    void init();
    QString teachernumber;
    QSqlQuery query;
    QVBoxLayout* mainlayout;
};
