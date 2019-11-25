#ifndef MESSAGE_H
#define MESSAGE_H
#include <QDebug>
#include <QString>
#define FrameMessage 68
#define FrameCopyMessage 63
//#define Frame 5
#include <cstring>
#include "datetime.h"
class Message
{
public:
    explicit Message();
    explicit Message(const char* Data, unsigned int i, unsigned int SIZE);
    explicit Message(unsigned int _frame);
    void createMassage(const char * Data, bool WHAT=false);
    const char* getData();
    std::string getStdData();
    bool isActive();
    void setFrame(int _frame);
    void setID(unsigned int id);
    void clear();
    void transformer(const char* Data);
    unsigned int getID();
    double toExternalThermomer();
    double toInternalThermomer();
    double toHumidity();
    double toPressure();
    unsigned int    toId();
    int    tominute();
    int    tosecend();
    int    tohour();
    int    toDay();
    int    toMonth();
    int    toYear();
    ~Message();
private:
    void designateDateParameters(const char* Data);
    void designateData(const char* Data, unsigned int& i, unsigned int& j, char* temp);
    double *_externalThermomer = nullptr;
    double *_internalThermomer = nullptr;
    double *_humidity = nullptr;
    double *_pressure = nullptr;
    DateTime* _date = nullptr;
    unsigned int *_id = nullptr;
    unsigned int *_frame = nullptr;
    unsigned int *_startMessage = nullptr;
    std::string _data;
    bool copy;
};

#endif // MESSAGE_H
