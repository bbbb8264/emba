#ifndef ATEACHERINFORMATION
#define ATEACHERINFORMATION

#endif // ATEACHERINFORMATION

#include <QtWidgets>
#include <QtSql>

class ATeacherInformation : public QFrame{
    Q_OBJECT
public:
    ATeacherInformation();
private:
    init();
    bool openinner = false;

};
