#include "serialport.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serialPort w;
    return a.exec();
}
