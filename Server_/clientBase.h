#ifndef CLIENTBASE_H
#define CLIENTBASE_H
#include "message.h"
#include "windowmain.h"
#include <QObject>
#include <QThread>
#include <QtSql>
class clientBase:public QThread
{
    Q_OBJECT
public:
  explicit clientBase(qintptr ID, QObject* parent);
    virtual void cos()=0;
    virtual bool isMessage()=0;
    virtual void setDataBase(QSqlDatabase* sql)=0;
    //virtual ~clientBase();
   const char* getData(unsigned int i);
   void setData(const char* data, unsigned int id);
   void increase();
   void setWindow(WindowMain& window);
   void dicrease();
   unsigned int getID();
   void freememory();

signals:

protected:
    virtual void run()=0;
    QObject *_parent= nullptr;
    WindowMain *_window =nullptr;
    qintptr* _ID = nullptr;
    bool* _what = nullptr;
    QSqlDatabase* _sql = nullptr;
    std::vector<Message*> V_message;
    unsigned int actualMessage;
    bool empty;
};

#endif // CLIENTBASE_H
