#include "fish.h"
#include "functions.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fish w;
    w.show();


    return a.exec();
}
