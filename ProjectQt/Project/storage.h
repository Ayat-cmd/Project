#ifndef STORAGE_H
#define STORAGE_H

#include <QDialog>
#include "worker.h"


namespace Ui {
class Storage;
}

class Storage : public QDialog
{
    Q_OBJECT

public:
    explicit Storage(QWidget *parent = nullptr);
    ~Storage();

public:
    Ui::Storage *ui;
    Supplier *sup_to_sklad;

private:
    //Кол-во собранных продуктов
    int quantity_elekCoffee;
    int quantity_elekBlender;
    int quantity_elekMyasoR;
    //Временная переменная
    int tmp;
    //Стоимость собранных продуктов
    uint cost_elekCoffee;
    uint cost_elekBlender;
    uint cost_elekMyasoR;

    //Общая стоимость проданных продуктов бытовой техники за все время
    uint total_cost_elekCoffee;
    uint total_cost_elekBlender;
    uint total_cost_elekMyasoR;

    //Кол-во проданных продуктов за все время
    int quantity_SEllelekCoffee;
    int quantity_SEllelekBlender;
    int quantity_SEllelekMyasoR;

    QString str;

public:
    //Устанавливаем общую стоимость проданных продуктов бытовой техники
    void set_total_costSell_elekCoffee(uint costTotal) {total_cost_elekCoffee += costTotal;}
    void set_total_costSell_elekBlender(uint costTotal){total_cost_elekBlender += costTotal;}
    void set_total_costSell_elekMyasoR(uint costTotal) {total_cost_elekMyasoR += costTotal;}
    //Возвращыем общую стоимость проданных продуктов бытовой техники
    uint get_total_costSell_elekCoffee(){return total_cost_elekCoffee;}
    uint get_total_costSell_elekBlender(){return total_cost_elekBlender;}
    uint get_total_costSell_elekMyasoR(){return total_cost_elekMyasoR;}
    //Возвращаем кол-во проданных товаров за все время
    int get_quantity_SEllelekCoffee(){return quantity_SEllelekCoffee;}
    int get_quantity_SEllelekBlender(){return quantity_SEllelekBlender;}
    int get_quantity_SEllelekMyasoR(){return quantity_SEllelekMyasoR;}

    //Собираем электрическую кофемолку
    void collect_ElekCoffee(unsigned int n, Worker &work, const int N_Employees);
    //Собираем Электрический блендер
    void collect_ElekBlender(unsigned int n, Worker &work, const int N_Employees);
    //Собираем электрическую мясорубку
    void collect_ElekMyasoR(unsigned int n, Worker &work, const int N_Employees);

    //Общая стоимость заказанных деталей за все время
    void set_Total_costOrder_elCoffee(uint total_cost) {total_cost_ordered_kits_Cof += total_cost;}
    void set_Total_costOrder_elBlender(uint total_cost) {total_cost_ordered_kits_Bl += total_cost;}
    void set_Total_costOrder_elMyasoR(uint total_cost) {total_cost_ordered_kits_MyasR += total_cost;}

    uint get_Total_costOrder_elCoffee() {return total_cost_ordered_kits_Cof;}
    uint get_Total_costOrder_elBlender(){return total_cost_ordered_kits_Bl;}
    uint get_Total_costOrder_elMyasoR() {return total_cost_ordered_kits_MyasR;}

    //Собираем эл. Мясорубку
    //Собираем эл. Блендер
    void collect_elBlelMyas(uint bl, uint myas, Worker &work, const int N_Employees);
    //Собираем эл. Блендер
    //Собираем эл. Кофемлку
    void collect_elBlelCof(uint bl, uint kof, Worker &work, const int N_Employees);
    //Собираем эл. Кофемлку
    //Собираем эл. Мясорубку
    void collect_elMyaselCof(uint myas, uint kof, Worker &work, const int N_Employees);
    //Собираем все продукты
    void Collect_All_Product(uint kof, uint bl, uint myas, Worker &work, const int N_Employees);
    //Продажа N-го кол-ва продуктов
    void Sell_ElekCoffee(int kol);
    void Sell_ElekBlender(int kol);
    void Sell_ElekMyasoR(int kol);
    //установливаем стоимость собранных продуктов
    void Set_Cost_ElekCoffee(uint cost)       {cost_elekCoffee = cost;}
    void Set_Cost_ElekBlender(uint cost)      {cost_elekBlender = cost;}
    void Set_Cost_ElekMyasoR(uint cost)       {cost_elekMyasoR = cost;}
    //Возвращаем стоимость собранных продуктов
    uint Get_Cost_ElekCoffee()                {return cost_elekCoffee;}
    uint Get_Cost_ElekBlender()               {return cost_elekBlender;}
    uint Get_Cost_ElekMyasoR()                {return cost_elekMyasoR;}
    //Возвращаем кол-во собранных продуктов
    int Get_collected_ElekCoffee()           {return quantity_elekCoffee;}
    int Get_collected_ElekBlender()          {return quantity_elekBlender;}
    int Get_collected_ElekMyasoR()           {return quantity_elekMyasoR;}

    //Установить кол-во комлектов деталей
    void Set_kit_ElekCoffee(int kit_elekCoffee)
    {
        kit_ElekCoffee += kit_elekCoffee;
        count_kit_ElekCoffee += kit_elekCoffee;
    }
    void Set_kit_ElekBlender(int kit_elekBlender)
    {
        kit_ElekBlender += kit_elekBlender;
        count_kit_ElekBlender += kit_elekBlender;
    }
    void Set_kit_ElekMyasoR(int kit_elekMyasoR)
    {
        kit_ElekMyasoR += kit_elekMyasoR;
        count_kit_ElekMyasoR += kit_elekMyasoR;
    }
    //возвращает кол-во комплектов деталей
    int Get_kit_ElekCoffee()                      {return kit_ElekCoffee;}
    int Get_kit_ElekBlender()                     {return kit_ElekBlender;}
    int Get_kit_ElekMyasoR()                      {return kit_ElekMyasoR;}

    //Возвращаем кол-во деталей заказанных за все время
    uint get_count_kit_ElekCoffee() {return count_kit_ElekCoffee;}
    uint get_count_kit_ElekBlender() {return count_kit_ElekBlender;}
    uint get_count_kit_ElekMyasoR() {return count_kit_ElekMyasoR;}

    //Поставщик (Заказать комлект деталей, все данные поставщика)
    void Sklad(Supplier &sup);
    //Заказ деталей
    void kit_Detail(Supplier &sup);
    //состояние склада
    void condition_sklad();
    //Установить стоимость комлектов деталей
    int ChangeSupCostKit(Supplier &sup);
    //Продажа продукта
    void sell_product();
    //Очищаем всё, скрываем и закрываем окно
    void Default();
    //Вызываем метод смены некоторых данных поставщика
    int sklad_supplierDataChange(Supplier &sup);

    int num;

private:
    //Кол-во комлектов деталей
    uint kit_ElekCoffee;
    uint kit_ElekBlender;
    uint kit_ElekMyasoR;

    //Кол-ва деталей заказанных за все время
    uint count_kit_ElekCoffee;
    uint count_kit_ElekBlender;
    uint count_kit_ElekMyasoR;

    uint total_cost_ordered_kits_Cof;
    uint total_cost_ordered_kits_MyasR;
    uint total_cost_ordered_kits_Bl;

    int count;
    QString count_Worker; //Проверяем достаточно ли сотрудников чтобы собрать продукт(Ы)
private slots:
    //кнопка Ok обработка строки выбора
    void on_changeS_btn_clicked();

    //Кнопка "Закрыть" возвращающая к опции
    void on_pushButton_clicked();

    //Кнопка "меню" возвращат в меню
    void on_close_clicked();

    //Кнопка Ок обрабатывает строку kit_line куда мы ввели наш выбор заказа
    void on_kit_btn_clicked();

    //окно установки количества комплектов деталей
    //Кнопка ОК Устанавливаем количество деталей которые мы хотим получить
    void on_countKit_Btn_clicked();

    //окно установки количества комплектов деталей
    //Кнопка назад возвращает к выбору деталей которые хотим заказать
    void on_pushButton_2_clicked();

    //Окно состояние склада
    //Показать Окно кол-ва комплектов деталей
    void on_kit_detail_stateChanged(int arg1);

    //Окно состояние склада
    //Показать кол-во собранных продуктов
    void on_kit_product_stateChanged(int arg1);

    //Окно состояния склада
    //Кнопка назад в меню
    void on_back_Btn_clicked();

    //Фунция для продажи
    //окно sell_Box "Выбор продажи
    //Выбор продукта который хотим продать
    void on_sell_Btn_clicked();

    //Фунция для продажи
    //Окно sellProduct_Box "Продажа товара"
    //кнопка устанавливает сколько продуктов продать
    void on_sell_product_btn_clicked();

    //ОКно установки кол-ва продуктов для продаж
    //Возвращает к выбору продажи продукта
    void on_back_btn_clicked();

    //Окно выбора продукта для продаж
    //Возвращает в меню
    void on_menu_btn_clicked();

    //Окно выбора Заказа комплекта деталей
    //Проверка на ввод  строки выбора заказа
    void on_kit_line_textChanged(const QString &arg1);

    //Окно Установки количества комплектов деталей
    //Проверка на ввод спинбакса
    void on_countKit_Spin_textChanged(const QString &arg1);

    //Окно Опции
    //проверка на ввод строки выбора опции
    void on_supplierOrKit_textChanged(const QString &arg1);

    //Окно Установки кол-ва продуктов для продажи
    //Проверка на ввод строки кол-ва продуктов для продаж кофемолки
    void on_countSell_cof_line_textChanged(const QString &arg1);

    //Окно Установки кол-ва продуктов для продажи
    //Проверка на ввод строки кол-ва продуктов для продаж Блендера
    void on_countSell_Bl_line_textChanged(const QString &arg1);

    //Окно Установки кол-ва продуктов для продажи
    //Проверка на ввод строки кол-ва продуктов для продаж Мясорубки
    void on_countSell_MyasoR_line_textChanged(const QString &arg1);

    //Окно выбора продукта для Заказа
    //Возвращает обратно в опции
    void on_close_2_clicked();

    //Окно Установки количества комплектов деталей
    //Рассчет стоимости кол-ва комлекта деталей
    void on_total_cost_ordered_kits_clicked();

    //Окно Установки кол-ва продуктов для продаж
    //Рассчет стоимости кол-ва собранных продуктов для продаж
    void on_total_cost_sell_product_clicked();

public slots:
    //выводим данные поставщика
    void Print(Supplier &sup);

    //смена поставщика
    void ChangeSup_Slot(Supplier &sup);

signals:
    void clicked_changeS_Signal();

};

#endif // STORAGE_H
