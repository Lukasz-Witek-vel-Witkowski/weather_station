#ifndef CLIENTFACTORY_H
#define CLIENTFACTORY_H
#include "clientserialport.h"
#include "clientsql.h"
#include "clientleesener.h"
#define id_clientsql 1
#define id_clientserialport 2
#define id_clientlessener 3
class clientFactory
{
public:
    clientFactory();
    clientBase* creation(int type,qintptr ID, QObject *parent);
    ~clientFactory();
};

#endif // CLIENTFACTORY_H
