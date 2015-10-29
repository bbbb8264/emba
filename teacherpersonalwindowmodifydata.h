#ifndef TEACHERPERSONALWINDOWMODIFYDATA
#define TEACHERPERSONALWINDOWMODIFYDATA

#endif // TEACHERPERSONALWINDOWMODIFYDATA

#include <QtWidgets>
#include <QtSql>
class ChangePicture;
class TeacherPersonalWindowModiyfyData : public QFrame{
    Q_OBJECT
public:
    TeacherPersonalWindowModiyfyData(QString teachernumber);
    QWidget* buttonwidget;
    QPushButton* backbutton;
signals:
    /*void submitedpicture();
    void submitedname();
    void submitedgender();
    void submitedstudentidentity();*/
    void submitedsuccess();
public slots:
    void submitdata();
private:
    void init();
    void setInitialValue();
    QSqlQuery query;
    QMessageBox msg;
    QString teachernumber;
    QLabel* teachernumberlabel;
    QLineEdit* teachernamelabel;
    QComboBox* departmentlabel;
    QLineEdit* emaillabel;
    QLineEdit* phonelabel;
    QFormLayout* uplayout;
    QWidget* upwidget;
    QVBoxLayout* mainlayout;
    QPushButton* submitbutton;
    QHBoxLayout* buttonlayout;
};
