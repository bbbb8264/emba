#include "filedialog.h"

FileChooser::FileChooser()
{
    setWindowTitle(tr("Open Image"));
    setFilter(QDir::Files);
    QStringList filters;
    filters << "Image files (*.png *.xpm *.jpg)"
            << "Text files (*.txt)"
            << "Any files (*)";
    setNameFilters(filters);
}
void FileChooser::open(QObject * receiver, const char * member)
{
    qDebug() << member;
}
