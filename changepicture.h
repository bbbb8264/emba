#ifndef CHANGEPICTURE
#define CHANGEPICTURE

#endif // CHANGEPICTURE

#include <QtWidgets>

class ChangePicture : public QLabel
{
   Q_OBJECT
   bool event(QEvent* e) override;
   void	mousePressEvent(QMouseEvent * ev) override;
   void	mouseReleaseEvent(QMouseEvent * ev) override;
   bool newpictureinsert = false;
   QString getpicturepath();
   QFileDialog* filedialog;
public:
   bool pictureinsert = false;
   ChangePicture();
   QImage img;
signals:
   void inserted();
};
