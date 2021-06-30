#include "print_workers.h"
#include "ui_print_workers.h"

Print_Workers::Print_Workers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Print_Workers)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window
         | Qt::WindowMinimizeButtonHint
         | Qt::WindowMaximizeButtonHint
         | Qt::CustomizeWindowHint);//отключили кнопку закрытия окна [х]

}

Print_Workers::~Print_Workers()
{
    delete ui;
}

//Установка данных списка сотрудников
void Print_Workers::DataWorkers_slot(QString &str)
{
    show();
    //Устанавливаем список сотрудников str(Выводим данные)
    ui->printShowWorkers->setText(str);
    exec();
}

//кнопка ок закрывает окно вывода списка сотрудников
void Print_Workers::on_printWorker_btn_clicked()
{
    //отчищаем список
    ui->printShowWorkers->clear();
    //Закрываем окно
    close();
}
