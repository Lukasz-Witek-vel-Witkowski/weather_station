#ifndef MEASUREMENT_H
#define MEASUREMENT_H
#include "datetime.h"
#include <QStandardItemModel>
#include <qdebug.h>
class Measurement
{
public:
    Measurement();
    Measurement(unsigned int id, double t_wew, double t_zew, double h, double p, DateTime data);
    Measurement(const Measurement& M);
    Measurement& operator=(const Measurement& M);
    bool operator==(const Measurement& M);
    void update(unsigned int id, double t_wew, double t_zew, double h, double p, DateTime data);
    void update(const Measurement& M);
    ~Measurement();
    void setTableWidget(unsigned int in,QStandardItemModel *model);
    unsigned int getId();
private:
    QStandardItem *_t_wew = nullptr;
    QStandardItem *_t_zew = nullptr;
    QStandardItem *_h = nullptr;
    QStandardItem *_p = nullptr;
    unsigned int _id;
    DateTime _data;
};

#endif // MEASUREMENT_H
