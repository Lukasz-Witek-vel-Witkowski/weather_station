#include "clientfactory.h"

clientFactory::clientFactory()
{

}
clientBase* clientFactory::creation(int type,qintptr ID, QObject *parent){
    switch(type){
    case id_clientserialport:   return new clientSerialPort(ID, parent);
    case id_clientsql:          return new clientSQL(ID,parent);
    case id_clientlessener:     return new clientLeesener(ID,parent); //wyrzuca blad!!
    }
    return nullptr;
}
clientFactory::~clientFactory(){}
