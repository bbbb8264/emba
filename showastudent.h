#ifndef SHOWASTUDENT
#define SHOWASTUDENT

#endif // SHOWASTUDENT

#include <QtWidgets>
#include <QtSql>
class ShowAStudent : public QFrame
{
public:
    ShowAStudent(QString);
private:
    void init();
    void setpicture();
    void setquery();
    QSqlQuery query;
    QString studentnumber;
    QHBoxLayout* mainlayout;
    QWidget* studentbasicdatawidget;
    QVBoxLayout* studentbasicdatalayout;
    QWidget* basicinformationwidget;
    QVBoxLayout* basicinformationlayout;
    QWidget* informationwidget;
    QVBoxLayout* informationlayout;
    QLabel* picturelabel;
    QImage img;
    QLabel* studentnumberlabel;
    QLabel* namelabel;
    QLabel* gradelabel;
    QLabel* departmentlabel;
};
