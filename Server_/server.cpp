#include "server.h"

Server::Server(QObject *parent):QTcpServer(parent)
{
    Window.show();
qDebug()<<"Start Server";
connectSQl();
V.resize(sizeClient);
V[it_csp]=factory.creation(id_clientserialport,id_clientserialport,this);
V[it_csql]=factory.creation(id_clientsql,id_clientsql,this);
V[it_csql]->setDataBase(&_sql);
V[it_clee]=factory.creation(id_clientlessener,id_clientlessener,this);
V[it_clee]->setWindow(Window);
qDebug()<<"fabric :)";
}
void Server::startServer(){
        if(this->listen(QHostAddress::Any,1234))  qDebug() <<"Coult not start server";
        else qDebug()<<"Listening...";
}
void Server::incomingConnection(qintptr Id){
   Thread* _thread = new Thread(Id, this);
   QObject::connect(_thread,SIGNAL(finished()),_thread,SLOT(deleteLater()));
   QObject::connect(_thread,SIGNAL(signalData(const char*)),V[it_csp],SLOT(getChar(const char*)));
   QObject::connect(V[it_csp],SIGNAL(sendMessage(const char*, unsigned int)),V[it_csql],SLOT(answerMessage(const char*, unsigned int)));
   QObject::connect(V[it_csp],SIGNAL(sendMessage(const char*, unsigned int)),V[it_clee],SLOT(answerMessage(const char*, unsigned int)));
   _thread->start();
}
void Server::connectSQl(){
    _sql = QSqlDatabase::addDatabase("QSQLITE");
    _sql.setHostName("Wather");
    _sql.setDatabaseName(dataBaseName);
    _sql.setUserName(dataBaseUser);
    _sql.setPassword(dataBasePassword);
    if(_sql.open()){
        qDebug()<<"is Connect SQl!";
         QSqlQuery query(_sql);
         QString data = "CREATE TABLE IF NOT EXISTS measurement (id INTEGER UNIQUE PRIMARY KEY, ";
         data += z_t;
         data += t_type;
         data += w_t;
         data += t_type;
         data += h;
         data += t_type;
         data += p;
         data += t_type;
         data += t_d;
         data += " varchar(20))";
         query.exec(data);
    }
    else{
        qDebug()<< "Failed to connect to the database";
    }
}

