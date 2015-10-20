#ifndef FILEDIALOG
#define FILEDIALOG

#endif // FILEDIALOG
#include <QtWidgets>
class FileChooser : public QFileDialog
{
public:
    FileChooser();
    void open(QObject * receiver, const char * member);
};
