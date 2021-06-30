#ifndef FIND_EMPLOYEE_H
#define FIND_EMPLOYEE_H

#include <QDialog>
#include <QMessageBox>
#include <print_workers.h>
#include <QLayout>
#include <QValidator>

namespace Ui {
class Find_employee;
}

class Find_employee : public QDialog
{
    Q_OBJECT

public:
    explicit Find_employee(QWidget *parent = nullptr);
    ~Find_employee();

    //Поиск сотрудника
    void Find_Worker(QVector<QString> &_Name, QVector<QString> &_Surname,  QVector<QString> &_Patronymic, QVector<QString> _Phone);


private slots:
    //Кнопка выбора поиска сотрудника
    void on_OkFind_Btn_clicked();

    //Кнопка поиска сотрудника по ФИО
    void on_OkFindSNP_Btn_clicked();

    //Кнопка поиска сотрудника по номмеру телефона
    void on_OkFindPhone_Btn_clicked();

    //Кнопка отмены выбора поиска и возврат в меню
    void on_pushButton_clicked();

    //Кнопка назад к выбору поиска
    void on_backFindSNP_Btn_clicked();

    //строка поиска фамилии не пуста
    void on_surnameFind_line_textChanged(const QString &arg1);

    //строка поиска имени не пуста
    void on_nameFind_line_textChanged(const QString &arg1);

    //строка поиска отчества не пуста
    void on_patranomicFind_line_textChanged(const QString &arg1);

    //строка поиска номера телефона не пуста
    void on_phoneFind_line_textChanged(const QString &arg1);

    void on_Back_find_to_phine_clicked();

private:
    Ui::Find_employee *ui;
    Print_Workers *print_find_worker;

    QVector<QString> Name;
    QVector<QString> Surname;
    QVector<QString> Patronymic;
    QVector<QString> Phone;
    QString res; //Записываем найденных сотрудников
    int flag;//для отслеживания повторов
    int tmp;//запоминаем позицию ячейки

signals:
    void DataWorkers_slot_Signal(QString &res);
};

#endif // FIND_EMPLOYEE_H
