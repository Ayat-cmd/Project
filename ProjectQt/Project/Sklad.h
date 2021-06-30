#ifndef SKLAD_H
#define SKLAD_H

#include <QDialog>
#include "worker.h"

namespace Ui {
class Storage;
}

class KitDetail : public QDialog //склад
{

    Q_OBJECT


public:
    //Конструктор
    KitDetail() : kit_ElekCoffee(0), kit_ElekBlender(0), kit_ElekMyasoR(0) {}
    //Установить кол-во комлектов деталей
    void Set_kit_ElekCoffee(int kit_elekCoffee)   {kit_ElekCoffee = kit_elekCoffee;}
    void Set_kit_ElekBlender(int kit_elekBlender) {kit_ElekBlender = kit_elekBlender;}
    void Set_kit_ElekMyasoR(int kit_elekMyasoR)   {kit_ElekMyasoR = kit_elekMyasoR;}
    //возвращает кол-во комплектов деталей
    int Get_kit_ElekCoffee()                      {return kit_ElekCoffee;}
    int Get_kit_ElekBlender()                     {return kit_ElekBlender;}
    int Get_kit_ElekMyasoR()                      {return kit_ElekMyasoR;}

protected:
    //Кол-во комлектов деталей
    int kit_ElekCoffee;
    int kit_ElekBlender;
    int kit_ElekMyasoR;
};

class Product : public KitDetail //Продукт бытовой техники
{

    Q_OBJECT

    //Кол-во собранных продуктов
    int quantity_elekCoffee;
    int quantity_elekBlender;
    int quantity_elekMyasoR;
    //Временная переменная
    int tmp;
    //Стоимость собранных продуктов
    unsigned cost_elekCoffee;
    unsigned cost_elekBlender;
    unsigned cost_elekMyasoR;
public:

    //Конструктор
//    Product() { quantity_elekCoffee = NULL; }
    //Собираем электрическую кофемолку
    void collect_ElekCoffee(unsigned int n, Worker &work, const int N_Employees);
    //Собираем Электрический блендер
    void collect_ElekBlender(unsigned int n, Worker &work, const int N_Employees);
    //Собираем электрическую мясорубку
    void collect_ElekMyasoR(unsigned int n, Worker &work, const int N_Employees);
    //Собираем все продукты
    void Collect_All_Product(unsigned int kof, unsigned int bl, unsigned int myas, Worker &work, const int N_Employees);
    //Продажа N-го кол-ва продуктов
    void Sell_ElekCoffee(int kol);
    void Sell_ElekBlender(int kol);
    void Sell_ElekMyasoR(int kol);
    //установливаем стоимость собранных продуктов продуктов
    void Set_Cost_ElekCoffee(unsigned cost)       {cost_elekCoffee = cost;}
    void Set_Cost_ElekBlender(unsigned cost)      {cost_elekBlender = cost;}
    void Set_Cost_ElekMyasoR(unsigned cost)       {cost_elekMyasoR = cost;}
    //Возвращаем стоимость собранных продуктов продуктов
    unsigned Get_Cost_ElekCoffee()                {return cost_elekCoffee;}
    unsigned Get_Cost_ElekBlender()               {return cost_elekBlender;}
    unsigned Get_Cost_ElekMyasoR()                {return cost_elekMyasoR;}
    //Возвращаем кол-во собранных продуктов
    int Get_collected_ElekCoffee()           {return quantity_elekCoffee;}
    int Get_collected_ElekBlender()          {return quantity_elekBlender;}
    int Get_collected_ElekMyasoR()           {return quantity_elekMyasoR;}
};

class Storage : public Product
{
    Q_OBJECT

public:
    explicit Storage(QWidget *parent = nullptr);
    ~Storage();

protected slots:
    void on_changeS_btn_clicked(Supplier &sup);

private:
    Ui::Storage *ui;

public:
    void quantity_kit_detail();//Метод просмотра кол-ва всех деталей на складе
    void quantity_product();//Метод просмотра кол-ва всех собранных продуктов

};


#endif // SKLAD_H
