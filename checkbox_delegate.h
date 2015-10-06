#ifndef CHECKBOX_DELEGATE
#define CHECKBOX_DELEGATE

#endif // CHECKBOX_DELEGATE

#include <QtWidgets>
class CheckBoxDelegate : public QStyledItemDelegate{
    Q_OBJECT
    void paint(QPainter *painter,const QStyleOptionViewItem &option,const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool editorEvent(QEvent *event,QAbstractItemModel *model,const QStyleOptionViewItem &option,const QModelIndex &index) Q_DECL_OVERRIDE;
};
