#include "windowdevice.h"
#include "ui_windowdevice.h"

WindowDevice::WindowDevice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowDevice)
{
    ui->setupUi(this);
    lessener = true;
    ui->device->setText("");
    pointer = new bool[Size_button];
    reset();
    valueTime=1;
    ui->cb_default->click();
    ui->cb_sekunda->click();
    ui->scrollArea->verticalScrollBar()->setFocus();

}

WindowDevice::~WindowDevice()
{
    delete ui;
    delete[] pointer;
}

void WindowDevice::on_pb_polacz_clicked()
{
//po naciś◘nięciu polaczenia
}



void WindowDevice::on_cb_minuta_clicked()
{
 on_click(box_minuta);
}

void WindowDevice::on_cb_sekunda_clicked()
{
 on_click(box_sekunda);
}
void WindowDevice::reset(){
        for(int i=0; i<Size_button; i++){
            pointer[i]=false;
        }
}


void WindowDevice::on_cb_default_clicked()
{
 on_click(box_default);
}
void WindowDevice::setresult(){
    if(pointer[box_sekunda]) ui->wynik->setText(QString::number(valueTime)+Sekunda);
    else ui->wynik->setText(QString::number(60*valueTime)+Sekunda);
}
void WindowDevice::refresh(int id){
    switch(id){
   case box_default:
        refresh_button(ui->cb_ciscienie,box_cisnienie_temp,pointer[box_default],false);
        refresh_button(ui->cb_termometr_wew,box_ter_wew_temp,pointer[box_default],false);
        refresh_button(ui->cb_termometr_zew,box_ter_zew_temp,pointer[box_default],false);
        refresh_button(ui->cb_wilgotnosc,box_wilgotnosc_temp,pointer[box_default],false);
         qDebug()<<"="<<pointer[box_cisnienie_temp]<<pointer[box_ter_wew_temp]<<pointer[box_ter_zew_temp]<<pointer[box_wilgotnosc_temp];
        qDebug()<<"wartosc default ="<<pointer[box_default];
         if(pointer[box_default]==false){
            refresh_button(ui->cb_ciscienie,box_cisnienie_temp,pointer[box_cisnienie],true);
            refresh_button(ui->cb_termometr_wew,box_ter_wew_temp,pointer[box_ter_wew],true);
            refresh_button(ui->cb_termometr_zew,box_ter_zew_temp,pointer[box_ter_zew],true);
            refresh_button(ui->cb_wilgotnosc,box_wilgotnosc_temp,pointer[box_wilgotnosc],true);

        }
        break;
      case box_sekunda:
        if(pointer[box_sekunda])  {
        refresh_button(ui->cb_minuta,box_minuta,false,true);
        setresult();}
        else {
         refresh_button(ui->cb_minuta,box_minuta,true,true);
         setresult();}
        break;
       case box_minuta:
        if(pointer[box_minuta])  {
        refresh_button(ui->cb_sekunda,box_sekunda,false,true);
         setresult();}
        else{
         refresh_button(ui->cb_sekunda,box_sekunda,true,true);
          setresult();}
        break;
       case Scala:
        setresult();
        break;
    }
}

void WindowDevice::on_cb_ciscienie_clicked()
{
 on_click(box_cisnienie);
  on_click(box_cisnienie_temp);
}

void WindowDevice::refresh_button(QAbstractButton* w,int id, bool value, bool enable){
    lessener=false;
    w->setEnabled(true);
     if(pointer[id]!=value){ w->click();
     pointer[id] = value;}
     w->setEnabled(enable);
    lessener=true;
}
bool WindowDevice::revalue(bool b){
    return !b;
}
void WindowDevice::on_click(int value){
    if(lessener==true){
    pointer[value]=!pointer[value];
    refresh(value);
    }
}

void WindowDevice::on_cb_wilgotnosc_clicked()
{
     on_click(box_wilgotnosc);
     on_click(box_wilgotnosc_temp);
}

void WindowDevice::on_cb_termometr_zew_clicked()
{
     on_click(box_ter_zew);
     on_click(box_ter_zew_temp);
}

void WindowDevice::on_cb_termometr_wew_clicked()
{
     on_click(box_ter_wew);
     on_click(box_ter_wew_temp);
}


void WindowDevice::on_Skala_valueChanged(int value)
{
    valueTime=value;
    refresh(Scala);
}

void WindowDevice::on_wynik_editingFinished()
{
    if(ui->wynik->text().toInt()>0)
    valueTime=ui->wynik->text().toInt();
    refresh(Scala);
}

void WindowDevice::on_wynik_selectionChanged()
{
    ui->wynik->setText("");
}

void WindowDevice::on_le_name_editingFinished()
{
    nameDevice = ui->le_name->text();
}

