#ifndef STUDENTPERSONALWINDOWBROWSEDATA
#define STUDENTPERSONALWINDOWBROWSEDATA

#endif // STUDENTPERSONALWINDOWBROWSEDATA

#include <QtWidgets>
#include <QtSql>
class StudentPersonalWindowBrowseData : public QFrame
{
public:
    StudentPersonalWindowBrowseData(QString);
    QPushButton* backbutton;
    void setlabelinformation();
private:
    void init();
    QString studentnumber;
    QSqlQuery query;
    QLabel* locationlabel;
    QLabel* addresslabel;
    QLabel* emaillabel;
    QLabel* birthdaylabel;
    QLabel* telephonedaylabel;
    QLabel* telephonenightlabel;
    QLabel* mobilelabel;
    QLabel* graduatedschoollabel;
    QLabel* graduateddepartmentlabel;
    QLabel* companynamelabel;
    QLabel* companycurrentpositionlabel;
    QVBoxLayout* mainlayout;
    QHBoxLayout* uplayout;
    QWidget* upwidget;
    QFormLayout* formlayout1;
    QWidget* formwidget1;
    QFormLayout* formlayout2;
    QWidget* formwidget2;
};
