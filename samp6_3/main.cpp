#include "qwmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWMainWindow w;
    w.show();
    return a.exec();
}
