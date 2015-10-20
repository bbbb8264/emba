#ifndef STUDENTPERSONALWINDOWCOURSEDATA
#define STUDENTPERSONALWINDOWCOURSEDATA

#endif // STUDENTPERSONALWINDOWCOURSEDATA

#include <QtWidgets>
#include <QtSql>

class StudentPersonalWindowCourseData : public QFrame{
public:
    StudentPersonalWindowCourseData(QString);
    QPushButton* backbutton;
private:
    void init();
    QString studentnumber;
    QSqlQuery query;
    QVBoxLayout* mainlayout;
};
