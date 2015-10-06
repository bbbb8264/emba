#ifndef ACTIONSQLRELATIONMODEL
#define ACTIONSQLRELATIONMODEL

#endif // ACTIONSQLRELATIONMODEL

#include <QtWidgets>
#include <QtSql>

class CheckBoxIdentityModel : public QIdentityProxyModel
{
    Q_OBJECT
private:
    Qt::CheckState* checkstate;
    int checkboxposition;
public:
    CheckBoxIdentityModel(int);
  //  int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex & index) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole) Q_DECL_OVERRIDE;
    void resetcheckstate(int rowCount);
public slots:
    void setcheck(const QModelIndex & index);
};
