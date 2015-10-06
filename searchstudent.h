/*#ifndef SEARCHSTUDENT
#define SEARCHSTUDENT

#endif // SEARCHSTUDENT
#include <QtWidgets>
#include <QSqlRelationalTableModel>
struct conditionset;
class MySqlRelationalTableModel;
class ActionSqlRelationModel;
class StudentSelect : public QWidget
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
    MySqlRelationalTableModel* model;
    ActionSqlRelationModel* proxy;
    StudentSelect();
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
};*/
