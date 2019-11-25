#include "clientBase.h"

clientBase::clientBase(qintptr ID, QObject* parent):QThread (parent){
    _parent = parent;
    _ID = new qintptr(ID);
    actualMessage = 0;
    empty = true;
   //message = new Message();
    qDebug()<<"creative ClientBase!";
  //  start();
}

const char* clientBase::getData(unsigned int i){
    if(i<=actualMessage){
        return V_message[i]->getData();
    }
    return nullptr; //ciekawe czy bedzie dzialac
}
void clientBase::setData(const char* data,unsigned int id){
   Message* message = new Message(data,id,FrameMessage);
   increase();
   V_message.push_back(message);
   delete message;
}
unsigned int clientBase::getID(){
    return V_message[actualMessage]->getID();
}
void clientBase::increase(){
    if(!empty){
       actualMessage++;
    }
    else{
        empty = false;
    }
}
void clientBase::dicrease(){
    if(!empty){
        if(actualMessage==0){
            empty = true;
        }
        else
            actualMessage--;
    }
}
void clientBase::freememory(){
    if(_sql!=nullptr) delete _sql;
    if(_ID!=nullptr) delete _ID;
    if(_what!= nullptr) delete _what;
}
void clientBase::setWindow(WindowMain& window){
    _window = &window;
}
