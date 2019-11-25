#ifndef SERVER_H
#define SERVER_H
#include <QObject>
#include <QTcpServer>
#include "thread.h"
#include "clientfactory.h"
#include "../outFile/option.h"
#include <vector>
#include <QMutex>
#include <QMessageBox>
#include <QSqlDatabase>
#define dataBaseName "D:\\Project\\Studia\\Semestr_V\\Qt\\pomiary\\baza\\Wather.sqllite3"
#define dataBaseUser   "root"
#define dataBasePassword    "Filip011235812"
#define z_t "ExternalThermomer"
#define w_t "InternalThermomer"
#define h "Humidity"
#define p "Pressure"
#define t_d "DateHour"
#define t_type " varchar(10), "
class Server:public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void startServer();
    void getchar(char* data);
    unsigned int getsize_thread() const;
    void setsize_thread(unsigned int value);
    void connectSQl();
protected:
    void incomingConnection(qintptr a);
private:
    std::vector<clientBase*> V;
    clientFactory factory;
    QSqlDatabase _sql;
    WindowMain Window;
};
#endif // SERVER_H
