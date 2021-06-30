#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QValidator>
#include <QLayout>

namespace Ui {
class Supplier;
}

class Supplier : public QDialog
{
    Q_OBJECT

public:
    explicit Supplier(QWidget *parent = nullptr);
    ~Supplier();

    //Р’РІРѕРґ РїРѕСЃС‚Р°РІС‰РёРєР°
    void supplierEnter();

    //РЈСЃС‚Р°РЅРѕРІРєР° С†РµРЅ РЅР° РєРѕРјР»РµРєС‚С‹ РґРµС‚Р°Р»РµР№
    int Install_costKitDetail();

private slots:
    //РѕРєРЅРѕ РІРІРѕРґР° РґР°РЅРЅС‹С… РїРѕСЃС‚Р°РІС‰РёРєР°
    //РєРЅРѕРїРєР° РћРљ СѓСЃС‚Р°РЅР°РІР»РёРІР°РµС‚ РґР°РЅРЅС‹Рµ РїРѕСЃС‚Р°РІС‰РёРєР°
    void on_writeSup_Btn_clicked();

    //РћРєРЅРѕ ChangeDataSup (Р’С‹Р±РёСЂР°РµРј РєР°РєРёРµ РґР°РЅРЅС‹Рµ РёР·РјРµРЅРёС‚СЊ РїРѕСЃС‚Р°РІС‰РёРєСѓ)
    //РљРЅРѕРїРєР° Р’С‹Р±СЂР°С‚СЊ РЈСЃС‚Р°РЅР°РІР»РёРІР°РµРј РЅР°С€ РІС‹Р±РѕСЂ С‚РѕРіРѕ С‡С‚Рѕ РјС‹ С…РѕС‚РёРј РёР·РјРµРЅРёС‚СЊ
    void on_Supp_PhSNP_btn_clicked();

    //РћРєРЅРѕ NewDataSup (РР·РјРµРЅСЏРµРј РґР°РЅРЅС‹Рµ РїРѕСЃС‚Р°РІС‰РёРєР°)
    //РљРЅРѕРїРєР° РћРє СѓСЃС‚Р°РЅР°РІР»РёРІР°РµС‚ РЅРѕРІС‹Рµ РґР°РЅРЅС‹Рµ РїРѕСЃС‚Р°РІС€РёРєР°
    void on_new_DataSup_btn_clicked();

    //РЈСЃС‚Р°РЅРѕРІРєР° С†РµРЅ РЅР° РєРѕРјР»РµРєС‚С‹ РґРµС‚Р°Р»РµР№
    //РљРЅРѕРїРєР° РЈСЃС‚Р°РЅР°РІР»РёРІР°РµС‚ С†РµРЅСѓ РЅР° РєСЂРјР»РµРєС‚С‹ РґРµС‚Р°Р»РµР№
    void on_costKit_Btn_clicked();

    //РћРєРЅРѕ setSupplier(Р’РІРѕРґ РґР°РЅРЅС‹С… РїРѕСЃС‚Р°РІС‰РёРєР°)
    //РџСЂРѕРІРµСЂРєР° РЅР° РІРІРѕРґ СЃС‚СЂРѕРєРё
    void on_Surname_textChanged(const QString &arg1);

    //РћРєРЅРѕ setSupplier(Р’РІРѕРґ РґР°РЅРЅС‹С… РїРѕСЃС‚Р°РІС‰РёРєР°)
    //РџСЂРѕРІРµСЂРєР° РЅР° РІРІРѕРґ СЃС‚СЂРѕРєРё
    void on_Name_textChanged(const QString &arg1);

    //РћРєРЅРѕ setSupplier(Р’РІРѕРґ РґР°РЅРЅС‹С… РїРѕСЃС‚Р°РІС‰РёРєР°)
    //РџСЂРѕРІРµСЂРєР° РЅР° РІРІРѕРґ СЃС‚СЂРѕРєРё
    void on_Patronymic_textChanged(const QString &arg1);

    //РћРєРЅРѕ setSupplier(Р’РІРѕРґ РґР°РЅРЅС‹С… РїРѕСЃС‚Р°РІС‰РёРєР°)
    //РџСЂРѕРІРµСЂРєР° РЅР° РІРІРѕРґ СЃС‚СЂРѕРєРё
    void on_numberPhone_textChanged(const QString &arg1);

    //РћРєРЅРѕ РІРІРѕРґР° РґР°РЅРЅС‹С… РїРѕСЃС‚Р°РІС‰РёРєР°
    // РєРЅРѕРїРєР° Р’РµСЂРЅСѓС‚СЊСЃСЏ РІ РјРµРЅСЋ
    void on_Close_WriteSup_Btn_clicked();

 ///////  // void on_ElCoffeeM_textChanged(const QString &arg1);

    //РћРєРЅРѕ РЈСЃС‚Р°РЅРѕРІРєР° С†РµРЅ РЅР° РєРѕРјРїР»РµРєС‚С‹ РґРµС‚Р°Р»РµР№
    //РџСЂРѕРІРµСЂРєР° РЅР° РІРІРѕРґ СЃС‚СЂРѕРєРё
    void on_kof_line_textChanged(const QString &arg1);

    //РћРєРЅРѕ РЈСЃС‚Р°РЅРѕРІРєР° С†РµРЅ РЅР° РєРѕРјРїР»РµРєС‚С‹ РґРµС‚Р°Р»РµР№
    //РџСЂРѕРІРµСЂРєР° РЅР° РІРІРѕРґ СЃС‚СЂРѕРєРё
    void on_Bl_line_textChanged(const QString &arg1);

    //РћРєРЅРѕ РЈСЃС‚Р°РЅРѕРІРєР° С†РµРЅ РЅР° РєРѕРјРїР»РµРєС‚С‹ РґРµС‚Р°Р»РµР№
    //РџСЂРѕРІРµСЂРєР° РЅР° РІРІРѕРґ СЃС‚СЂРѕРєРё
    void on_MyasR_line_textChanged(const QString &arg1);

    //РћРєРЅРѕ РІС‹Р±РѕСЂР° РєР°РєРёРµ РґР°РЅРЅС‹Рµ РїРѕСЃС‚Р°РІС‰РёРєР° РёР·РјРµРЅРёС‚СЊ
    //РџСЂРѕРІРµСЂРєР° РЅР° РІРІРѕРґ СЃС‚СЂРѕРєРё
    void on_dataSuppChange_textChanged(const QString &arg1);

    //РћРєРЅРѕ РЅРѕРІС‹Рµ РґР°РЅРЅС‹Рµ РїРѕСЃС‚Р°РІС‰РёРєР° РєРѕС‚РѕСЂС‹Рµ РјС‹ СЃРѕР±РёСЂР°РµРјСЃСЏ СѓСЃС‚Р°РЅРѕРІРёС‚СЊ
    //РџСЂРѕРІРµСЂРєР° РЅР° РІРІРѕРґ СЃС‚СЂРѕРєРё
    void on_newDataSup_textChanged(const QString &arg1);

    //РћРєРЅРѕ СѓСЃС‚Р°РЅРѕРІРєР° С†РµРЅ РЅР° РєРѕРјРїР»РµРєС‚С‹ РґРµС‚Р°Р»РµР№
    //РљРЅРѕРїРєР° РІРѕР·РІСЂР°С‰Р°РµС‚ РѕР±СЂР°С‚РЅРѕ РІ РћРїС†РёРё
    void on_back_costKit_Btn_clicked();

    //РћРєРЅРѕ РІС‹Р±РёСЂР°РµРј С‡С‚Рѕ РёР·РјРµРЅРёС‚СЊ Сѓ РїР°СЃС‚РѕРІС‰РёРєР°, РєР°РєРёРµ РґР°РЅРЅС‹Рµ РёР·РјРјРµРЅРёС‚СЊ
    //РљРЅРѕРїРєР° РІРѕР·РІСЂР°С‰Р°РµС‚ РІ РѕРєРЅРѕ РћРїС†РёРё
    void on_back_Option_Btn_clicked();

    //РћРєРЅРѕ РёР·РјРµРЅСЏРµРј РґР°РЅРЅС‹Рµ РїРѕСЃС‚Р°РІС‰РёРєР° РїРѕ РІС‹Р±РѕСЂСѓ
    //РљРЅРѕРїРєР° РІРѕР·РІСЂР°С‰Р°РµС‚ РІ РѕРєРЅРѕ РІС‹Р±РёСЂР°РµРј С‡С‚Рѕ РёР·РјРµРЅРёС‚СЊ Сѓ РїР°СЃС‚РѕРІС‰РёРєР°, РєР°РєРёРµ РґР°РЅРЅС‹Рµ РёР·РјРјРµРЅРёС‚СЊ
    void on_back_ChangeDataSup_Btn_clicked();

private:
    Ui::Supplier *ui;

public:
    //РјРµС‚РѕРґ СЃРјРµРЅС‹ РЅРµРєРѕС‚РѕСЂС‹С… РґР°РЅРЅС‹С… РїРѕСЃС‚Р°РІС‰РёРєР°
    int _supplierDataChange();
    void _Print();//Р’С‹РІРѕРґ РІСЃРµС… РґР°РЅРЅС‹С… Рѕ РїРѕСЃС‚Р°РІС‰РёРєРµ

    QVector<QString> Get_Supplier() {return _Supplier;}
    //РњРµС‚РѕРґ РїРѕР·РІРѕР»СЏС‰РёР№ СѓСЃС‚Р°РЅРѕРІРёС‚СЊ СЃС‚РѕРёРјРѕСЃС‚СЊ РєРѕРјРїР»РµРєС‚РѕРІ РґРµС‚Р°Р»РµР№
    void Set_Cost_KitD_Sup(ulong cost, ulong cost1, ulong cost2)
    {Cost_KitD_ElCoffee = cost; Cost_KitD_ElBlender = cost1; Cost_KitD_ElMyasoR = cost2;}

    unsigned long Get_Cost_KitD_Sup_ElCoffee()  {return Cost_KitD_ElCoffee;}
    unsigned long Get_Cost_KitD_Sup_ElBlender() {return Cost_KitD_ElBlender;}
    unsigned long Get_Cost_KitD_Sup_ElMyasoR()  {return Cost_KitD_ElMyasoR;}

private:
    QVector<QString> _Supplier;    //РџРѕСЃС‚Р°РІС‰РёРє Р¤РРћ
    ulong Cost_KitD_ElCoffee; //РЎС‚РѕРёРјРѕСЃС‚СЊ РєРѕРјРїР»РµРєС‚РѕРІ РґРµС‚Р°Р»РµР№
    ulong Cost_KitD_ElBlender;
    ulong Cost_KitD_ElMyasoR;
    QString str;//РґР»СЏ РІС‹Р±РѕСЂР° РѕРїС†РёРё
    int num;
    bool click_btn;
    bool click_ChangeDataSup_btn;
};

#endif // SUPPLIER_H
