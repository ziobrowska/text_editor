// Joanna Ziobrowska

#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[]){

    Q_INIT_RESOURCE(zasoby);

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("UJ EDYTOR");
    w.show();

    return a.exec();
}
