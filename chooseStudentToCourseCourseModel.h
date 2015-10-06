#ifndef SQLQUERYMODEL
#define SQLQUERYMODEL

#endif // SQLQUERYMODEL
#include <QtWidgets>
#include <QSql>
#include <QSqlQueryModel>
class ChooseStudentToCourseCourseModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
};
