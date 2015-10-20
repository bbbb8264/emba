#ifndef SELECTSTUDENTSQLQUERYMODEL
#define SELECTSTUDENTSQLQUERYMODEL

#endif // SELECTSTUDENTSQLQUERYMODEL

#include <QtWidgets>
#include <QSql>
#include <QSqlQueryModel>
class SelectStudentSqlQueryModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
};
