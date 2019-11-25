#ifndef CLIENTLEESENER_H
#define CLIENTLEESENER_H
#include "clientBase.h"

class clientLeesener : public clientBase
{
    Q_OBJECT
public:
   explicit clientLeesener(qintptr ID, QObject *parent);
    void cos() Q_DECL_OVERRIDE;
    bool isMessage() Q_DECL_OVERRIDE;
    void run() Q_DECL_OVERRIDE;
    void setDataBase(QSqlDatabase* sql) Q_DECL_OVERRIDE;
public slots:
     void answerMessage(const char* Data, unsigned int id);
};

#endif // CLIENTLEESENER_H
