#ifndef MYSQLRELATIONALTABLEMODEL
#define MYSQLRELATIONALTABLEMODEL

#endif // MYSQLRELATIONALTABLEMODEL

#include <QtWidgets>
#include <QtSql>
class MySqlRelationalTableModel : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    MySqlRelationalTableModel();
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    //QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
};
