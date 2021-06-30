#ifndef SAVE_DATA_H
#define SAVE_DATA_H

#include <QDialog>
#include "storage.h"
#include <QFile>
#include <QTextStream>

namespace Ui {
class Save_Data;
}

class Save_Data : public QDialog
{
    Q_OBJECT

public:
    explicit Save_Data(QWidget *parent = nullptr);
    ~Save_Data();

    void SaveData(Worker &work, Supplier &sup, Storage &sklad);

private slots:
    //возвращаемся в меню
    void on_to_Menu_clicked();

    //Записать данные в файл
    void on_to_File_btn_clicked();

    //Проверка на пустоту
    void on_worker_toFile_line_textChanged(const QString &arg1);

    //Проверка на пустоту
    void on_supCost_toFile_line_textChanged(const QString &arg1);

    //Проверка на пустоту
    void on_kitProductCost_toFile_line_textChanged(const QString &arg1);

public:
    void Save_Data_toFile_W(QString fileNameW);//Сохранение данных в файл о сотрудниках
    //Сохранение данных в файл о поставщике и продуктах в складе
    void Save_Data_toFile_SP(QString fileNameS, QString fileNameP);

private:
    Ui::Save_Data *ui;
    Worker *work_save;
    Supplier *sup_save;
    Storage *sklad_save;

    int i = 0;//для цикла
    uint cost_elCof;
    uint cost_elBl;
    uint cost_elMyas;

    QString fileName_W, fileName_S, fileName_P; //путь к файлам
};

#endif // SAVE_DATA_H
