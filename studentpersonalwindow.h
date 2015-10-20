#ifndef STUDENTPERSONALWINDOW
#define STUDENTPERSONALWINDOW

#endif // STUDENTPERSONALWINDOW

#include <QtWidgets>
#include <QtSql>
class StudentPersonalWindowMenu;
class StudentPersonalWindowBrowseData;
class StudentPersonalWindowModiyfyData;
class StudentPersonalWindowCourseData;
class StudentPersonalWindow : public QFrame
{
    Q_OBJECT
public slots:
    void openbrowsedatawidget();
    void closebrowsedatawidget();
    void openmodifydatawidget();
    void closemodifydatawidget();
    void openbrowsecourserecordwidget();
    void closebrowsecourserecordwidget();
    void refreshpicture();
    void refreshname();
    void refreshgender();
    void refreshstudentidentity();
public:
    StudentPersonalWindow(QString);
    StudentPersonalWindowMenu* controllmenu;
private:
    void init();
    void setlabelinformation();
    QSqlQuery query;
    QImage img;
    QLabel* studentnumberlabel;
    QString studentnumber;
    QLabel* ticketnumberlabel;
    QLabel* levellabel;
    QLabel* genderlabel;
    QLabel* namelabel;
    QLabel* picturelabel;
    QLabel* studentidentitylabel;
    QHBoxLayout* mainlayout;
    QVBoxLayout* basicinformationlayout;
    QFrame* basicinformationwidget;
    QFormLayout* basicinformationformlayout;
    QWidget* basicinformationformwidget;
    bool isBrowseDataWidgetOpened = false;
    StudentPersonalWindowBrowseData* browsedatawidget;
    StudentPersonalWindowModiyfyData* modifydatawidget;
    StudentPersonalWindowCourseData* coursedatawidget;
};
