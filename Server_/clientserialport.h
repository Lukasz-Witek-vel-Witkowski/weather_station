#ifndef CLIENTSERIALPORT_H
#define CLIENTSERIALPORT_H
#include "clientBase.h"

class clientSerialPort:public clientBase
{
    Q_OBJECT
public:
    explicit clientSerialPort(qintptr ID, QObject *parent);
    void cos() Q_DECL_OVERRIDE;
    bool isMessage() Q_DECL_OVERRIDE;
    void run() Q_DECL_OVERRIDE;
    void setDataBase(QSqlDatabase* sql) Q_DECL_OVERRIDE;
public slots:
    void getChar(const char* Data);
signals:
    void sendMessage(const char* Data, unsigned int id);
};

#endif // CLIENTSERIALPORT_H
