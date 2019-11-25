#include "message.h"

Message::Message(unsigned int data)
{
     _frame = new unsigned int(data);
}
Message::Message(const char* Data, unsigned int i, unsigned int SIZE){
    setID(i);
    _frame = new unsigned int(SIZE);
    createMassage(Data);
    qDebug()<<"creative message of id = "<<i;
}
Message::Message(){qDebug()<<"Creative Message!";}
void Message::createMassage(const char* Data, bool WHAT){
    qDebug()<<"Pobranie daty!";
    bool bId= false;
    if(_id==nullptr){ _id = new unsigned int; bId = true;}
    qDebug()<<"id ="<<bId<<"Frame ="<<*_frame;
    unsigned int i;
    unsigned int j;
    char* temp;
    unsigned int size=0;
    for(i=0; i<*_frame; i++){
       // qDebug()<<Data[i];
        if(Data[i]=='|'&&i>0){
           if(bId== true){
            temp = new char[i];
            for(j=0; j<i; j++){
               temp[j]=Data[j];
            }

            *_id=unsigned(QString::fromUtf8(temp,int(i)).toInt());
            delete temp;
           }
           if(WHAT==true){
                  transformer(Data);
                  qDebug()<<"Mesage ok !";
                  return;
            }
            size = *_frame-i;
            temp = new char[size];
            i++;
            _startMessage = new unsigned int;
            *_startMessage = i;
            for(j=i; j<*_frame;j++){
               temp[j-i]=Data[j];
            }
           designateDateParameters(temp);
            transformer(Data);
            qDebug()<<"MESSSAGE OK!";
            *_frame = size;
              delete[] temp;
            break;
        }
    }
}
const char* Message::getData(){
    if(isActive())return _data.c_str();
    return nullptr;
}
std::string Message::getStdData(){
    return _data;
}
void Message::clear(){
    delete _frame;
    delete _id;
    delete _startMessage;
    delete _date;
    _startMessage = nullptr;
    _frame = nullptr;
    _id = nullptr;
    _date = nullptr;
    copy = false;
}
bool Message::isActive(){
    if(!_data.empty()) return true;
    return false;
}
unsigned int Message::getID(){
    if(_id) return *_id;
    return NULL;
}
void Message::setFrame(int data){
    if(_frame==nullptr){
        qDebug()<<"nie ma wskaznika!";
  _frame = new unsigned int(unsigned(data));
    }
    else{
         qDebug()<<"jest wskaznik!";
    *_frame = unsigned(data);
    }
}
Message::~Message(){
    delete _id;
    delete _frame;
    delete _startMessage;
     delete _date;
    _date = nullptr;
    _id = nullptr;
    _frame = nullptr;
    _startMessage = nullptr;
}
void Message::setID(unsigned int id){
    if(_id==nullptr){
        _id = new unsigned int;
        *_id = id;
        }
    else
        *_id = id;
}
void Message::transformer(const char* Data){
    for(unsigned int i=0; i<*_frame; i++){
    _data.push_back(Data[i]);
    }
}
double Message::toExternalThermomer(){
    return *_externalThermomer;
}
double Message::toInternalThermomer(){
    return *_internalThermomer;
}
double Message::toHumidity(){
    return *_humidity;
}
unsigned int    Message::toId(){
    return *_id;
}
double Message::toPressure(){
    return *_pressure;
}
void Message::designateDateParameters(const char* Data){
    unsigned int i =0;
    unsigned int j =0;
    char* temp;
    temp = new char[*_frame];
    for(i=0; i<*_frame; i++){
        switch(Data[i]){
        case 'C':
            designateData(Data,i,j,temp);
            if(_externalThermomer==nullptr)
            _externalThermomer = new double(QString::fromUtf8(temp).toDouble());
            else
            *_externalThermomer = QString::fromUtf8(temp).toDouble();
           break;
        case 'T':
            designateData(Data,i,j,temp);
            if(_internalThermomer==nullptr)
            _internalThermomer = new double(QString::fromUtf8(temp).toDouble());
            else
            *_internalThermomer = QString::fromUtf8(temp).toDouble();
           break;
        case 'W':
            designateData(Data,i,j,temp);
            if(_externalThermomer==nullptr)
            _humidity = new double(QString::fromUtf8(temp).toDouble());
            else
            *_humidity = QString::fromUtf8(temp).toDouble();
           break;
        case 'P':
            designateData(Data,i,j,temp);
            if(_pressure==nullptr)
            _pressure = new double(QString::fromUtf8(temp).toDouble());
            else
            *_pressure = QString::fromUtf8(temp).toDouble();
           break;
        case 'Y':
             designateData(Data,i,j,temp);
             if(_date==nullptr)
                 _date = new DateTime();
                 _date->addYear(QString::fromUtf8(temp).toInt());
            break;
        case 'M':
            designateData(Data,i,j,temp);
            if(_date==nullptr)
                _date = new DateTime();
                _date->addMonth(QString::fromUtf8(temp).toInt());
           break;
        case 'D':
            designateData(Data,i,j,temp);
            if(_date==nullptr)
                _date = new DateTime();
                _date->addDay(QString::fromUtf8(temp).toInt());
           break;
        case 'h':
            designateData(Data,i,j,temp);
            if(_date==nullptr)
                _date = new DateTime();
           _date->addHour(QString::fromUtf8(temp).toInt());
           break;
        case 'm':
            designateData(Data,i,j,temp);
            if(_date==nullptr)
                _date = new DateTime();
           _date->addMinute(QString::fromUtf8(temp).toInt());
           break;
        case 's':
            designateData(Data,i,j,temp);
            if(_date==nullptr)
                _date = new DateTime();
               _date->addSecond(QString::fromUtf8(temp).toInt());
            break;
        }
  // qDebug()<<"Message: "<<temp;
    }
}
void Message::designateData(const char* Data,unsigned int& i, unsigned int& j, char* temp){
    i++;
    if(temp!=nullptr)
        delete[] temp;
        temp = new char[*_frame];

    for(j=i; j<*_frame; j++){
        if(Data[j]==' '){
            temp[j-i]='\0';
            i = j;
            return;
        }
        else{
           temp[j-i] = Data[j];
        }
    }
}
int Message::tominute(){
    return _date->getMinute();
}
int Message::tosecend(){
    return _date->getSecond();
}
int Message::tohour(){
    return _date->getHour();
}
int Message::toDay(){
    return _date->getDay();
}
int Message::toMonth(){
    return _date->getMounth();
}
int Message::toYear(){
    return _date->getYear();
}
