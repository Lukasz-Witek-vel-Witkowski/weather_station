#include "serialport.h"
void Connect(serialPort* Socket);
serialPort::serialPort(QObject *parent) : QObject(parent)
{
    device = new QSerialPort(this);
    Socket = new QTcpSocket(this);
    data="";
    serial ="";
    ba ="";
    id = 1;
    good = false;
    view=false;
    active = true;
    isconnect = false;
    T = new QThread();
    wdevice = new WindowDevice();
    option = new Option();
    wdevice->show();
    //option->show();
    config();
}
void serialPort::config(){
     QFile file("D:\\Project\\Studia\\Semestr_V\\Qt\\SerialPort\\plik.txt");
     if(file.open(QFile::WriteOnly | QFile::Text)){
          QTextStream zapis(&file);
        for(int i=0; i<100;i++){
           //device->setPortName("com6");
           device->setPortName("com"+QString::number(i));
           device->setBaudRate(QSerialPort::Baud9600);
           device->setDataBits(QSerialPort::Data8);
           device->setFlowControl(QSerialPort::NoFlowControl);
           device->setParity(QSerialPort::NoParity);
           device->setStopBits(QSerialPort::OneStop);
           device->setFlowControl(QSerialPort::NoFlowControl);
           device->open(QIODevice::ReadWrite);
           qDebug()<<"Pruba otwarcia portu: COM"+QString::number(i);
           QObject::connect(device, SIGNAL(readyRead()), this, SLOT(read()));
           if(device->isOpen()){serial = device->portName().toStdString();
               getSocket().connectToHost("192.168.56.1",1234);
               break; }
            qDebug()<<"Nie udało sę połączyć!";
        }
        file.close();
 }
}
void serialPort::getTime(){
      GetSystemTime(&st);
      data.pop_back();
      data.pop_back();
      data = getid()+data;
      addid();
    data += "Y"+QString::number(st.wYear).toStdString() + " M"+QString::number(st.wMonth).toStdString()+ " D"+QString::number(st.wDay).toStdString()+ " h"+QString::number(st.wHour+1).toStdString()+
            " m"+QString::number(st.wMinute).toStdString()+ " s"+QString::number(st.wSecond).toStdString()+"\n";//dodanie strefy czasowej
}
serialPort::~serialPort() {
    delete device;
    delete Socket;
}
bool serialPort::getactive(){
    return active;
}
QTcpSocket& serialPort::getSocket(){
    return *Socket;
}
void serialPort::setSerial(std::string data) {serial = data;}
void serialPort::read(){
ba = device->readAll();
    if(ba!=""){
        if(view && be.size()+ba.size()<60){good = true; data = be.toStdString()+ba.toStdString();  qDebug()<<be+ba; view=false; be.clear();Connect(this);}
        else if(view){view=false;}
        else if(ba[0]=='W'){  be = ba; view=true;}
    }
}
std::string serialPort::getSerial(){return serial;}
std::string serialPort::getData(){return data;}
bool serialPort::ready(){
    if(good){
        good=false;
        return true;
    }
    return false;
}

void Connect(serialPort* Serial){
    if(Serial->getSocket().waitForConnected(1000)){
        qDebug() << "Connect!";
        Serial->getTime();
            if(Serial->ready()){
                //Sleep(2000);
                Serial->getSocket().write(Serial->getData().c_str(),1234);
                 qDebug()<<"wysyłka"<<Serial->getData().c_str();
            }
    }
    else{
          Serial->getSocket().close();
         Serial->getTime();
        qDebug() << "Not Connected!"<<Serial->getData().c_str()<<" id- "<<Serial->getid().c_str();;
    }
}
void serialPort::addid(){
    id++;
    if(id>sizeid){
        id = 1;
    }
}
std::string serialPort::getid(){
   std::string data;
   int i;
   data = QString::number(id).toStdString();
   if(data.size()<5){
       char a='0';
       for(i=0; i<int(5-data.size());i++)
                data=a+data;
   }
   data+='|';
   return data;
}
