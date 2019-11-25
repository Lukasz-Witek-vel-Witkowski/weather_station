#include "windowmain.h"
//#include <QApplication>
#include <QtWidgets/QApplication>
#include "server.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server w;
    w.startServer();

    return a.exec();
}
