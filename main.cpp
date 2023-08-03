#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resizeWindow();
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    a.exec();
    return 0;
}
