#include "t9.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    T9 w;
    w.show();

    return a.exec();
}
