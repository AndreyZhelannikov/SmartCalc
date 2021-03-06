#include <QApplication>

#include "calculator.h"
#include "qcustomplot.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Calculator w;

    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::white);
    w.setAutoFillBackground(true);
    w.setPalette(pal);

    w.show();
    return a.exec();
}
