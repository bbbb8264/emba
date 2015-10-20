#include "checkboxidentitymodel.h"

CheckBoxIdentityModel::CheckBoxIdentityModel(int position){
    checkstate = new Qt::CheckState[10000];
    for(int i = 0;i < 10000;i++){
        checkstate[i] = Qt::Unchecked;
    }
    checkboxposition = position;
}

QVariant CheckBoxIdentityModel::data(const QModelIndex &index, int role) const
{
    if(index.column() == checkboxposition && role == Qt::CheckStateRole){
        return checkstate[index.row()];
    }
    return sourceModel()->data(index,role);
}

Qt::ItemFlags CheckBoxIdentityModel::flags(const QModelIndex & index) const
{
    if(index.column() == checkboxposition){
        return Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
    }
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}
void CheckBoxIdentityModel::setcheck(const QModelIndex & index){
    if(checkstate[index.row()] == Qt::Checked){
        checkstate[index.row()] = Qt::Unchecked;
    }else{
        checkstate[index.row()] = Qt::Checked;
    }
}
bool CheckBoxIdentityModel::setData(const QModelIndex &index,
                              const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::CheckStateRole) {
        if(checkstate[index.row()] == Qt::Checked){
            checkstate[index.row()] = Qt::Unchecked;
        }else{
            checkstate[index.row()] = Qt::Checked;
        }
        return true;
    }
    return true;
}
void CheckBoxIdentityModel::resetcheckstate(int rowCount){
    for(int i = 0;i < rowCount;i++){
        checkstate[i] = Qt::Unchecked;
    }
}
void CheckBoxIdentityModel::uncheckall(){
    for(int i = 0;i < this->rowCount();i++){
        checkstate[i] = Qt::Unchecked;
    }
}
void CheckBoxIdentityModel::selectall(){
    for(int i = 0;i < this->rowCount();i++){
        checkstate[i] = Qt::Checked;
    }
}
