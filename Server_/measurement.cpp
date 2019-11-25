#include "measurement.h"
Measurement::Measurement(){
    _t_wew = new QStandardItem(" ");
    _t_zew = new QStandardItem(" ");
    _h = new QStandardItem(" ");
    _p = new QStandardItem(" ");
    _id = 0;
}
Measurement::Measurement(unsigned int id, double t_wew, double t_zew, double h, double p, DateTime data)
{
   _t_wew = new QStandardItem(QString::number(t_wew,'f',2));
   _t_zew = new QStandardItem(QString::number(t_zew,'f',2));
   _h = new QStandardItem(QString::number(h,'f',2));
   _p = new QStandardItem(QString::number(p,'f',2));
    _id = id;
    _data = data;
}
void Measurement::setTableWidget(unsigned int in, QStandardItemModel *model){
            model->setItem(int(in), 0, _t_wew);
            model->setItem(int(in), 1, _t_zew);
            model->setItem(int(in), 2, _h);
            model->setItem(int(in), 3, _p);
}
unsigned int Measurement::getId(){return _id;}
Measurement::~Measurement(){
    qDebug()<<"Delete Measurement";
    delete _t_wew;
    delete _t_zew;
    delete _h;
    delete _p;
}
Measurement::Measurement(const Measurement& M){
    if(this!=&M) *this = M;
}
Measurement& Measurement::operator=(const Measurement& M){
 if(this==&M) return *this;
 if(*this==M) return *this;
 _id = M._id;
 _data = M._data;
 if(_t_wew==nullptr) _t_wew = new QStandardItem(M._t_wew->text());
 else
 _t_wew->setText(M._t_wew->text());
 if(_t_zew==nullptr) _t_zew = new QStandardItem(M._t_zew->text());
 else
 _t_zew->setText(M._t_zew->text());
 if(_h==nullptr) _h = new QStandardItem(M._h->text());
 else
 _h->setText(M._h->text());
 if(_p==nullptr) _p = new QStandardItem(M._p->text());
 else
 _p->setText(M._p->text());
return *this;

}
bool Measurement::operator==(const Measurement& M){
        if(_id == M._id&&_data==M._data&&_t_wew->text()==M._t_wew->text()&&
                _t_zew->text()==M._t_zew->text()&&_h->text()==M._h->text()&&
                _p->text()==M._p->text()) return true;
        return false;
}
void Measurement::update(unsigned int id, double t_wew, double t_zew, double h, double p, DateTime data){
    _id = id;
    _data = data;
    _t_wew->setText(QString::number(t_wew,'f',2));
    _t_zew->setText(QString::number(t_zew,'f',2));
    _h->setText(QString::number(h,'f',2));
    _p->setText(QString::number(p,'f',2));
}
void Measurement::update(const Measurement& M){
    qDebug()<<"update";
    _id = M._id;
    _data = M._data;
    _t_wew->setText(M._t_wew->text());
    _t_zew->setText(M._t_zew->text());
    _h->setText(M._h->text());
    _p->setText(M._p->text());
}
