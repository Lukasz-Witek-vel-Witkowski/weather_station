#include "option.h"
#include "ui_option.h"

Option::Option(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Option)
{
    ui->setupUi(this);
}

Option::~Option()
{
    delete ui;
}
