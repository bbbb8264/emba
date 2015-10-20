#ifndef ADDSTUDENTTOCOURSE
#define ADDSTUDENTTOCOURSE

#endif // ADDSTUDENTTOCOURSE

#include <QtWidgets>
struct conditionset;
class SelectStudentSqlQueryModel;
class CheckBoxIdentityModel;
class SelectStudent : public QWidget
{
    Q_OBJECT
public slots:
    void addacondition();
    void deleteacondition(conditionset*& con);
    void finish();
    void uncheckall();
    void selectall();
signals:
    void cleanPrevious();
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
    QMessageBox msg;
    QStringList coursenumberlist;
    QStringList coursenamelist;
    QStringList conditions;
    QString filter;
    SelectStudentSqlQueryModel* model;
    CheckBoxIdentityModel* proxy;
    SelectStudent(QStringList,QStringList);
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
    QTableView* tableview;
    QWidget* resultwidget;
    QVBoxLayout* resultlayout;
    QWidget* resultaddwidget;
    QHBoxLayout* resultaddlayout;
    QWidget* resultshowwidget;
    QPushButton* previousbutton;
    QPushButton* submitbutton;
    QPushButton* selectallbutton;
    QPushButton* uncheckallbutton;
    QHBoxLayout* controlllayout;
    QWidget* controllwidget;
};
