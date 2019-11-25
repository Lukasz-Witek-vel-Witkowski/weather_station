#include "thread.h"
Thread::Thread(qintptr ID, QObject *parent):QThread(parent)
{
    what = true;
socketDescriptor =ID;
_data = new char[FrameMessage];
qDebug()<<"creative thread";
}
void Thread::run(){
   socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor)){
       //emit error(socket->error());
        qDebug()<<"error!";
        return;
    }
    connect(socket, SIGNAL(readyRead()),this,SLOT(read()),Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()),this,SLOT(disconnect()),Qt::DirectConnection);
    exec();
 }
void Thread::read(){ 
    QByteArray ba;
    ba = socket->readAll();
    if(ba!=""){
        if(_data==nullptr) _data = new char[FrameMessage+1];
        for(int i=0; i<FrameMessage; i++){
            _data[i] = ba[i];
        }
        _data[FrameMessage]='\0';
    qDebug()<<"Emited!";
    qDebug() <<socketDescriptor <<"Data in"<<_data;
    //funkcja analizy przeslanych danych do napisania!!!
     msleep(100);
    emit signalData(_data);
     qDebug()<<"koniec read thread";
    }
}
void Thread::disconnect(){
    qDebug()<<socketDescriptor<<"Diskonnect";
    socket->deleteLater();
    delete[] _data;
    exit(0);
}

