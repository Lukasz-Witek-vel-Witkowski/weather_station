#include "clientsql.h"

clientSQL::clientSQL(qintptr ID, QObject *parent):clientBase (ID, parent)
{    
    start();
}
void clientSQL::cos(){
   // _sql = QSqlDatabase::addDatabase("QSQLITE");
   /* _sql->setHostName("Wather");
    _sql->setDatabaseName(dataBaseName);
    _sql->setUserName(dataBaseUser);
    _sql->setPassword(dataBasePassword);*/
    if(_sql->open()){
   QSqlQuery query(*_sql);
   QString data ="INSERT INTO measurement(ExternalThermomer,InternalThermomer,Humidity,Pressure,DateHour) VALUES ('"+
           QString::number(V_message[actualMessage]->toExternalThermomer(),'f',2)+"','"+
           QString::number(V_message[actualMessage]->toInternalThermomer(),'f',2)+"','"+
           QString::number(V_message[actualMessage]->toHumidity(),'f',2)+"','"+
           QString::number(V_message[actualMessage]->toPressure(),'f',2)+"','"+
           QString::number(V_message[actualMessage]->toDay())+"-"+
           QString::number(V_message[actualMessage]->toMonth())+"-"+
           QString::number(V_message[actualMessage]->toYear())+" "+
           QString::number(V_message[actualMessage]->tohour())+":"+
           QString::number(V_message[actualMessage]->tominute())+":"+
           QString::number(V_message[actualMessage]->tosecend())+"')";
   query.exec(data);
   qDebug()<<data;
    }
}
bool clientSQL::isMessage(){return false;}
void clientSQL::run(){

}
void clientSQL::answerMessage(const char* Data, unsigned int id){
    std::string data;
    for(int i=0; i<FrameMessage; i++){
        data.push_back(Data[i]);
    }
    if(!empty){
        if(V_message[actualMessage]->getID()==id) return;
    }
    qDebug()<<"Odebranie sygnalu prze clientSQL: "<<id<<Data;
    increase();
    qDebug()<<actualMessage;
    V_message.push_back(nullptr);
    V_message[actualMessage] = new Message(data.c_str(), id,FrameMessage);
    qDebug()<<"VMessage ok!";
    cos();
    delete V_message[actualMessage];
    V_message.erase(V_message.begin() + int(actualMessage));
    dicrease();
}
void clientSQL::setDataBase(QSqlDatabase* sql){
    _sql = sql;
    if(_what==nullptr) _what = new bool;
    *_what = true;

}
