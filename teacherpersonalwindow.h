#ifndef TEACHERPERSONALWINDOW
#define TEACHERPERSONALWINDOW

#endif // TEACHERPERSONALWINDOW

#include <QtWidgets>
#include <QtSql>
class TeacherPersonalWindowMenu;
class TeacherPersonalWindowModiyfyData;
class TeacherPersonalWindowCourseData;
class TeacherPersonalWindow : public QFrame
{
    Q_OBJECT
public slots:
    void openmodifydatawidget();
    void closemodifydatawidget();
    void openbrowsecourserecordwidget();
    void closebrowsecourserecordwidget();
    void refreshbasicinformation();
public:
    TeacherPersonalWindow(QString);
    TeacherPersonalWindowMenu* controllmenu;
private:
    void init();
    void setlabelinformation();
    QSqlQuery query;
    QLabel* teachernumberlabel;
    QString teachernumber;
    QLabel* emaillabel;
    QLabel* phonelabel;
    QLabel* namelabel;
    QLabel* departmentnumberlabel;
    QLabel* departmentnamelabel;
    QHBoxLayout* mainlayout;
    QVBoxLayout* basicinformationlayout;
    QFrame* basicinformationwidget;
    QFormLayout* basicinformationformlayout;
    QWidget* basicinformationformwidget;
    bool isBrowseDataWidgetOpened = false;
    TeacherPersonalWindowModiyfyData* modifydatawidget;
    TeacherPersonalWindowCourseData* coursedatawidget;
};
