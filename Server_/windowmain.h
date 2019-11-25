#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H
#include "measurement.h"
#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QString>
#include <vector>
#include <QStandardItemModel>
#include <QDebug>
#include <string>
#define idRadActualy    0
#define idRadPersonal   1
#define idSuwak         3
#define idtextGora      4
#define sekunda         " [s]"
namespace Ui {
class WindowMain;
}

class WindowMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowMain(QWidget *parent = nullptr);
    void setData(unsigned int id,double t_w, double t_z, double w, double c,int day, int mounth, int year, int h, int m, int s);
    ~WindowMain();

private slots:
    void on_Rad_actual_clicked();

    void on_Rad_personal_clicked();

    void on_Le_time_editingFinished();

    void on_Le_size_editingFinished();

    void on_Suwak_valueChanged(int value);

    QString actualyText(QString arg, int pointer=1);
    void update();
    //void on_Le_time_textChanged(const QString &arg1);

    void on_Le_gora_editingFinished();

    //void on_Le_gora_textChanged(const QString &arg1);

private:
    void refresh(int id);
    void configurationTable(unsigned int i_value=20);
    unsigned int size_measurement;
    bool messagebox;
    Measurement* V_measurement;
    QStandardItemModel *tableViewModel;
    QString le_time;
    QString le_size;
    QString le_gora;
    unsigned int value;
    unsigned int iterator;
    unsigned int iter_value;
    Ui::WindowMain *ui;
};

#endif // WINDOWMAIN_H
