#include "mainwindow.h"
#include "bookingwindow.h"

#include <QApplication>
#include <QLabel>
#include <QGridLayout>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(600,400); //setting the windows width and height;
    w.show();
    return a.exec();
}
