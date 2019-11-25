#ifndef CLIENTSQL_H
#define CLIENTSQL_H
#include "clientBase.h"

class clientSQL: public clientBase
{
    Q_OBJECT
public:
    explicit clientSQL(qintptr ID, QObject *parent);
    void cos() Q_DECL_OVERRIDE;
    bool isMessage() Q_DECL_OVERRIDE;
    void run() Q_DECL_OVERRIDE;
    void setDataBase(QSqlDatabase* sql) Q_DECL_OVERRIDE;
public slots:
     void answerMessage(const char* Data, unsigned int id);
};

#endif // CLIENTSQL_H
