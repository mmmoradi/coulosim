#include "coulosim.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Coulosim w;
    w.show();
    return a.exec();
}
