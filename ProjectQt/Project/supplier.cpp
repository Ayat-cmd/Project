#include "supplier.h"
#include "ui_supplier.h"
#include <QDebug>

Supplier::Supplier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Supplier)
{
    Cost_KitD_ElCoffee = Cost_KitD_ElBlender = Cost_KitD_ElMyasoR=0;

    //window = new MainWindow(this);
    ui->setupUi(this);

    //Блокируем кнопку закрытия окна
    setWindowFlags(Qt::Window
         | Qt::WindowMinimizeButtonHint
         | Qt::WindowMaximizeButtonHint
         | Qt::CustomizeWindowHint);

    //Скрываем окно Установка цен на комлекты деталей
    ui->InstallCostKit_Box->hide();
    //Скрываем окно ввод данных поставщика
    ui->setSupplier->hide();
    //Скрываем окно новые данные поставщика
    ui->NewDataSup->hide();
    //скрываем окно выбор какие данные изменить
    ui->ChangeDataSup->hide();
    //Помогает отслеживаьт нажатие кнопки в установке цен на коммплекты деталей
    click_btn = false;
    //Помогает отслеживать нажатие кнопки в выборе какие данные изменить
    click_ChangeDataSup_btn = false;

   this->layout()->setSizeConstraint(QLayout::SetFixedSize);  /*Это то, что заставляет форму автоматически изменять размер  автоматическое изменение размера на виджете hide/show.*/

    //Устанавливаем ограничение на ввод
    QRegExp exp("[а-яА-Яa-zA-Z]{1,20}");
    QRegExp num("[0-9]{1,999}");
    QRegExp phone("[0-9]{11}");
    QRegExp SuppChange("[1-4]{1}");

    //Устанавливаем, ограничения на строки
    ui->Surname->setValidator(new QRegExpValidator(exp, this));
    ui->Name->setValidator(new QRegExpValidator(exp, this));
    ui->Patronymic->setValidator(new QRegExpValidator(exp, this));
    ui->newDataSup->setValidator(new QRegExpValidator(exp, this));

    ui->numberPhone->setValidator(new QRegExpValidator(phone, this));

    ui->ElCoffeeM->setValidator(new QRegExpValidator(num, this));
    ui->El_Blender->setValidator(new QRegExpValidator(num, this));
    ui->ElMyasoR->setValidator(new QRegExpValidator(num, this));
    ui->kof_line->setValidator(new QRegExpValidator(num, this));
    ui->Bl_line->setValidator(new QRegExpValidator(num, this));
    ui->MyasR_line->setValidator(new QRegExpValidator(num, this));

    ui->dataSuppChange->setValidator(new QRegExpValidator(SuppChange, this));
}

Supplier::~Supplier()
{
    delete ui;
}

//Ввод поставщика
void Supplier::supplierEnter()
{
    show();
    ui->NewDataSup->hide();
    ui->ChangeDataSup->hide();
    //Показать Ввод данных поставщика
    ui->setSupplier->show();
    exec();
}

//Установка цен на комлекты деталей
int Supplier::Install_costKitDetail()
{
    show();
    //показать окно Установки цен на детали
    ui->InstallCostKit_Box->show();
    //Скрыть окно ввода данных поставщика
    ui->setSupplier->hide();
    exec();

    if(click_btn == true) //Если нажал кнопку Ок(Установил цену)
    {
        return 0;
    }else                //Если нажал кнопку Назад(не установил цену)
        return 1;
}

//окно ввода данных поставщика
//кнопка ОК устанавливает данные поставщика
void Supplier::on_writeSup_Btn_clicked()
{
    //Если строки ФИО не пусты и номер телефона равен 11 цифрам
    if(!ui->Surname->text().isEmpty() && !ui->Name->text().isEmpty() && !ui->Patronymic->text().isEmpty()
            && !ui->numberPhone->text().isEmpty() && ui->numberPhone->text().size() == 11)
    {
        //Если поставщика нет
        if(Get_Supplier().empty())
        {
            _Supplier.push_back(ui->Surname->text());
            _Supplier.push_back(ui->Name->text());
            _Supplier.push_back(ui->Patronymic->text());
            _Supplier.push_back(ui->numberPhone->text());
        } else {//Если поставщик есть
            //Отчищаем данные старого поставщика
            _Supplier.clear();
            _Supplier.push_back(ui->Surname->text());
            _Supplier.push_back(ui->Name->text());
            _Supplier.push_back(ui->Patronymic->text());
            _Supplier.push_back(ui->numberPhone->text());
        }

        //Устанвка цен на комлекты деталей
        QString cost;
        //Кофемолка
        cost = ui->ElCoffeeM->text();
        Cost_KitD_ElCoffee = cost.toInt();
        ui->ElCoffeeM->clear();

        //Блендер
        cost = ui->El_Blender->text();
        Cost_KitD_ElBlender = cost.toInt();
        ui->El_Blender->clear();

        //Мясорубка
        cost = ui->ElMyasoR->text();
        Cost_KitD_ElMyasoR = cost.toInt();
        ui->ElMyasoR->clear();

        //Отчищаем строки ФИО и номер телефона
        ui->Surname->clear();
        ui->Name->clear();
        ui->Patronymic->clear();
        ui->numberPhone->clear();

        //закрываем окно
        close();
    }else{
        if(ui->Surname->text().isEmpty())//Если строка фамилии пуста
        {
            ui->Surname->setFocus();
            ui->surname_label->setText("Заполните->");
            ui->surname_label->setStyleSheet("color: red");
        }
            if(ui->Name->text().isEmpty())//Если строка имени пуста
            {
                ui->Name->setFocus();
                ui->name_label->setText("Заполните->");
                ui->name_label->setStyleSheet("color: red");
            }
                if(ui->Patronymic->text().isEmpty())//Если строка отчества пуста
                {
                    ui->Patronymic->setFocus();
                    ui->patronymic_label->setText("Заполните->");
                    ui->patronymic_label->setStyleSheet("color: red");
                }
                    if(ui->numberPhone->text().isEmpty())//Если строка номера телефона пуста
                    {
                        ui->numberPhone->setFocus();
                        ui->phone_label->setText("Заполните->");
                        ui->phone_label->setStyleSheet("color: red");
                    }
    }

}

//метод смены некоторых данных поставщика
int Supplier::_supplierDataChange()
{
    show();
    //Показываем окно выбора того что хотите изменить
    ui->ChangeDataSup->show();
    //Скрываем окно ввода данных поставщика
    ui->setSupplier->hide();
    //Скрываем окно новые данные поставщика
    ui->NewDataSup->hide();
    exec();
    //Если нажал кнопку Ок(Установил цену)
    if(click_ChangeDataSup_btn == true)
        return 0;
    else        //Если нажал кнопку Назад(не установил цену)
        return 1;
}

//Окно ChangeDataSup (Выбираем какие данные изменить поставщику)
//Кнопка Выбрать Устанавливаем наш выбор того что мы хотим изменить
void Supplier::on_Supp_PhSNP_btn_clicked()
{
    //При нажатии кнопки "Выбрать" устанавливаем true
    click_ChangeDataSup_btn = true;
    //Присваиваем строку с выбранным номером
    str = ui->dataSuppChange->text();
    num = str.toInt();
    //Если выбор сделан
    if(!str.isEmpty())
    {
        //Если Выбор >4 или <1
        if(num>4 || num<1){
            hide();
            QMessageBox::warning(this, "Ошибка!", "Такого выбора нет!");
            close();//Закрыть окно
        }
        //Скрыть Окно выбора изменения данных
        ui->ChangeDataSup->hide();
        //Показать окно Ввода новых даных
        if(num == 4)
        {
            QRegExp phone("[0-9]{1,11}");
            ui->newDataSup->setValidator(new QRegExpValidator(phone, this));
            ui->NewDataSup->show();
        }else{
            QRegExp str("[а-яА-Яa-zA-Z]{1,20}");
            ui->newDataSup->setValidator(new QRegExpValidator(str, this));
            ui->NewDataSup->show();
        }
        //Отчищаем строку выбора изменения данных поставщика
        ui->dataSuppChange->clear();
    }else{
        ui->dataSuppChange->setFocus();
        ui->SuppChange_label->setStyleSheet("color:red");
    }
}

//Окно NewDataSup (Изменяем данные поставщика)
//Кнопка Ок устанавливает новые данные поставшика
void Supplier::on_new_DataSup_btn_clicked()
{
    //Если данные введены
    if(!ui->newDataSup->text().isEmpty())
    {
        //записываем новые данные
        _Supplier[num-1] = ui->newDataSup->text(); //изменяем данные
        //Отчищаем строку новых данных постащика
        ui->newDataSup->clear();
        //Скрываем окно "Изменяем данные поставщика"
        ui->NewDataSup->hide();
        //Закрываем окно
        close();
    }else{
        ui->newDataSup->setFocus();
        ui->newDataSup_label->setStyleSheet("color: red");
    }
}

//Установка цен на комлекты деталей
//Кнопка Устанавливает цену на крмлекты деталей
void Supplier::on_costKit_Btn_clicked()
{
    //Если кнопка установки цены нажата присвоить true
    click_btn = true;
    QString kof = ui->kof_line->text();
    QString bl = ui->Bl_line->text();
    QString myas = ui->MyasR_line->text();
    //Если данные введены
    if(!kof.isEmpty() && !bl.isEmpty() && !myas.isEmpty() && kof.toInt() != 0 && bl.toInt() != 0 && myas != 0)
    {
        //Устанавливаем цену на комплекты деталей
        Cost_KitD_ElCoffee = ui->kof_line->text().toUInt();
        Cost_KitD_ElBlender = ui->Bl_line->text().toUInt();
        Cost_KitD_ElMyasoR = ui->MyasR_line->text().toUInt();

        //Отчищаем строки цен
        ui->kof_line->clear();
        ui->MyasR_line->clear();
        ui->Bl_line->clear();

        ui->InstallCostKit_Box->hide();
        hide();
        QMessageBox::information(this, "Результат", "Цены на комплекты деталей установлены!");
        close();
    }else{
        if(kof.isEmpty())//Если строка пуста
        {
            ui->kof_line->setFocus();
            ui->kofCost_label->setStyleSheet("color: red");
        }
        if(bl.isEmpty())//Если строка пуста
        {
            ui->Bl_line->setFocus();
            ui->BlCost_label->setStyleSheet("color: red");
        }
        if(myas.isEmpty())//Если строка пуста
        {
            ui->MyasR_line->setFocus();
            ui->myasRCost_label->setStyleSheet("color: red");
        }
    }
}

//Окно setSupplier(Ввод данных поставщика)
//Проверка на ввод строки
void Supplier::on_Surname_textChanged(const QString &arg1)
{
    //Если строка фамилии не пуста
    if(!arg1.isEmpty())
    {
        ui->surname_label->clear();
    }
}

//Окно setSupplier(Ввод данных поставщика)
//Проверка на ввод строки
void Supplier::on_Name_textChanged(const QString &arg1)
{
    //Если строка имени не пуста
    if(!arg1.isEmpty())
    {
        ui->name_label->clear();
    }
}

//Окно setSupplier(Ввод данных поставщика)
//Проверка на ввод строки
void Supplier::on_Patronymic_textChanged(const QString &arg1)
{
    //Если строка Отчества не пуста
    if(!arg1.isEmpty())
    {
        ui->patronymic_label->clear();
    }
}

//Окно setSupplier(Ввод данных поставщика)
//Проверка на ввод строки
void Supplier::on_numberPhone_textChanged(const QString &arg1)
{
    //Если начало строки не равно 0
    if(arg1 != "0")
    {
        //Если строка не пуста и не равна 11
        if(!arg1.isEmpty() && ui->numberPhone->text().size() != 11)
        {
            ui->phone_label->clear();
            ui->phone_label->setText("Введите 11 цифр");
            ui->phone_label->setStyleSheet("color: red");
        }else
            {
                ui->phone_label->clear();
            }
    }else{
        //Отчищаем строку
        ui->numberPhone->clear();
    }
}

//Окно ввода данных поставщика
// кнопка Вернуться в меню
void Supplier::on_Close_WriteSup_Btn_clicked()
{
    //Отчищаем строки
    ui->Surname->clear();
    ui->Name->clear();
    ui->Patronymic->clear();
    ui->numberPhone->clear();
    ui->ElMyasoR->clear();
    ui->ElCoffeeM->clear();
    ui->El_Blender->clear();

    //Скрываем окно ввода поставщика
    ui->setSupplier->hide();
    close();//Закрыть окно
}

//Окно Установка цен на комплекты деталей
//Проверка на ввод строки
void Supplier::on_kof_line_textChanged(const QString &arg1)
{
    //Если стоимость комплекта деталей кофемолки введена
    if(!arg1.isEmpty() && arg1.toInt() != 0)
    {
        ui->kofCost_label->setStyleSheet("color: black");
    }
}

//Окно Установка цен на комплекты деталей
//Проверка на ввод строки
void Supplier::on_Bl_line_textChanged(const QString &arg1)
{
    //Если стоимость комлекта деталей блендера введена
    if(!arg1.isEmpty() && arg1.toInt() != 0)
    {
        ui->BlCost_label->setStyleSheet("color: black");
    }
}

//Окно Установка цен на комплекты деталей
//Проверка на ввод строки
void Supplier::on_MyasR_line_textChanged(const QString &arg1)
{
    //Если стоимость комлекта деталей Мясорубки введена
    if(!arg1.isEmpty() && arg1.toInt() != 0)
    {
        ui->myasRCost_label->setStyleSheet("color: black");
    }
}

//Окно выбора какие данные поставщика изменить
//Проверка на ввод строки
void Supplier::on_dataSuppChange_textChanged(const QString &arg1)
{
    //Если строка не пуста (выбор сделан)
    if(!arg1.isEmpty())
    {
        ui->SuppChange_label->setStyleSheet("color: black");
    }
}

//Окно новые данные поставщика которые мы собираемся установить
//Проверка на ввод строки
void Supplier::on_newDataSup_textChanged(const QString &arg1)
{
    //Если строка новых данных поставщика не пуста
    if(!arg1.isEmpty())
    {
        ui->newDataSup_label->setStyleSheet("color: black");
    }
}

//Окно установка цен на комплекты деталей
//Кнопка возвращает обратно в Опции
void Supplier::on_back_costKit_Btn_clicked()
{
    ui->kofCost_label->setStyleSheet("color: black");
    ui->BlCost_label->setStyleSheet("color: black");
    ui->myasRCost_label->setStyleSheet("color: black");
    //Если нажата кнопка назад в дальнейшем поможет вывести окно опций
    click_btn = false;
    //Отчищаем строки
    ui->kof_line->clear();
    ui->Bl_line->clear();
    ui->MyasR_line->clear();
    //Скрываем окно установки цен на комплекты деталей
    ui->InstallCostKit_Box->hide();
    hide();
}

//Окно выбираем что изменить у пастовщика, какие данные измменить
//Кнопка возвращает в окно Опции
void Supplier::on_back_Option_Btn_clicked()
{
    ui->SuppChange_label->setStyleSheet("color: black");
    //Помогает вывести окно Опции
    click_ChangeDataSup_btn = false;
    ui->dataSuppChange->clear();
    ui->ChangeDataSup->hide();
    hide();
}

//Окно изменяем данные поставщика по выбору
//Кнопка возвращает в окно выбираем что изменить у пастовщика, какие данные измменить
void Supplier::on_back_ChangeDataSup_Btn_clicked()
{
    ui->newDataSup_label->setStyleSheet("color: black");
    //Отчищаем строку новых данных поставщика
    ui->newDataSup->clear();
    //скрываем окно измение данных поставщика по выбору
    ui->NewDataSup->hide();
    //Показываем окно выбора что изменить у пастовщика, какие данные измменить
    ui->ChangeDataSup->show();
}
