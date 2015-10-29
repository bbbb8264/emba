#ifndef STUDENTPERSONALWINDOWMODIFYDATA
#define STUDENTPERSONALWINDOWMODIFYDATA

#endif // STUDENTPERSONALWINDOWMODIFYDATA

#include <QtWidgets>
#include <QtSql>
class ChangePicture;
class StudentPersonalWindowModiyfyData : public QFrame{
    Q_OBJECT
public:
    StudentPersonalWindowModiyfyData(QString studentnumber);
    QWidget* buttonwidget;
    QPushButton* backbutton;
signals:
    void submitedpicture();
    void submitedname();
    void submitedgender();
    void submitedstudentidentity();
public slots:
    void submitdata();
private:
    void init();
    void setTextEditSize(QLineEdit*);
    void setInitialValue();
    QSqlQuery query;
    QMessageBox msg;
    QString studentnumber;
    QFormLayout* formlayout1;
    QFormLayout* formlayout2;
    QFormLayout* formlayout3;
    QWidget* formwidget1;
    QWidget* formwidget2;
    QWidget* formwidget3;
    QHBoxLayout* uplayout;
    QWidget* upwidget;
    QVBoxLayout* mainlayout;
    QLabel* ticketnumberinput;
    QLabel* studentnumberinput;
    QLineEdit* locationinput;
    QLineEdit* studentidentityinput;
    QLabel* graduatelevel;
    QLineEdit* nameinput;
    ChangePicture* pictureinput;
    QGroupBox* gendergroup;
    QHBoxLayout* genderlayout;
    QRadioButton* malebutton;
    QRadioButton* femalebutton;
    QLineEdit* addressinput;
    QLineEdit* emailinput;
    QDateEdit* birthdayinput;
    QGroupBox* contactgroup;
    QFormLayout* contactlayout;
    QLineEdit* telephonedayinput;
    QLineEdit* telephonenightinput;
    QLineEdit* mobileinput;
    QLineEdit* graduateschoolinput;
    QLineEdit* graduatedepartmentinput;
    QGroupBox* companygroup;
    QFormLayout* companylayout;
    QLineEdit* companynameinput;
    QLineEdit* companypositioninput;
    QGroupBox* creditgroup;
    QHBoxLayout* creditlayout;
    QRadioButton* credityes;
    QRadioButton* creditno;
    QHBoxLayout* buttonlayout;
    QPushButton* submitbutton;
    QVBoxLayout* picturelayout;
    QWidget* picturewidget;
    QLabel* graduatelevelerror;
    bool graduatelevelerrorinserted = false;
};
