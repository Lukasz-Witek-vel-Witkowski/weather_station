#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTcpSocket>
#include <QTextStream>
#include <QtDebug>
#include <QWindow>
#include <QThread>
#include <string>
#include <Windows.h>
#include <QFile>
#include "windowdevice.h"
#include "../outFile/option.h"
#define sizeid 100000
class serialPort : public QObject
{
    Q_OBJECT
public:
    explicit serialPort(QObject *parent = nullptr);
    void setSerial(std::string data);
    void config();
    std::string getSerial();
    std::string getData();
    bool ready();
    QTcpSocket& getSocket();
    bool getactive();
    friend void connect(serialPort Socket);
    void getTime();
    bool getIsConnect();
    void setISConnect(bool what);
    std::string getid();
    void addid();
    ~serialPort();
private:
    std::string serial;
    std::string data;
    QSerialPort *device;
    QByteArray ba,be;
    QThread* T;
    QTcpSocket *Socket;
    bool view;
    bool good;
    bool active;
    int id;
    bool isconnect;
    SYSTEMTIME st;
    QByteArray serialData;
    Option* option;
    WindowDevice* wdevice;
signals:

public slots:
    void read();
};


#endif // SERIALPORT_H
