#include "mysqlrelationaltablemodel.h"


MySqlRelationalTableModel::MySqlRelationalTableModel(){

}
int MySqlRelationalTableModel::columnCount(const QModelIndex &) const
{
    return 20;
}
