#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("ImgLabel");
    w.show();
    w.setWindowIcon(QIcon("./resources/icons/TITLE.png"));
    return a.exec();
}
