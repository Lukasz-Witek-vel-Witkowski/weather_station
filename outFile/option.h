#ifndef OPTION_H
#define OPTION_H
#include <QtWidgets/QMainWindow>
#include <QtXml>
namespace Ui {
class Option;
}

class Option : public QMainWindow
{
    Q_OBJECT

public:
    explicit Option(QWidget *parent = nullptr);
    ~Option();

private:
    Ui::Option *ui;
    QDomDocument* _xml = nullptr;
};

#endif // OPTION_H
