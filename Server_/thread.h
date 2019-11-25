#ifndef THREAD_H
#define THREAD_H 
#include <QtCore>
#include <QTcpSocket>
#include "clientBase.h"
#include <QDebug>
#define sizeClient 3
#define it_csp 0
#define it_csql 1
#define it_clee 2
class Thread: public QThread
{
   Q_OBJECT
public:
 explicit Thread(qintptr ID, QObject *parent = nullptr);
 void error(QTcpSocket::SocketError socketerror);
signals:
 void signalData(const char*);
public slots:
void read();
void disconnect();
protected:
    void run() Q_DECL_OVERRIDE;
private:
    qintptr socketDescriptor;
    QTcpSocket *socket = nullptr;
    bool what;
    char* _data = nullptr;
};

#endif // THREAD_H
