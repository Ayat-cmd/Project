#ifndef SECOND_WINDOW_H
#define SECOND_WINDOW_H

#include <QDialog>
#include "save_data.h"

namespace Ui {
class Second_Window;
}

class Second_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Second_Window(QWidget *parent = nullptr);
    ~Second_Window();

    //Создание продукта или установка кол-ва сотрудников для сборки продукта
    void create_Product(Worker &work, Storage &sklad);
    //выбор способа удаление сотрудников
    void Delete();
    //Поиск и удаление по ФИО
    void Delete_Worker();
    //Поиск и удаление сотрудника по номеру телефона
    void Delete_Worker_Phone();
    //Устанока зарплаты сотрудникам или цены на продукты. Просмотр цен на товары
    void zp_Cost(Worker &work, Storage &sklad, Supplier &sup);

private slots:
    //Кнопка ОК определяем какой из checkBox-сов выбрать
    void on_CreateProductCheck_Btn_clicked();

    //Вернуться в меню
    void on_backToMenu_Btn_clicked();

    /*Устанавливаем кол-во сотрудников собирающих бытовую технику*/
    void on_introduceWorker_Btn_clicked();

    //кнопка Назад возвращающая в окно выбора, создани продукта или установки кол-ва сотрудников
    void on_BackCreateProduct_Btn_clicked();

    //Кнопка возвращает в окно выбора, создани продукта или установки кол-ва сотрудников
    void on_backCreateProduct_btn_clicked();

    //Кнопка выбора какие продукты собрать
    void on_toCollect_Btn_clicked();

    //Собрать продукт
    void on_CollectProduct_Btn_clicked();

    //Кнопка назад, Вернутьс к выбору одного из продуктов которые хотим собрать
    void on_BackChoiceCreate_Btn_clicked();

    //Узнаем сколько сотрудников собирают один продукт
    void on_informationCountWorker_Create_stateChanged(int arg1);

    //Кнопка выбора поиска для удаления сотрудника по ФИО
    void on_to_SNP_delete_Btn_clicked();

    //Кнопка выбора поиска для удаления сотрудника по номеру телефона
    void on_to_Phone_delete_Btn_clicked();

    //Кнопка Врнуться обратно в меню
    void on_back_toMenu_clicked();

    //Кнопка запуска процесса поиска сотрудника по ФИО
    void on_FindWorker_delete_Btn_clicked();

    //Кнопка Возвращает к выбору поиска сотрудника для удаления
    void on_back_Choce_Find_delete_Btn_clicked();

    //Строка поиска по фамилии
    void on_FindLastName_textChanged(const QString &arg1);

    //строка поиска по имени
    void on_FindName_textChanged(const QString &arg1);

    //Строка поиска по Отчеству
    void on_FindPatronymic_textChanged(const QString &arg1);

    //Кнопка поиска сотрудника, по номеру телефона, для удаления
    void on_FindWorkerPhone_delete_clicked();

    //Кнопка Возвращает к выбору поиска сотрудника для удаления
    void on_Back_Choce_Find_delete_btn_clicked();

    //Строка поиска сотрудника по номеру телефона
    void on_find_phone_line_textChanged(const QString &arg1);

    //Кнопка Вернуться в меню
    void on_Back_Btn_clicked();

    //Установка зарплаты сотрудникам
    void on_install_zpWorker_check_stateChanged(int arg1);

    //Установка цен на продукты
    void on_install_costProduct_check_stateChanged(int arg1);

    //Просмотр стоимости товаров
    void on_Print_costProduct_check_stateChanged(int arg1);

    //Кнопка Выбрать для перехода с выбора на что установить цену, на установку цены
    void on_CostProduct_check_btn_clicked();

    //Отмена выбранных галочек(убираем галочки) для установки цен на продукты
    void on_cancel_Btn_clicked();

    //Кнопка Назад к выбору установки цен на продукт
    void on_Baack_install_cost_Btn_clicked();

    //Строка ввода цены на продукт
    void on_CostProduct_line_textChanged(const QString &arg1);

    //Кнопка Установки цен на продукты
    void on_CostProduct_btn_clicked();

    //Кнопка установки зарплаты сотрудникам
    void on_ZP_Btn_clicked();

    //Проверка строки установки зарплаты сотрудникам на пустату
    void on_zp_line_textChanged(const QString &arg1);

    //проверка строки кол-ва кофемолок, которые надо собрать
    void on_elKof_line_textChanged(const QString &arg1);

    //Проверка строки кол-ва блендеров которые надо собрать
    void on_countCreate_elBL_line_textChanged(const QString &arg1);

    //Проверка строки кол-ва мясорубок, которые надо собрать
    void on_elMyasoR_line_textChanged(const QString &arg1);

    //проверка строки на ввод, кол-ва сотрудников собирающих продукты
    void on_introduceCountWorker_line_textChanged(const QString &arg1);

private:
    Ui::Second_Window *ui;
    Supplier *_sup;
    Worker *_work;
    Storage *_sklad;
    Save_Data *_save;

    int N_Employees; //Количество сотрудников которое будет собирать продукты
    int count_product_create;
    QString str_product;
    QString find_name;
    QString find_surname;
    QString find_patronymic;
    QString find_phone;

    QString str;
    unsigned int zp; //Зарплата
    unsigned cost; //цена продукта
    int n;   // Помогает выбрать условие

    //Завершение сборки продукта
    void collect_product_finish();
    //Убираем галоочки с выбора сборки
    void ChoiceCollectProduct_setChecked_false();

signals:
    void Delete_findSNP_Signal(QString &find_surname, QString &find_name, QString &find_patronymic);

    int Delete_findPhone_Signal(QString &Phone_find);
};

#endif // SECOND_WINDOW_H
