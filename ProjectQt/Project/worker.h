#ifndef WORKER_H
#define WORKER_H

#include <QDialog>
#include "supplier.h"
#include "print_workers.h"
#include "find_employee.h"
#include <QItemDelegate>

namespace Ui {
class Worker;
}
/*Нужно создать свой делегат на основе QItemDelegate и установить его для таблицы при помощи setItemDelegate(...).*/
/*Делаем Делегатор, ввода только цифр в дальнейшем пригодится для 4-го столбца QTableWidget(Добавление сотрудников)*/
class CChoicePathDelegate : public QItemDelegate
{
public:
    CChoicePathDelegate (QObject *parent = 0);
    /*нужно переопределить один метод - createEditor, создать редактор ячеек (QLineEdit), установить нужное регулярное выражение ввода:*/
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem& /*&option*/,
                          const QModelIndex& /*&index*/) const;
};

class Str : public QItemDelegate
{
public:
    Str (QObject *parent = 0);
    /*нужно переопределить один метод - createEditor, создать редактор ячеек (QLineEdit), установить нужное регулярное выражение ввода:*/
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem& /*&option*/,
                          const QModelIndex& /*&index*/) const;
};

class Worker : public QDialog
{
    Q_OBJECT

public:
    explicit Worker(QWidget *parent = nullptr);
    ~Worker();

private://Если ошибка поменяй на паблик
    Ui::Worker *ui;
    Print_Workers *printWorkers;
    Find_employee *find_worker;

    /*Окно Выбора каким способом удалить сотрудников если номера совпали у нескольких сотрудников*/
    int Choice_or_All_delete();

public://Открытая часть класса
    void DataEntry_worker(QVector<QString> &surename, QVector<QString> &name, QVector<QString> &Ochestvo, QVector<QString> &phone)
    {
        _Surname = surename;
        _Name = name;
        _Patronymic = Ochestvo;
        _Phone = phone;
    }

    //Поиск и удаление сотрудника по ФИО
    void Delete_Worker(QString d_surname, QString d_name, QString d_ochestvo);//Удаление сотрудников
    //Удалить сотрудника по номеру телефона
    int Delete_Worker_PHONE(QString d_phone);
    void Find_SureNameOches();//Поиск сотрудника по ФИО
    void find_Phone(unsigned long int phone);//Поиск сотрудника по номеру телефона
    void ZP_Work(unsigned int zp) {_zp = zp;}//Установление зарплаты

    void Print();//Вывод всех данных о сотрудниках

    QVector<QString> Get_Work() {return _Surname;}
    QVector<QString> Get_Work_Name() {return _Name;}
    QVector<QString> Get_Work_Ochestvo() {return _Patronymic;}
    QVector<QString> Get_Work_Phone() {return _Phone;}
    unsigned int Get_Work_ZP() {return _zp;};
private slots:
    //Окно кол-во сотрудников
    //Устанавливаем кол-во сотрудников
    void on_countWorker_clicked();

    //ОКно Новый сотрудник
    //Кнопка Устанавливает нового сотрудника
    void on_newWork_btn_clicked();

    //Окно Количество добавляеых сотрудников
    //Кнопка записи сотрудников в базу
    void on_saveWorker_clicked();

    //Окно Выбора каким способ добавлять сотрудников
    //Кнопка помогающая выбрать способ добавления сотрудника
    void on_OK_clicked();

    //Окно удаления сотрудника
    //Кнопка переходит по выбронному checkBox-су удаления
    void on_delete_phone_Btn_clicked();

    //Окно уволить сотрудника
    //Кнопка удаления выбранного сотрудника
    void on_ChoiceDelete_Btn_clicked();

    //ОКкно где мы Задаем кол-во сотрудников
    //проверка ввода кол-ва добавляемых сотрудников
    void on_worker_textChanged(const QString &arg1);

    //Окно новый сотрудник
    //Проверка ввода фамилии
    void on_surname_textChanged(const QString &arg1);

    //Окно новый сотрудник
    //Проверка ввода имени
    void on_name_textChanged(const QString &arg1);

    //Окно новый сотрудник
    //Проверка ввода отчества
    void on_patronymic_textChanged(const QString &arg1);

    //Окно новый сотрудник
    //Проверка ввода номера телефона
    void on_phone_textChanged(const QString &arg1);

    //Окно новый сотрудник
    //кнопка возвращает к окну выбора добавления сотрудника
    void on_Back_ChoiceAddWorker_Btn_clicked();

    //Окно уволить сотрудника
    //Кнопка возвращает к окну выбора каким из способов уволить сотрудника
    void on_back_Choice_DeleteWorker_Btn_clicked();

    //Окно Добавить одного сотрудника или несколько
    //Кнопка Отмены закрывает окно
    void on_cancel_clicked();

    /*Окно Увольнение сотрудника(ов) по выбору либо уволить все найденных сотрудников, либо выбрать кого уволить*/
    //Кнопка возвращает к окну Поиск сотрудника по номеру телефона для удаления
    void on_back_find_worker_phone_delete_clicked();

    //ОКкно где мы Задаем кол-во сотрудников
    //Кнопка закрытия окна
    void on_close_Btn_clicked();

    void on_deleteWorker_line_textChanged(const QString &arg1);

public slots:
    //Добавление нового сотрудника
    void addWorkSlot();

    //Окно Количество сотрудников
    //Задаем кол-во добавляемых сотрудников
    void WorkerSlot();

    // добавление сотрудника
    void ChoiceSlot();

private://Закрытая часть класса
//protected:
    //Временные переменные
    QVector<QString> _Name;
    QVector<QString> _Surname;
    QVector<QString> _Patronymic;
    QVector<QString> _Phone;
    unsigned int _zp;
    int flag = 0;//помогает записать нужную строку
    int i;
    int tmp;//для смещения ячейки для удаления
    QString str;
    bool del; //для определения какая кнопка нажата в окне выбора как удалить сотрудника
    QString delete_phone;
    bool click_Choice_DeleteWorker;

signals:
    void find_emloyee_Signal(QVector<QString> &_Name, QVector<QString> &_Surname,  QVector<QString> &_Patronymic, QVector<QString> _Phone);
};

#endif // WORKER_H
