#include "dumbcalc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dumbcalc w;
    w.show();
    return a.exec();
}
