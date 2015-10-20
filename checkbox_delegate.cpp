#include "checkbox_delegate.h"

#include <QtGui>

static QRect CheckBoxRect(const QStyleOptionViewItem &view_item_style_options) {
  QStyleOptionButton check_box_style_option;
  QRect check_box_rect = QApplication::style()->subElementRect(
      QStyle::SE_CheckBoxIndicator,
      &check_box_style_option);
  QPoint check_box_point(view_item_style_options.rect.x() +
                         view_item_style_options.rect.width() / 2 -
                         check_box_rect.width() / 2,
                         view_item_style_options.rect.y() +
                         view_item_style_options.rect.height() / 2 -
                         check_box_rect.height() / 2);
  return QRect(check_box_point, check_box_rect.size());
}

void CheckBoxDelegate::paint(QPainter *painter,
                             const QStyleOptionViewItem &option,
                             const QModelIndex &index) const {
  bool checked = index.model()->data(index, Qt::CheckStateRole).toBool();
  QStyleOptionButton check_box_style_option;
  check_box_style_option.state |= QStyle::State_Enabled;
  if (checked) {
    check_box_style_option.state |= QStyle::State_On;
  } else {
    check_box_style_option.state |= QStyle::State_Off;
  }
  check_box_style_option.rect = CheckBoxRect(option);
  QApplication::style()->drawControl(QStyle::CE_CheckBox,
                                     &check_box_style_option,
                                     painter);
}

// This is essentially copied from QStyledItemEditor, except that we
// have to determine our own "hot zone" for the mouse click.
bool CheckBoxDelegate::editorEvent(QEvent *event,
                                   QAbstractItemModel *model,
                                   const QStyleOptionViewItem &option,
                                   const QModelIndex &index) {
  if (event->type() == QEvent::MouseButtonRelease) {
      model->setData(index,"",Qt::CheckStateRole);
      return true;
  }
  return true;
}
