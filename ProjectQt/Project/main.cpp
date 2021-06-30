#include "mainwindow.h"
#include <QStyleFactory>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Установим стиль оформления
     // Стандартная палитра является светлой
    qApp->setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;
    w.show();
    return a.exec();
}
