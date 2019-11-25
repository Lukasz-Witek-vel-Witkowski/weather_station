#include "windowmain.h"
#include "ui_windowmain.h"

WindowMain::WindowMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowMain)
{
    ui->setupUi(this);
    tableViewModel = new QStandardItemModel(ui->Tab);
    ui->Tab->setModel(tableViewModel);
    iterator =0;
    messagebox = false;
    configurationTable();
    ui->Rad_actual->click();
}

WindowMain::~WindowMain()
{
    delete ui;
}
void WindowMain::refresh(int id){

    switch(id){
    case idRadActualy:
        ui->Le_size->setEnabled(false);
        ui->Le_time->setEnabled(false);
        ui->Le_gora->setEnabled(true);
        ui->Suwak->setEnabled(true);
        refresh(idSuwak);
        break;
    case idRadPersonal:
        ui->Le_size->setEnabled(true);
        ui->Le_time->setEnabled(true);
        //ui->Le_size->setText(le_size);
        //ui->Le_time->setText(le_time);
        ui->Suwak->setEnabled(false);
        ui->Le_gora->setEnabled(false);
        break;
    case idSuwak:
        value = unsigned(ui->Suwak->value());
        refresh(idtextGora);
        break;
    case idtextGora:
        QString data;
        switch(value){
        case 1:     data = "2";     value = 1;      break;
        case 2:     data = "4";     value = 2;      break;
        case 3:     data = "6";     value = 3;      break;
        case 4:     data = "8";     value = 4;      break;
        case 5:     data = "10";    value = 5;      break;
        case 6:     data = "20";    value = 10;     break;
        case 7:     data = "30";    value = 15;     break;
        case 8:     data = "40";    value = 20;     break;
        case 9:     data = "50";    value = 25;     break;
        case 10:    data = "60";    value = 30;     break;
        }
        ui->Le_gora->setText(data+sekunda);
        break;
    }

}
void WindowMain::on_Rad_actual_clicked()
{
    refresh(idRadActualy);
}

void WindowMain::on_Rad_personal_clicked()
{
    refresh(idRadPersonal);
}

void WindowMain::on_Le_time_editingFinished()
{
   le_time = actualyText(ui->Le_time->text());
   ui->Le_time->setText(le_time+sekunda);
}

void WindowMain::on_Le_size_editingFinished()
{
    le_size = actualyText(ui->Le_size->text());
}

void WindowMain::on_Suwak_valueChanged(int x)
{
    value = unsigned(x);
    refresh(idtextGora);
}
QString WindowMain::actualyText(QString arg, int pointer){
    qDebug()<<arg;
     std::string data;
    switch(pointer){
   case 1:
    int i;
    for(i=0; i<arg.length();i++){
        if(arg[i]==' '){
            for(int j=(++i);j<arg.length();j++){
                if(arg[j]!='['&&arg[j]!='s'&&arg[j]!=']'){
                    data = arg.toStdString();
                    data.erase(data.begin()+j);
                }
            }
            return QString::fromStdString(data);
        }
        if((arg[i]>'9'||arg[i]<'0')){
            std::string data = arg.toStdString();
            data.erase(data.begin()+i);
          return QString::fromStdString(data);
        }
    }
        break;
    }
    return arg;
}
/*void WindowMain::on_Le_time_textChanged(const QString &arg1)
{
    ui->Le_time->setText(actualyText(arg1));
}*/
void WindowMain::setData(unsigned int id,double t_w, double t_z, double w, double c,int day, int month, int year, int h, int m, int s){
    iterator++;
    if(iterator>=value){
        iterator = 0;
      }
    else    return;
    messagebox = false;
    iter_value++;
    ui->text_external->setText(QString::number(t_z,'f',2));
    ui->text_internal->setText(QString::number(t_w,'f',2));
    ui->text_humidi->setText(QString::number(w,'f',2));
    ui->text_Pressure->setText(QString::number(c,'f',2));
    ui->text_time->setText(QString::number(day)+"-"+QString::number(month)+"-"+QString::number(year)+" "+QString::number(h)+":"+QString::number(m)+":"+QString::number(s));
    DateTime datetime(day,month, year,h,m,s);
    if(iter_value<=size_measurement){
        V_measurement[iter_value-1].update(id,t_w,t_z,w,c,datetime);
    }
    else{
        update();
        V_measurement[size_measurement-1].update(id,t_w,t_z,w,c,datetime);
    }
        for(unsigned int i=0; i<size_measurement; i++)
            V_measurement[i].setTableWidget(i,tableViewModel);
}
void WindowMain::update(){
    for(unsigned int i=0; i<size_measurement-1; i++){
        V_measurement[i].update(V_measurement[i+1]);
    }
}
void WindowMain::configurationTable(unsigned int i_value){
    tableViewModel->clear();
    size_measurement = i_value;
    iter_value =0;
    tableViewModel->setColumnCount(4);
    V_measurement = new Measurement[i_value];
    tableViewModel->setHorizontalHeaderLabels({"T wewnętrzny", "T zwnętrzny",
                                              "Wilgotność", "Ciśnienie"});
    ui->Tab->setColumnWidth(0,87);
    ui->Tab->setColumnWidth(1,87);
    ui->Tab->setColumnWidth(2,87);
    ui->Tab->setColumnWidth(3,87);
    ui->Tab->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->Tab->setSelectionBehavior(QAbstractItemView::SelectRows); // ustawiam zaznaczanie całych wierszy
    ui->Tab->setSelectionMode(QAbstractItemView::SingleSelection);
}

void WindowMain::on_Le_gora_editingFinished()
{
    if(messagebox==true) return;
qDebug()<<"Le_gora_editingFinished"<<ui->Le_gora->text();
    le_gora=actualyText(ui->Le_gora->text());
    if(3600 < le_gora.toInt()&&messagebox==false){
        messagebox=true;
        QMessageBox::StandardButton przycisk = QMessageBox::question(this,"Nie właściwa wartość",
                                      "Maksymalnie można ustawić na 3600[s]!, Ustawić wartość na 3600[s]?",
                                      QMessageBox::Yes|QMessageBox::No);
        if(przycisk==QMessageBox::Yes){
            ui->Le_gora->setText("3600[s]");
            le_gora ="3600";
        }
        else if(przycisk==QMessageBox::No){
            refresh(idtextGora); return;
        }
    }
    else if(0>=le_gora.toInt()&&messagebox==false){
        messagebox = true;
        QMessageBox::StandardButton przycisk = QMessageBox::question(this,"Nie właściwa wartość",
                                      "Minimalnie można ustawić na 2[s]!, Ustawić wartość na 2[s]?",
                                      QMessageBox::Yes|QMessageBox::No);
        if(przycisk==QMessageBox::Yes){
            ui->Le_gora->setText("2[s]");
            le_gora = "2";
        }
        else if(przycisk==QMessageBox::No){
            refresh(idtextGora); return;
        }

    }
    ui->Le_gora->setText(le_gora+sekunda);
    value = unsigned(le_gora.toInt()/2);
}

/*void WindowMain::on_Le_gora_textChanged(const QString &arg1)
{
    ui->Le_gora->setText(actualyText(arg1));
}*/
