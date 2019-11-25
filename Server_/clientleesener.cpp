#include "clientleesener.h"

clientLeesener::clientLeesener(qintptr ID, QObject *parent):clientBase (ID,parent)
{
start();
}
void clientLeesener::cos(){
    _window->setData(V_message[actualMessage]->toId(),
                     V_message[actualMessage]->toInternalThermomer(),
                     V_message[actualMessage]->toExternalThermomer(),
                     V_message[actualMessage]->toHumidity(),
                     V_message[actualMessage]->toPressure(),
                     V_message[actualMessage]->toDay(),
                     V_message[actualMessage]->toMonth(),
                     V_message[actualMessage]->toYear(),
                     V_message[actualMessage]->tohour(),
                     V_message[actualMessage]->tominute(),
                     V_message[actualMessage]->tosecend());
}
bool clientLeesener::isMessage(){return false;}
void clientLeesener::run(){};

//clientLeesener::~clientLeesener(){}
void clientLeesener::answerMessage(const char* Data, unsigned int id){
    std::string data;
    for(int i=0; i<FrameMessage; i++){
        data.push_back(Data[i]);
    }
    if(!empty){
        if(V_message[actualMessage]->getID()==id) return;
    }
    qDebug()<<"Odebranie sygnalu prze clientLeessener: "<<id<<Data;
    increase();
    V_message.push_back(nullptr);
    V_message[actualMessage] = new Message(data.c_str(), id,FrameMessage);
    cos();
    delete V_message[actualMessage];
    V_message.erase(V_message.begin() + int(actualMessage));
   dicrease();
}
void clientLeesener::setDataBase(QSqlDatabase* sql) {}
