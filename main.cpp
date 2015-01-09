#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    //set window title
    w.setWindowTitle("PANDARDUINO");

    return a.exec();
}
