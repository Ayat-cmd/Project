#ifndef PRINT_WORKERS_H
#define PRINT_WORKERS_H

#include <QDialog>

namespace Ui {
class Print_Workers;
}

class Print_Workers : public QDialog
{
    Q_OBJECT

public:
    explicit Print_Workers(QWidget *parent = nullptr);
    ~Print_Workers();

private:
    Ui::Print_Workers *ui;

public slots:
    //Установка данных списка сотрудников
    void DataWorkers_slot(QString &str);
private slots:
    //кнопка ок закрывает окно вывода списка сотрудников
    void on_printWorker_btn_clicked();
};

#endif // PRINT_WORKERS_H
