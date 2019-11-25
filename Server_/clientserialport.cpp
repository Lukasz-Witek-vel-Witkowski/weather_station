#include "clientserialport.h"

clientSerialPort::clientSerialPort(qintptr ID, QObject *parent):clientBase(ID,parent)
{
     qDebug()<<"creative SerialPort!";
   start();
   V_message.push_back(nullptr);
     qDebug()<<"creative SerialPort!";

}
void clientSerialPort::cos(){

}
bool clientSerialPort::isMessage(){
    qDebug()<<"incomingConnection ";
           //message->createMassage();
    if(V_message[actualMessage]->isActive()){
        qDebug()<<"Message Active!";
    return true;
    }
    qDebug()<<"Message is not Active:(";
    return false;
}
void clientSerialPort::getChar(const char* Data){
    std::string data;
    for(int i=0; i<FrameMessage; i++){
        data.push_back(Data[i]);
    }
//  qDebug()<<"Hura odebrany sygnal"<<Data;
   V_message.push_back(nullptr);
    increase();
   actualMessage=0;
  V_message[actualMessage] = new Message(FrameMessage);
  V_message[actualMessage]->createMassage(data.c_str(),true);
  if(V_message[actualMessage]->isActive()){
   emit sendMessage(V_message[actualMessage]->getStdData().c_str(), V_message[actualMessage]->getID());
      qDebug()<<"widomosc serialPort! = "<<actualMessage<<V_message[actualMessage]->getData();
  }
  qDebug()<<"czy dziala?";
  delete V_message[actualMessage];
  V_message.erase(V_message.begin() + int(actualMessage));
 dicrease();
  qDebug()<<"koniec serialPort!";
}
void clientSerialPort::run(){
    qDebug()<<"Start client Serial Port!";
}
void clientSerialPort::setDataBase(QSqlDatabase* sql){}
