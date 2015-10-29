#ifndef ADDSTUDENTTOCOURSE
#define ADDSTUDENTTOCOURSE

#endif // ADDSTUDENTTOCOURSE

#include <QtWidgets>
#include <QtSql>
struct conditionset;
class SelectStudentSqlQueryModel;
class CheckBoxIdentityModel;
class SearchTeacher : public QWidget
{
    Q_OBJECT
public slots:
    void addacondition();
    void deleteacondition(conditionset*& con);
signals:
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
    QStringList conditions;
    QString filter;
    QSqlQueryModel* model;
    SearchTeacher();
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
};
