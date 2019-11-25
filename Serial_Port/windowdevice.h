#ifndef WINDOWDEVICE_H
#define WINDOWDEVICE_H
#include <QDebug>
#include <QMainWindow>
#include <QAbstractButton>
#include <QScrollBar>
#include <Windows.h>
namespace Ui {
class WindowDevice;
}
#define Size_button 11
#define Sekunda " [s]"
#define Scala   200
#define box_sekunda 0
#define box_minuta 1
#define box_default 2
#define box_cisnienie 3
#define box_wilgotnosc 4
#define box_ter_zew 5
#define box_ter_wew 6
#define box_cisnienie_temp 7
#define box_wilgotnosc_temp 8
#define box_ter_zew_temp 9
#define box_ter_wew_temp 10
class WindowDevice : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowDevice(QWidget *parent = nullptr);
    ~WindowDevice();

private slots:
    void on_pb_polacz_clicked();
    void on_cb_minuta_clicked();
    void on_cb_sekunda_clicked();
    void refresh(int id);
    void on_click(int value);
    void on_cb_default_clicked();
    bool revalue(bool b);
    void refresh_button(QAbstractButton* w,int id, bool value, bool enable);
    void on_cb_ciscienie_clicked();
    void on_cb_wilgotnosc_clicked();
    void setresult();
    void on_cb_termometr_zew_clicked();
    void reset();
    void on_cb_termometr_wew_clicked();
    void on_Skala_valueChanged(int value);
    void on_wynik_editingFinished();
    void on_wynik_selectionChanged();
    void on_le_name_editingFinished();

private:
    Ui::WindowDevice *ui;
    bool* pointer;
    bool lessener;
    int valueTime;
    QString nameDevice;
};

#endif // WINDOWDEVICE_H
