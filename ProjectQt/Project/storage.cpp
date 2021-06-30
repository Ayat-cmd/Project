#include "storage.h"
#include "ui_storage.h"

Storage::Storage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Storage)
{
    kit_ElekCoffee = kit_ElekBlender = kit_ElekMyasoR =                 //кол-во комплектов деталей
    quantity_elekCoffee = quantity_elekBlender = quantity_elekMyasoR =  //кол-во собранных продуктов
    tmp =                                                               //временная переменная
    cost_elekCoffee = cost_elekBlender = cost_elekMyasoR = 0;           //строимость собранных продуктов

    //для расчета стоимости кол-ва заказанных комлектов деталей
    total_cost_ordered_kits_Cof = 0;
    total_cost_ordered_kits_MyasR = 0;
    total_cost_ordered_kits_Bl = 0;

    //для расчета общей стоимости проданных продуктов
    total_cost_elekCoffee = 0;
    total_cost_elekBlender = 0;
    total_cost_elekMyasoR = 0;

    //Кол-ва деталей заказанных за все время
    count_kit_ElekCoffee = 0;
    count_kit_ElekBlender = 0;
    count_kit_ElekMyasoR = 0;

    //Кол-во проданных продуктов
    quantity_SEllelekCoffee = 0;
    quantity_SEllelekBlender = 0;
    quantity_SEllelekMyasoR = 0;

    ui->setupUi(this);

    sup_to_sklad = new Supplier(this);

    this->layout()->setSizeConstraint(QLayout::SetFixedSize);  /*Это то, что заставляет форму автоматически изменять размер  автоматическое изменение размера на виджете hide/show.*/

    //Блокируем кнопку закрытия окна
    setWindowFlags(Qt::Window
         | Qt::WindowMinimizeButtonHint
         | Qt::WindowMaximizeButtonHint
         | Qt::CustomizeWindowHint);

    //Устанавливаем ограничение на ввод
    QRegExp option("[0-4]{1}");
    QRegExp count("[0-9]{1,999}");
    QRegExp kit("[1-4]{1}");
    //Устанавливаем, ограничения на строки
    ui->supplierOrKit->setValidator(new QRegExpValidator(option, this));
    ui->countSell_cof_line->setValidator(new QRegExpValidator(count, this));
    ui->countSell_Bl_line->setValidator(new QRegExpValidator(count, this));
    ui->countSell_MyasoR_line->setValidator(new QRegExpValidator(count, this));
    ui->kit_line->setValidator(new QRegExpValidator(kit, this));

    //скрываем окно состояние склада
    ui->condition_sklad->hide();
    //скрываем окно Опции (Поставщика)
    ui->Option->hide();
    //скрываем окно вывода данных о постащике
    ui->infoSupp->hide();
    //скрываем окно заказа комлектов деталей
    ui->kitDetail->hide();
    //скрываем окно установки кол-ва деталей которые хотим заказать
    ui->CountKitSup->hide();
    //скрываем окно выбора продукта который хотим продать
    ui->sell_Box->hide();
    //Скрываем окно установки кол-ва продуктов которые хотим продать
    ui->sellProduct_Box->hide();
}

Storage::~Storage()
{
    delete ui;
}

//Поставщик (Заказать комлект деталей, все данные поставщика)
void Storage::Sklad(Supplier &sup)
{
    show();
    sup_to_sklad = &sup;
    //Показать окно опции
    ui->Option->show();
    ui->Option->setFixedSize(450, 270);
    ui->infoSupp->hide();
    ui->kitDetail->hide();
    ui->CountKitSup->hide();
    exec();
}

//Заказ деталей
void Storage::kit_Detail(Supplier &sup)
{
    //Если Цены на комплекты деталей установлены
    if(sup.Get_Cost_KitD_Sup_ElCoffee() != 0|| sup.Get_Cost_KitD_Sup_ElMyasoR() != 0 || sup.Get_Cost_KitD_Sup_ElBlender() != 0){
        //Показать окно заказа деталей
        ui->kitDetail->show();
    }else{
        hide();
        QMessageBox::warning(this, "Ошибка", "Установите цены на комплекты деталей!");
        show();
        ui->Option->show();
    }
}

//кнопка Ok обработка строки выбора
void Storage::on_changeS_btn_clicked()
{
    //Если строка пуста
    if(!ui->supplierOrKit->text().isEmpty())
    {
        //Присваиваем номер введеный в строке
        str = ui->supplierOrKit->text();
        num = str.toUInt();
        //Скрываем окно опции
        ui->Option->hide();
        //Отчищаем строку
        ui->supplierOrKit->clear();
        //Вызываем сигнал, который вызывает слот toChange_supplierSlot для выбора метода
        emit clicked_changeS_Signal();
    }else{
        ui->supplierOrKit->setFocus();
        ui->supplierOrKit_label->setStyleSheet("color: red");
    }
}

//выводим данные поставщика
void Storage::Print(Supplier &sup)
{
    //Показать окно вывода данных поставщика
    ui->infoSupp->show();
    //Устанавливаем текст
    ui->lastname->setText(sup.Get_Supplier()[0]);
    ui->name->setText(sup.Get_Supplier()[1]);
    ui->patronymic->setText(sup.Get_Supplier()[2]);
    ui->phone->setText(sup.Get_Supplier()[3]);
}

//Кнопка "Закрыть" возвращающая к опции
void Storage::on_pushButton_clicked()
{
    //Скрываем окно данных поставщика
    ui->infoSupp->hide();
    //Показываем окно опции
    ui->Option->show();
}

//Кнопка "меню" возвращат в меню
void Storage::on_close_clicked()
{
    ui->supplierOrKit_label->setStyleSheet("color: black");
    //Отчищаеем строку выбора Опции
    ui->supplierOrKit->clear();
    //Скрываем окно опции
    ui->Option->hide();
    //закрываем окно
    close();
}

//смена поставщика
void Storage::ChangeSup_Slot(Supplier &sup)
{
    hide();//скрываем окно склада
    //вызываем метод Ввода поставщика
    emit sup.supplierEnter();
}

//Установить стоимость комлектов деталей
int Storage::ChangeSupCostKit(Supplier &sup)
{
    //временная переменная
    int k = 0;
    //скрываем окно склада
    hide();
    //вызываем метод установки цен на комлекты деталей и результат присваиваем k
    k = sup.Install_costKitDetail();

    if(k == 1)   //Если нажал кнопку Назад(Не установил цену)
    {
        show();
        //показать Окно опции и сделать выбор
        ui->Option->show();
        return 1;
    }else{
        //Если нажал кнопку Ок(Установил цену)
        //закрыть окно склад
        close();
        return 0;
    }
}

//Вызываем метод смены некоторых данных поставщика
int Storage::sklad_supplierDataChange(Supplier &sup)
{
    //временная переменная
    int k = 0;
    //скрываем окно склада
    hide();
    //вызываем метод смены некоторых данных поставщика и результат присваиваем k
    k = sup._supplierDataChange();
    //Если нажал кнопку Назад(Не установил цену)
    if(k == 1)
    {
        show();
        //показать Окно опции и сделать выбор
        ui->Option->show();
        return 1;
    }else{
        //Если нажал кнопку Ок(Установил цену)
        //закрыть окно склад
        close();
        return 0;
    }
}

//Продажа продукта
void Storage::sell_product()
{
    show();
    ui->Option->hide();
    //Показываем окно выбора, какой продукт продать
    ui->sell_Box->show();
    ui->sellProduct_Box->hide();
    exec();
}

//Очищаем всё, скрываем и закрываем окно
void Storage::Default()
{
    ui->countSell_cof_line->clear();
    ui->countSell_Bl_line->clear();
    ui->countSell_MyasoR_line->clear();
    ui->total_cost_sell_product_label->clear();

    ui->sell_elBl_check->setChecked(false);
    ui->sell_elCof_check->setChecked(false);
    ui->sell_elMyasoR_check->setChecked(false);

    ui->sell_Box->hide();
    ui->sellProduct_Box->hide();
    close();
}

//Кнопка Ок обрабатывает строку kit_line куда мы ввели наш выбор заказа
void Storage::on_kit_btn_clicked()
{
    str = ui->kit_line->text();
    num = str.toUInt();
    //Если строка выбора комплектов деталей не пуста
    if(!ui->kit_line->text().isEmpty())
    {
        //Если Ввели число больше 4 или меньше 1
        if( num > 4 || num < 1)
        {
            hide();
            QMessageBox::warning(this, "Ошибка", "Такого выбора нет. Введите корректные данные!");
            close();
        }else{
            //Скрыть окно выбора Заказа деталей
            ui->kitDetail->hide();
            //Отчестить строку выбора комплектов деталей
            ui->kit_line->clear();
            //Показываем окно установки количества комплектов деталей
            ui->CountKitSup->show();
        }
    }else{
        ui->kit_line->setFocus();
        ui->kit_label->setStyleSheet("color: red");
    }
}

//окно установки количества комплектов деталей
//Кнопка ОК Устанавливаем количество деталей которые мы хотим получить
void Storage::on_countKit_Btn_clicked()
{
    //присваиваем количество деталей
    str = ui->countKit_Spin->text();
    count = str.toUInt();
    //Отчищаем спинбокс
    ui->countKit_Spin->clear();
    //Если кол-во деталей не 0 или не пусто
    if(count != 0 || !ui->countKit_Spin->text().isEmpty())
    {
        //Если выбрали комлект деталей эл.Кофемолку
        if(num == 1)
        {
            tmp = sup_to_sklad->Get_Cost_KitD_Sup_ElCoffee() * count;
            set_Total_costOrder_elCoffee(tmp);
            Set_kit_ElekCoffee(count);//Установливаем количество заказанных деталей
        }else
            //Если выбрали комлект деталей эл.Блендер
            if(num == 2)
            {
                //рассчет стоимости заданного кол-ва комплектов деталей
                tmp = sup_to_sklad->Get_Cost_KitD_Sup_ElBlender() * count;
                set_Total_costOrder_elBlender(tmp);
                Set_kit_ElekBlender(count);
            }else
                //Если выбрали комлект деталей эл.Мясорубк
                if(num == 3)
                {
                    //рассчет стоимости заданного кол-ва комплектов деталей
                    tmp = sup_to_sklad->Get_Cost_KitD_Sup_ElMyasoR() * count;
                    set_Total_costOrder_elMyasoR(tmp);
                    Set_kit_ElekMyasoR(count);
                }else
                    //Если выбрали все три комлекта деталей
                    if(num == 4)
                    {
                        //Записываем количество заказанных детылей
                        //рассчет стоимости заданного кол-ва комплектов деталей
                        tmp = sup_to_sklad->Get_Cost_KitD_Sup_ElCoffee() * count;
                        set_Total_costOrder_elCoffee(tmp);
                        tmp = sup_to_sklad->Get_Cost_KitD_Sup_ElMyasoR() * count;
                        set_Total_costOrder_elMyasoR(tmp);
                        tmp = sup_to_sklad->Get_Cost_KitD_Sup_ElBlender() * count;
                        set_Total_costOrder_elBlender(tmp);
                        Set_kit_ElekCoffee(count);
                        Set_kit_ElekBlender(count);
                        Set_kit_ElekMyasoR(count);
                    }
        //Отчищаем расчет стоимости N-го кол-ва деталей
        ui->total_cost_ordered_kits_label->clear();
        //Скрываем окно установки количества комплектов деталей
        ui->CountKitSup->hide();
        //Закрываем окно
        close();
    }else{
        ui->countKit_Spin->setFocus();
        ui->Spin_label->setStyleSheet("color: red");
    }
}

//окно установки количества комплектов деталей
//Кнопка назад возвращает к выбору деталей которые хотим заказать
void Storage::on_pushButton_2_clicked()
{
    ui->Spin_label->setStyleSheet("color: black");
    //Отчистить расчет стоимости кол-ва деталей
    ui->total_cost_ordered_kits_label->clear();
    //Отчестить кол-во заказаных деталей
    ui->countKit_Spin->clear();;
    //Скрыть окно установки количества комплектов деталей
    ui->CountKitSup->hide();
    //показать окно выбора комплекта деталей которые хотим заказать
    ui->kitDetail->show();
}

//состояние склада
void Storage::condition_sklad(){
    show();
    //показать окно состояния склада
    ui->condition_sklad->show();
    //Скрыть окна вывоа кол-ва комлектов деталей и собраных продуктов
    ui->quantity_Kit_Detail->hide();
    ui->quantity_Kit_Product->hide();
    exec();
    //Скрываем окно состояния склада после завершения его просмотра
    ui->condition_sklad->hide();
}

//Окно состояние склада
//Показать Окно кол-ва комплектов деталей
void Storage::on_kit_detail_stateChanged(int arg1)
{
    //Если отметили просмотр кол-ва деталей
    if(arg1 == Qt::Checked)
    {
        //Показать окно кол-ва деталей
        ui->quantity_Kit_Detail->show();
        str =  "Количество комлекта деталей для электрической кофемолки: " + QString::number(Get_kit_ElekCoffee()) + "\n" +
               "Количество комлекта деталей для электрического блендера: " + QString::number(Get_kit_ElekBlender()) + "\n" +
               "Количество комлекта деталей для электрической мясорубки: " + QString::number(Get_kit_ElekMyasoR()) + "\n";
        //Установить информацию о деталях
        ui->quantity_Kit_Detail->setText(str);
        str="";
    }else{
        //Скрыть окно кол-ва деталей
        ui->quantity_Kit_Detail->hide();
    }
}

//Окно состояние склада
//Показать кол-во собранных продуктов
void Storage::on_kit_product_stateChanged(int arg1)
{
    //если  отметили просмотр кол-ва собранных продуктов
    if(arg1 == Qt::Checked)
    {
        //Показать окно кол-ва собранных продуктов
        ui->quantity_Kit_Product->show();
        str = "Количество собранных электрических кофемолок: " + QString::number(Get_collected_ElekCoffee()) + "\n" +
               "Количество собранных электрических блендеров: " + QString::number(Get_collected_ElekBlender()) + "\n" +
                "Количество собранных электрических мясорубок: " + QString::number(Get_collected_ElekMyasoR()) + "\n";
        //Установить информацию о продуктах
        ui->quantity_Kit_Product->setText(str);
        str="";
    }else{
        //Скрыть окно собранных продуктов
        ui->quantity_Kit_Product->hide();
    }
}

//Собираем эл. Кофемлку
void Storage::collect_ElekCoffee(unsigned int n, Worker &work, const int N_Employees)
{
    tmp = n * N_Employees;// кол-во сотрудников которое нужно чтобы собрать продукт

    //Если Комплектов деталей больше кол-ва деталей которое мы задали для сборки
    if(kit_ElekCoffee >= n)
    {
        //Если сотрудников больше, чем сотрудников которые мы задали для сборки продукта
        if(work.Get_Work().size() >= tmp)
        {
            //Начинаем сборку продукта n раз
            for(uint i = 0; i < n; i++)
            {
                quantity_elekCoffee++; //Собранный продукт
                kit_ElekCoffee--;      //Комплект деталей
            }
        } else {
            QMessageBox::warning(this, "Ошика!", "Недостаточно сотрудников для изготовления " + QString::number(n) +
                                 " кофемолок(и)\nУ вас " + QString::number(work.Get_Work().size()) +
                                 " сотрудников\n Вам нужно добавить " + QString::number(tmp - work.Get_Work().size()) + " cотрудника(ов)");
        }
    } else {
        QMessageBox::warning(this, "Ошибка!", "Недостаточно комлектов деталей!\n"
                                   "Количество комлектов деталей для эл. кофемолки: " + QString::number(kit_ElekCoffee) + "\n"
                                   "Дабавьте еще" + QString::number(n - kit_ElekCoffee) + "комплекта(ов)\n"
                                   "Закажите у пастовщика комплект деталей");
    }
}

//Собираем эл. Блендер
void Storage::collect_ElekBlender(uint n, Worker &work, const int N_Employees) {
    tmp = n * N_Employees;// кол-во сотрудников которое нужно чтобы собрать продукт

    //Если Комплектов деталей больше, кол-ва деталей которое мы задали для сборки
    if(kit_ElekBlender >= n )
    {
        //Если сотрудников в базе больше, чем сотрудников которые мы задали для сборки продукта
        if(work.Get_Work().size() >= tmp)
        {
            //Начинаем сборку продукта n раз
            for(uint i=0; i<n;i++)
            {
                quantity_elekBlender++;//Собранный продукт
                kit_ElekBlender--;     //Комплект деталей
            }
        }else
        {
            QMessageBox::warning(this, "Ошибка!", "Недостаточно сотрудников для изготовления " + QString::number(n) + " блендеров\n"
                                                  "У вас " + QString::number(work.Get_Work().size()) + " сотрудников\n"
                                                  "Вам нужно добавить " + QString::number(tmp - work.Get_Work().size()) + " cотрудника(ов)");
        }
    }else{
        QMessageBox::warning(this, "Ошибка!", "Недостаточно комлектов деталей!\n"
                                              "Количество комлектов деталей для эл. блендера: " + QString::number(kit_ElekCoffee) + "\n"
                                              "Дабавьте еще" + QString::number(n - kit_ElekBlender) + "комплекта(ов)\n"
                                              "Закажите у пастовщика комплект деталей");
    }
}

//Собираем эл. Мясорубку
void Storage::collect_ElekMyasoR(unsigned int n, Worker &work, const int N_Employees) {
    tmp = n * N_Employees; // кол-во сотрудников которое нужно чтобы собрать продукт

    //Если Комплектов деталей больше, кол-ва деталей которое мы задали для сборки
    if(kit_ElekMyasoR >= n)
    {
        //Если сотрудников в базе больше, чем сотрудников которые мы задали для сборки продукта
        if(work.Get_Work().size() >= tmp)
        {
            //Начинаем сборку продукта n раз
            for(uint i=0; i<n;i++)
            {
                quantity_elekMyasoR++;
                kit_ElekMyasoR--;
            }
        } else {
            QMessageBox::warning(this, "Ошибка!", "Недостаточно сотрудников для изготовления " + QString::number(n) + " блендеров\n"
                                                  "У вас " + QString::number(work.Get_Work().size()) + " сотрудников\n"
                                                  "Вам нужно добавить " + QString::number(tmp - work.Get_Work().size()) + " cотрудника(ов)");
        }
    }else{
        QMessageBox::warning(this, "Ошибка!", "Недостаточно комлектов деталей!\n"
                                              "Количество комлектов деталей для эл. мясорубки: " + QString::number(kit_ElekMyasoR) + "\n"
                                              "Дабавьте еще" + QString::number(n - kit_ElekMyasoR) + "комплекта(ов)\n"
                                              "Закажите у пастовщика комплект деталей");
    }
}

//Собираем эл. Мясорубку
//Собираем эл. Блендер
void Storage::collect_elBlelMyas(uint bl, uint myas, Worker &work, const int N_Employees)
{
    tmp = bl + myas;//кол-во продуктов которые мы хотим собрать
    tmp *= N_Employees;// кол-во сотрудников которое нужно чтобы собрать продукт

    //Если сотрудников в базе больше, чем сотрудников которые мы задали для сборки продукта
    if(tmp <= work.Get_Work().size())
    {
        collect_ElekMyasoR(myas, work, N_Employees);//Вызываем метод сборки продуктов
        collect_ElekBlender(bl, work, N_Employees);
    } else {
        QMessageBox::warning(this, "Ошибка!", "Недостаточно сотрудников для изготовления " + QString::number(tmp/N_Employees) + " продуктов\n"
                                              "Нужно добавить " + QString::number(tmp - work.Get_Work().size()) + " сотрудников!");

    }
}

//Собираем эл. Блендер
//Собираем эл. Кофемлку
void Storage::collect_elBlelCof(uint bl, uint kof, Worker &work, const int N_Employees)
{
    tmp = bl + kof;//кол-во продуктов которые мы хотим собрать
    tmp *= N_Employees;// кол-во сотрудников которое нужно чтобы собрать продукт

    //Если сотрудников в базе больше, чем сотрудников которые мы задали для сборки продукта
    if(tmp <= work.Get_Work().size())
    {
        collect_ElekCoffee(kof, work, N_Employees);//Вызываем метод сборки продуктов
        collect_ElekBlender(bl, work, N_Employees);
    } else {
        QMessageBox::warning(this, "Ошибка!", "Недостаточно сотрудников для изготовления " + QString::number(tmp/N_Employees) + " продуктов\n"
                                              "Нужно добавить " + QString::number(tmp - work.Get_Work().size()) + " сотрудников!");

    }
}

//Собираем эл. Кофемлку
//Собираем эл. Мясорубку
void Storage::collect_elMyaselCof(uint myas, uint kof, Worker &work, const int N_Employees)
{
    tmp = myas + kof;//кол-во продуктов которые мы хотим собрать
    tmp *= N_Employees;// кол-во сотрудников которое нужно чтобы собрать продукт

    //Если сотрудников в базе больше, чем сотрудников которые мы задали для сборки продукта
    if(tmp <= work.Get_Work().size())
    {
        collect_ElekCoffee(kof, work, N_Employees);//Вызываем метод сборки продуктов
        collect_ElekMyasoR(myas, work, N_Employees);
    } else {
        QMessageBox::warning(this, "Ошибка!", "Недостаточно сотрудников для изготовления " + QString::number(tmp/N_Employees) + " продуктов\n"
                                              "Нужно добавить " + QString::number(tmp - work.Get_Work().size()) + " сотрудников!");

    }
}


//Собрать все продукты
void Storage::Collect_All_Product(unsigned int kof, unsigned int bl, unsigned int myas, Worker &work, const int N_Employees)
{

    tmp = kof + bl + myas; //кол-во продуктов которые мы хотим собрать
    tmp *= N_Employees; //кол-во сотрудников которое требуется

    //Если сотрудников в базе больше, чем сотрудников которые мы задали для сборки продукта
    if(tmp <= work.Get_Work().size())
    {
        collect_ElekCoffee(kof, work, N_Employees);//Вызываем метод сборки продуктов
        collect_ElekMyasoR(myas, work, N_Employees);
        collect_ElekBlender(bl, work, N_Employees);
    } else {
        QMessageBox::warning(this, "Ошибка!", "Недостаточно сотрудников для изготовления " + QString::number(tmp/N_Employees) + " продуктов\n"
                                              "Нужно добавить " + QString::number(tmp - work.Get_Work().size()) + " сотрудников!");

    }
}

//Окно состояния склада
//Кнопка назад в меню
void Storage::on_back_Btn_clicked()
{
    ui->kit_detail->setChecked(false);
    ui->kit_product->setChecked(false);
    close();
}

//Продукт продан
void Storage::Sell_ElekCoffee(int kol)
{
    for(int i = 0; i < kol; i++)
    {
        quantity_elekCoffee--;
        quantity_SEllelekCoffee++;
    }
}

//Продукт продан
void Storage::Sell_ElekBlender(int kol)
{
    for(int i = 0; i < kol; i++)
    {
        quantity_elekBlender--;
        quantity_SEllelekBlender++;
    }
}

//Продукт продан
void Storage::Sell_ElekMyasoR(int kol)
{
    for(int i = 0; i < kol; i++)
    {
        quantity_elekMyasoR--;
        quantity_SEllelekMyasoR++;
    }
}

//Фунция для продажи
//Окно sellProduct_Box "Продажа товара"
//кнопка устанавливает сколько продуктов продать
void Storage::on_sell_product_btn_clicked()
{
    //присваиваем кол-во продуктов которые хотим продать
    QString kol_cof = ui->countSell_cof_line->text();
    QString kol_bl = ui->countSell_Bl_line->text();
    QString kol_myas = ui->countSell_MyasoR_line->text();

    //Если для продажи выбрали все три продукта
    if(ui->sell_elCof_check->isChecked() && ui->sell_elBl_check->isChecked() && ui->sell_elMyasoR_check->isChecked())
    {
        //Проверяем LineEdit на пустоту(Введены ли данные в поле) и если кол-ва продуктов для продажи не равно 0
        if(!kol_cof.isEmpty() && !kol_bl.isEmpty() && !kol_myas.isEmpty()
                && kol_cof.toUInt()!=0 && kol_bl.toUInt()!=0 && kol_myas.toUInt()!=0)
        {
            if(Get_collected_ElekCoffee() != 0)//Если продукты не закончились
            {
                if(Get_collected_ElekBlender() != 0)
                {
                    if(Get_collected_ElekMyasoR() != 0)
                    {
                        //Если кол-во продуктов которые мы хотим продать больше, кол-ва которое есть на складе
                        if(kol_cof.toInt()>Get_collected_ElekCoffee() || kol_bl.toInt()>Get_collected_ElekBlender() || kol_myas.toInt()>Get_collected_ElekMyasoR()){
                            QMessageBox::warning(this, "Склад", "На складе нет столько продуктов!\nСоберите больше!");
                        }else{//Если меньше
                            //Устанавливаем цену которую потратили
                            tmp = kol_cof.toInt() * Get_Cost_ElekCoffee();
                            set_total_costSell_elekCoffee(tmp);

                            tmp = kol_myas.toInt() * Get_Cost_ElekMyasoR();
                            set_total_costSell_elekMyasoR(tmp);

                            tmp = kol_bl.toInt() * Get_Cost_ElekBlender();
                            set_total_costSell_elekBlender(tmp);

                            Sell_ElekCoffee(kol_cof.toInt());//Вызываем методы продажи продуктов, параметрами передаем
                            Sell_ElekBlender(kol_bl.toInt());//количество которое хотим продать
                            Sell_ElekMyasoR(kol_myas.toInt());
                        }
                    }else
                        QMessageBox::warning(this, "Ошибка", "Соберите эл. Мясорубку!");
                }else
                    QMessageBox::warning(this, "Ошибка", "Соберите эл. Блендер!");
            }else
                QMessageBox::warning(this, "Ошибка", "Соберите эл. Кофемолку!");
            Default();//Очищаем всё, скрываем и закрываем окно
        }else{
            if(kol_cof.isEmpty())
            {
                ui->countSell_cof_line->setFocus();
                ui->Cof_label->setStyleSheet("color: red");
            }
            if(kol_bl.isEmpty())
            {
                ui->countSell_Bl_line->setFocus();
                ui->Bl_label->setStyleSheet("color: red");
            }
            if(kol_myas.isEmpty())
            {
                ui->countSell_MyasoR_line->setFocus();
                ui->MyasoR_label->setStyleSheet("color: red");
            }
        }
    }else
        //Если для продажи выбрали два продукта(Кофемолка и Блендер)
        if(ui->sell_elCof_check->isChecked() && ui->sell_elBl_check->isChecked())
        {
            //Проверяем LineEdit на пустоту(Введены ли данные в поле) и если кол-ва продуктов для продажи не равно 0
            if(!kol_cof.isEmpty() && !kol_bl.isEmpty() && kol_bl.toInt()!=0 && kol_cof.toInt()!=0)
            {
                if(Get_collected_ElekCoffee() != 0)//Если продукты не закончились
                {
                    if(Get_collected_ElekBlender() != 0)
                    {
                        //Если кол-во продуктов которые мы хотим продать больше, кол-ва которое есть на складе
                        if(kol_cof.toInt()>Get_collected_ElekCoffee() || kol_bl.toInt()>Get_collected_ElekBlender()){
                            QMessageBox::warning(this, "Ошибка", "На склане нет столько продуктов!\nСоберите больше!");
                        }else{
                            //Устанавливаем цену которую потратили
                            tmp = kol_cof.toInt() * Get_Cost_ElekCoffee();
                            set_total_costSell_elekCoffee(tmp);

                            tmp = kol_bl.toInt() * Get_Cost_ElekBlender();
                            set_total_costSell_elekBlender(tmp);

                            Sell_ElekCoffee(kol_cof.toInt());//Вызываем методы продажи продуктоа, параметрами передаем
                            Sell_ElekBlender(kol_bl.toInt());//количество которое хотим продать
                        }
                    }else
                        QMessageBox::warning(this, "Ошибка", "Соберите эл. Блендер!");
                }else
                    QMessageBox::warning(this, "Ошибка", "Соберите эл. Кофемолку!");
                Default();//Очищаем всё, скрываем и закрываем окно
            }else{
                if(kol_cof.isEmpty())
                {
                    ui->countSell_cof_line->setFocus();
                    ui->Cof_label->setStyleSheet("color: red");
                }
                if(kol_bl.isEmpty())
                {
                    ui->countSell_Bl_line->setFocus();
                    ui->Bl_label->setStyleSheet("color: red");
                }
            }
        }else
            //Если для продажи выбрали два продукта(Блендер и Мясорубка)
            if(ui->sell_elBl_check->isChecked() && ui->sell_elMyasoR_check->isChecked())
            {
                //Проверяем LineEdit на пустоту(Введены ли данные в поле) и если кол-ва продуктов для продажи не равно 0
                if(!kol_bl.isEmpty() && !kol_myas.isEmpty() && kol_bl.toInt()!=0 && kol_myas.toInt()!=0)
                {
                    if(Get_collected_ElekBlender() != 0)//Если продукты не закончились
                    {
                        if(Get_collected_ElekMyasoR() != 0)
                        {
                            //Если кол-во продуктов которые мы хотим продать больше, кол-ва которое есть на складе
                            if(kol_bl.toInt()>Get_collected_ElekBlender() || kol_myas.toInt()>Get_collected_ElekMyasoR()){
                                QMessageBox::warning(this, "Склад", "На складе нет столько продуктов!\nСоберите больше!");
                            }else{
                                //Устанавливаем цену которую потратили
                                tmp = kol_myas.toInt() * Get_Cost_ElekMyasoR();
                                set_total_costSell_elekMyasoR(tmp);

                                tmp = kol_bl.toInt() * Get_Cost_ElekBlender();
                                set_total_costSell_elekBlender(tmp);

                                //Вызываем методы продажи продуктоа, параметрами передаем
                                Sell_ElekBlender(kol_bl.toInt());//количество которое хотим продать
                                Sell_ElekMyasoR(kol_myas.toInt());
                            }
                        }else
                            QMessageBox::warning(this, "Ошибка", "Соберите эл. Мясорубку!");
                    }else
                        QMessageBox::warning(this, "Ошибка", "Соберите эл. Блендер!");
                    Default();//Очищаем всё, скрываем и закрываем окно
                }else{
                    if(kol_bl.isEmpty())
                    {
                        ui->countSell_Bl_line->setFocus();
                        ui->Bl_label->setStyleSheet("color: red");
                    }
                    if(kol_myas.isEmpty())
                    {
                        ui->countSell_MyasoR_line->setFocus();
                        ui->MyasoR_label->setStyleSheet("color: red");
                    }
                }
            }else
                //Если для продажи выбрали два продукта(Кофемолка и Мясорубка)
                if(ui->sell_elCof_check->isChecked() && ui->sell_elMyasoR_check->isChecked())
                {
                    //Проверяем LineEdit на пустоту(Введены ли данные в поле) и если кол-ва продуктов для продажи не равно 0
                    if(!kol_cof.isEmpty() && !kol_myas.isEmpty() && kol_cof.toInt()!=0 && kol_myas.toInt()!=0)
                    {
                        if(Get_collected_ElekCoffee() != 0)//Если продукты не закончились
                        {
                            if(Get_collected_ElekMyasoR() != 0)
                            {
                                //Если кол-во продуктов которые мы хотим продать больше, кол-ва которое есть на складе
                                if(kol_cof.toInt()>Get_collected_ElekCoffee() || kol_myas.toInt()>Get_collected_ElekMyasoR()){
                                    QMessageBox::warning(this, "Склад", "На складе нет столько продуктов!\nСоберите больше!");
                                }else{
                                    //Устанавливаем цену которую потратили
                                    tmp = kol_cof.toInt() * Get_Cost_ElekCoffee();
                                    set_total_costSell_elekCoffee(tmp);

                                    tmp = kol_myas.toInt() * Get_Cost_ElekMyasoR();
                                    set_total_costSell_elekMyasoR(tmp);

                                    Sell_ElekCoffee(kol_cof.toInt());//Вызываем методы продажи продуктоа, параметрами передаем
                                    Sell_ElekMyasoR(kol_myas.toInt());//количество которое хотим продать
                                }
                            }else
                                QMessageBox::warning(this, "Ошибка", "Соберите эл. Мясорубку!");
                        }else
                            QMessageBox::warning(this, "Ошибка", "Соберите эл. Кофемолку!");
                        Default();//Очищаем всё, скрываем и закрываем окно
                    }else{
                        if(kol_cof.isEmpty())
                        {
                            ui->countSell_cof_line->setFocus();
                            ui->Cof_label->setStyleSheet("color: red");
                        }
                        if(kol_myas.isEmpty())
                        {
                            ui->countSell_MyasoR_line->setFocus();
                            ui->MyasoR_label->setStyleSheet("color: red");
                        }
                    }
                }else
                    //Если для продажи выбрали один продукт(Кофемолка)
                    if(ui->sell_elCof_check->isChecked())
                    {
                        //Проверяем LineEdit на пустоту(Введены ли данные в поле) и если кол-ва продукта для продажи не равно 0
                        if(!kol_cof.isEmpty() && kol_cof.toInt() != 0)
                        {
                            if(Get_collected_ElekCoffee() != 0)//Если эл. Кофемолки не закончились
                            {
                                //Если кол-во продуктов которые мы хотим продать больше, кол-ва которое есть на складе
                                if(kol_cof.toInt()>Get_collected_ElekCoffee())
                                {
                                    QMessageBox::warning(this, "Склад", "На складе нет столько продуктов!\nСоберите больше эл. Кофемолок");
                                }else{
                                    //Устанавливаем цену которую потратили
                                    tmp = kol_cof.toInt() * Get_Cost_ElekCoffee();
                                    set_total_costSell_elekCoffee(tmp);

                                    Sell_ElekCoffee(kol_cof.toInt());/*Вызываем метод продажи эл. Кофемолки, и параметрами передаем кол-во которое хотим продать*/
                                }
                            } else
                                QMessageBox::warning(this, "Ошибка", "Соберите продукт!");
                            Default();//Очищаем всё, скрываем и закрываем окно
                        }else{
                            ui->countSell_cof_line->setFocus();
                            ui->Cof_label->setStyleSheet("color: red");
                        }
                    }else
                        //Если для продажи выбрали один продукт(Блендер)
                        if(ui->sell_elBl_check->isChecked())
                        {
                            //Проверяем LineEdit на пустоту(Введены ли данные в поле) и если кол-ва продукта для продажи не равно 0
                            if(!kol_bl.isEmpty() && kol_bl.toInt() != 0)
                            {
                                if(Get_collected_ElekBlender() != 0)//Если эл. Блендеры не закончились
                                {
                                    //Если кол-во продуктов которые мы хотим продать больше, кол-ва которое есть на складе
                                    if(kol_bl.toInt() > Get_collected_ElekBlender())
                                    {
                                        QMessageBox::warning(this, "Склад", "На складе нет столько продуктов!\nСоберите больше эл. Блендеров");
                                    }else{
                                        //Устанавливаем цену которую потратили
                                        tmp = kol_bl.toInt() * Get_Cost_ElekBlender();
                                        set_total_costSell_elekBlender(tmp);

                                        Sell_ElekBlender(kol_bl.toInt());/*Вызываем метод продажи эл. Блендера(ов), и параметрами передаем кол-во которое хотим продать*/
                                    }
                                }else
                                    QMessageBox::warning(this, "Ошибка", "Соберите продукт!");
                                Default();//Очищаем всё, скрываем и закрываем окно
                            }else{
                                ui->countSell_Bl_line->setFocus();
                                ui->Bl_label->setStyleSheet("color: red");
                            }
                        }else
                            //Если для продажи выбрали один продукт(Мясорубка)
                            if(ui->sell_elMyasoR_check->isChecked())
                            {
                                //Проверяем LineEdit на пустоту(Введены ли данные в поле) и если кол-ва продукта для продажи не равно 0
                                if(!kol_myas.isEmpty() && kol_myas.toInt() != 0)
                                {
                                    if(Get_collected_ElekMyasoR() != 0)//Если эл. Мясорубки не закончились
                                    {
                                        //Если кол-во продуктов которые мы хотим продать больше, кол-ва которое есть на складе
                                        if(kol_myas.toInt() > Get_collected_ElekBlender())
                                        {
                                            QMessageBox::warning(this, "Склад", "На складе нет столько продуктов!\nСоберите больше эл. Мясорубок");
                                        }else{
                                            //Устанавливаем цену которую потратили
                                            tmp = kol_myas.toInt() * Get_Cost_ElekMyasoR();
                                            set_total_costSell_elekMyasoR(tmp);

                                            Sell_ElekMyasoR(kol_myas.toInt());/*Вызываем метод продажи эл. Мясорубки(ок), и параметрами передаем кол-во которое хотим продать*/
                                        }
                                     }else
                                        QMessageBox::warning(this, "Ошибка", "Соберите продукт!");
                                    Default();//Очищаем всё, скрываем и закрываем окно
                                }else{
                                    ui->countSell_MyasoR_line->setFocus();
                                    ui->MyasoR_label->setStyleSheet("color: red");
                                }
                            }
}

//Фунция для продажи
//окно sell_Box "Выбор продажи
//Выбор продукта который хотим продать
void Storage::on_sell_Btn_clicked()
{
    //Если Есть собранные продукты
    if(Get_collected_ElekCoffee() != 0 || Get_collected_ElekBlender() != 0 || Get_collected_ElekMyasoR() != 0)
    {
        //Если выбрал все три продукта для продажи
        if(ui->sell_elCof_check->isChecked() && ui->sell_elBl_check->isChecked() && ui->sell_elMyasoR_check->isChecked())
        {
            if(Get_collected_ElekCoffee() != 0)//Если эл. Кофемолки не закончились
            {
                if(Get_collected_ElekBlender() != 0)
                {
                    if(Get_collected_ElekMyasoR() != 0)
                    {
                        //Показываем окно установки кол-ва и продажи продуктов
                        ui->sellProduct_Box->show();
                        //Скрываем окно выбора продукта который хотим продать
                        ui->sell_Box->hide();

                        //Показываем строки для ввода кол-ва продуктов которые хотим продать
                        ui->Cof_label->show();
                        ui->countSell_cof_line->show();
                        ui->Bl_label->show();
                        ui->countSell_Bl_line->show();
                        ui->MyasoR_label->show();
                        ui->countSell_MyasoR_line->show();
                    }else{
                        QMessageBox::warning(this, "Ошибка", "Вы не можете продать три продукта!\n"
                                                             "Мясорубок осталось: " + QString::number(quantity_elekCoffee));
                    }
                }else{
                    QMessageBox::warning(this, "Ошибка", "Вы не можете продать три продукта!\n"
                                                         "Блендеров осталось: " + QString::number(quantity_elekCoffee));
                }
            } else {
                QMessageBox::warning(this, "Ошибка", "Вы не можете продать сразу три продукта!\n"
                                                     "Кофемолок осталось: " + QString::number(quantity_elekCoffee));
            }
        }else
            //Если выбрал два продукта для продажи(Кофемолка, Блендер)
            if(ui->sell_elCof_check->isChecked() && ui->sell_elBl_check->isChecked())
            {
                if(Get_collected_ElekCoffee() != 0)//Если эл. Кофемолки не закончились
                {
                    if(Get_collected_ElekBlender() != 0)
                    {
                        //Показываем окно установки кол-ва и продажи продуктов
                        ui->sellProduct_Box->show();
                        //Скрываем окно выбора продукта который хотим продать
                        ui->sell_Box->hide();

                        ui->MyasoR_label->hide();
                        ui->countSell_MyasoR_line->hide();
                        //Показываем строки для ввода кол-ва продуктов которые хотим продать
                        ui->Cof_label->show();
                        ui->countSell_cof_line->show();
                        ui->Bl_label->show();
                        ui->countSell_Bl_line->show();
                    }else{
                        QMessageBox::warning(this, "Ошибка", "Вы не можете продать два продукта!\n"
                                                             "Блендеров осталось: " + QString::number(quantity_elekCoffee));
                    }
                }else{
                    QMessageBox::warning(this, "Ошибка", "Вы не можете продать два продукта!\n"
                                                         "Кофемолкок осталось: " + QString::number(quantity_elekCoffee));
                }
            }else
                //Если выбрал два продукта для продажи(Блендер, Мясорубка)
                if(ui->sell_elBl_check->isChecked() && ui->sell_elMyasoR_check->isChecked())
                {
                    if(Get_collected_ElekBlender() != 0)//Если продукты на складе не закончились
                    {
                        if(Get_collected_ElekMyasoR() != 0)
                        {
                        //Показываем окно, установки кол-ва и продажи продуктов
                        ui->sellProduct_Box->show();
                        //Скрываем окно выбора продукта который хотим продать
                        ui->sell_Box->hide();

                        ui->Cof_label->hide();
                        ui->countSell_cof_line->hide();
                        //Показываем строки для ввода кол-ва продуктов которые хотим продать
                        ui->Bl_label->show();
                        ui->countSell_Bl_line->show();
                        ui->MyasoR_label->show();
                        ui->countSell_MyasoR_line->show();
                        }else{
                            QMessageBox::warning(this, "Ошибка", "Вы не можете продать два продукта!\n"
                                                                 "Мясорубок осталось: " + QString::number(quantity_elekCoffee));
                        }
                    }else{
                        QMessageBox::warning(this, "Ошибка", "Вы не можете продать два продукта!\n"
                                                             "Блендеров осталось: " + QString::number(quantity_elekCoffee));
                    }
                }else
                    //Если выбрал два продукта для продажи (Кофемолка, Мясорубка)
                    if(ui->sell_elCof_check->isChecked() && ui->sell_elMyasoR_check->isChecked())
                    {
                        if(Get_collected_ElekCoffee() != 0)//Если эл. Кофемолки не закончились
                        {
                            if(Get_collected_ElekMyasoR() != 0)//Если продукты на складе не закончились
                            {
                                //Показываем окно, установки кол-ва и продажи продуктов
                                ui->sellProduct_Box->show();
                                //Скрываем окно выбора продукта который хотим продать
                                ui->sell_Box->hide();

                                ui->Bl_label->hide();
                                ui->countSell_Bl_line->hide();
                                //Показываем строки для ввода кол-ва продуктов которые хотим продать
                                ui->Cof_label->show();
                                ui->countSell_cof_line->show();
                                ui->MyasoR_label->show();
                                ui->countSell_MyasoR_line->show();
                            }else{
                                QMessageBox::warning(this, "Ошибка", "Вы не можете продать два продукта!\n"
                                                                     "Мясорубок осталось: " + QString::number(quantity_elekCoffee));
                            }
                        }else{
                            QMessageBox::warning(this, "Ошибка", "Вы не можете продать два продукта!\n"
                                                                 "Кофемолкок осталось: " + QString::number(quantity_elekCoffee));
                        }
                    }else
                        //Если выбрал один продукт для продажи(Кофемолка)
                        if(ui->sell_elCof_check->isChecked())
                        {
                            if(Get_collected_ElekCoffee() != 0)//Если продукты на складе не закончились
                            {
                                //Показываем окно, установки кол-ва и продажи продуктов
                                ui->sellProduct_Box->show();
                                //Скрываем окно выбора продукта который хотим продать
                                ui->sell_Box->hide();

                                ui->Bl_label->hide();
                                ui->countSell_Bl_line->hide();
                                ui->MyasoR_label->hide();
                                ui->countSell_MyasoR_line->hide();
                                //Показываем строки для ввода кол-ва продуктов которые хотим продать
                                ui->Cof_label->show();
                                ui->countSell_cof_line->show();
                            }else{
                                QMessageBox::warning(this, "Ошибка", "Вы не можете продать продукт!\n"
                                                                     "Кофемолкок осталось: " + QString::number(quantity_elekCoffee));
                            }
                        }else
                            //Если выбрал один продукт для продажи(Блендер)
                            if(ui->sell_elBl_check->isChecked())
                            {
                                if(Get_collected_ElekBlender() != 0)//Если продукты на складе не закончились
                                {
                                    //Показываем окно, установки кол-ва и продажи продуктов
                                    ui->sellProduct_Box->show();
                                    //Скрываем окно выбора продукта который хотим продать
                                    ui->sell_Box->hide();

                                    ui->Cof_label->hide();
                                    ui->countSell_cof_line->hide();
                                    ui->MyasoR_label->hide();
                                    ui->countSell_MyasoR_line->hide();
                                    //Показываем строки для ввода кол-ва продуктов которые хотим продать
                                    ui->Bl_label->show();
                                    ui->countSell_Bl_line->show();
                                }else{
                                    QMessageBox::warning(this, "Ошибка", "Вы не можете продать продукт!\n"
                                                                         "Блендеров осталось: " + QString::number(quantity_elekCoffee));
                                }
                            }else
                                //Если выбрал один продукт для продажи(Мясорубка)
                                if(ui->sell_elMyasoR_check->isChecked())
                                {
                                    if(Get_collected_ElekMyasoR() != 0)//Если продукты на складе не закончились
                                    {
                                        //Показываем окно, установки кол-ва и продажи продуктов
                                        ui->sellProduct_Box->show();
                                        //Скрываем окно выбора продукта который хотим продать
                                        ui->sell_Box->hide();

                                        ui->Bl_label->hide();
                                        ui->countSell_Bl_line->hide();
                                        ui->Cof_label->hide();
                                        ui->countSell_cof_line->hide();
                                        //Показываем строки для ввода кол-ва продуктов которые хотим продать
                                        ui->MyasoR_label->show();
                                        ui->countSell_MyasoR_line->show();
                                    }else{
                                        QMessageBox::warning(this, "Ошибка", "Вы не можете продать продукт!\n"
                                                                             "Мясорубок осталось: " + QString::number(quantity_elekCoffee));
                                    }
                                }else
                                    QMessageBox::warning(this, "Ошибка", "Сделайте выбор!");
    }else
        QMessageBox::warning(this, "Уведомление!", "У вас нет собранного продукта для продажи!\n"
                                    "Соберите продукт!");
}

//ОКно установки кол-ва продуктов для продаж
//Возвращает к выбору продажи продукта
void Storage::on_back_btn_clicked()
{
    ui->Cof_label->setStyleSheet("color: black");
    ui->Bl_label->setStyleSheet("color: black");
    ui->MyasoR_label->setStyleSheet("color: black");
    ui->sell_elCof_check->setChecked(false);
    ui->sell_elBl_check->setChecked(false);
    ui->sell_elMyasoR_check->setChecked(false);
    //Отчестить строки и расчет стоимости кол-ва продуктов
    ui->total_cost_sell_product_label->clear();
    ui->countSell_cof_line->clear();
    ui->countSell_Bl_line->clear();
    ui->countSell_MyasoR_line->clear();
    //Скрыть окно установки кол-ва продуктов для продаж
    ui->sellProduct_Box->hide();
    //показать окно выбор продажи продукта
    ui->sell_Box->show();
}

//Окно выбора продукта для продаж
//Возвращает в меню
void Storage::on_menu_btn_clicked()
{
    //Убираем галочки с выбора продукта для продаж
    ui->sell_elMyasoR_check->setChecked(false);
    ui->sell_elBl_check->setChecked(false);
    ui->sell_elCof_check->setChecked(false);
    //Скрыть окно выбора продукта для продаж
    ui->sell_Box->hide();
    //закрыть окно
    close();
}

//Окно выбора Заказа комплекта деталей
//Проверка на ввод  строки выбора заказа
void Storage::on_kit_line_textChanged(const QString &arg1)
{
    //Если  строка выбора заказа не пуста
    if(!arg1.isEmpty())
    {
        ui->kit_label->setStyleSheet("color: black");
    }
}

//Окно Установки количества комплектов деталей
//Проверка на ввод спинбакса
void Storage::on_countKit_Spin_textChanged(const QString &arg1)
{
    //Если спинбокс не пустой
    if(!arg1.isEmpty())
    {
        ui->Spin_label->setStyleSheet("color: black");
    }
}

//Окно Опции
//проверка на ввод строки выбора опции
void Storage::on_supplierOrKit_textChanged(const QString &arg1)
{
    //Если строка выюора не пуста
    if(!arg1.isEmpty())
    {
        ui->supplierOrKit_label->setStyleSheet("color: black");
    }
}

//Окно Установки кол-ва продуктов для продажи
//Проверка на ввод строки кол-ва продуктов для продаж кофемолки
void Storage::on_countSell_cof_line_textChanged(const QString &arg1)
{
    //Если строка кол-ва продуктов для продаж Не пуста
    if(!arg1.isEmpty() && arg1.toInt() != 0)
    {
        ui->Cof_label->setStyleSheet("color: black");
    }
}

//Окно Установки кол-ва продуктов для продажи
//Проверка на ввод строки кол-ва продуктов для продаж Блендера
void Storage::on_countSell_Bl_line_textChanged(const QString &arg1)
{
    //если строка кол-ва продуктов для продаж Блендера НЕ пуста
    if(!arg1.isEmpty() && arg1.toInt() != 0)
    {
        ui->Bl_label->setStyleSheet("color: black");
    }
}

//Окно Установки кол-ва продуктов для продажи
//Проверка на ввод строки кол-ва продуктов для продаж Мясорубки
void Storage::on_countSell_MyasoR_line_textChanged(const QString &arg1)
{
    //Если строка не пуста
    if(!arg1.isEmpty() && arg1.toInt() != 0)
    {
        ui->MyasoR_label->setStyleSheet("color: black");
    }
}

//Окно выбора продукта для Заказа
//Возвращает обратно в опции
void Storage::on_close_2_clicked()
{
    ui->kit_label->setStyleSheet("color: black");
    //Отчищаем строку выбора продукта для заказа
    ui->kit_line->clear();
    //Скрываем окно выбора продукта для Заказа
    ui->kitDetail->hide();
    //Показываем окно Опции
    ui->Option->show();
}

//Окно Установки количества комплектов деталей
//Рассчет стоимости кол-ва комлекта деталей
void Storage::on_total_cost_ordered_kits_clicked()
{
    //Присваиваем кол-во комплектов деталей
    str = ui->countKit_Spin->text();
    count = str.toUInt();
    if(num == 1)//Если выбрали Заказать эл.Кофемолку
    {
        //рассчет стоимости заданного кол-ва комплектов деталей
        //total_cost_ordered_kits_Cof = sup_to_sklad->Get_Cost_KitD_Sup_ElCoffee() * count;
        ui->total_cost_ordered_kits_label->setText(QString::number(sup_to_sklad->Get_Cost_KitD_Sup_ElCoffee() * count) + "руб");
    }else
        if(num == 2)//Если выбрали Заказать эл.Блендер
        {
            //рассчет стоимости заданного кол-ва комплектов деталей
            //total_cost_ordered_kits_Bl = sup_to_sklad->Get_Cost_KitD_Sup_ElBlender() * count;
            ui->total_cost_ordered_kits_label->setText(QString::number(sup_to_sklad->Get_Cost_KitD_Sup_ElBlender() * count) + "руб");
        }else
            if(num == 3)//Если выбрали Заказать эл.Мясорубку
            {
                //рассчет стоимости заданного кол-ва комплектов деталей
                //total_cost_ordered_kits_MyasR = sup_to_sklad->Get_Cost_KitD_Sup_ElMyasoR() * count;
                ui->total_cost_ordered_kits_label->setText(QString::number(sup_to_sklad->Get_Cost_KitD_Sup_ElMyasoR() * count) + "руб");
            }else
                if(num == 4)//Если выбрали Заказать все три комплекта деталей
                {
                    //рассчет стоимости заданного кол-ва комплектов деталей
                    tmp = sup_to_sklad->Get_Cost_KitD_Sup_ElCoffee() * count;
                    tmp += sup_to_sklad->Get_Cost_KitD_Sup_ElMyasoR() * count;
                    tmp += sup_to_sklad->Get_Cost_KitD_Sup_ElBlender() * count;
                    //tmp = total_cost_ordered_kits_Cof + total_cost_ordered_kits_MyasR + total_cost_ordered_kits_Bl;
                    ui->total_cost_ordered_kits_label->setText(QString::number(tmp) + "руб");
                }
}

//ОКно Установки кол-ва продуктов для продаж
//РАссчет стоимости кол-ва собранных продуктов для продаж
void Storage::on_total_cost_sell_product_clicked()
{
    //присваиваем кол-во продуктов
    QString kol_cof = ui->countSell_cof_line->text();
    QString kol_bl = ui->countSell_Bl_line->text();
    QString kol_myas = ui->countSell_MyasoR_line->text();

    //Если вы хотите Рассчитать общую стоимость всех трех продуктов Кофемолки, блендера, мясорубки
    if(ui->sell_elCof_check->isChecked() && ui->sell_elBl_check->isChecked() && ui->sell_elMyasoR_check->isChecked())
    {
        /*Проверяем LineEdit на пустоту(Введены ли данные в поле) и если кол-во Установленных продуктов для рассчета общей стоимости не равно 0*/
        if(!kol_cof.isEmpty() && !kol_bl.isEmpty() && !kol_myas.isEmpty()
                && kol_cof.toUInt()!=0 && kol_bl.toUInt()!=0 && kol_myas.toUInt()!=0)
        {
            //рассчет общей стоимости заданного кол-ва продуктов
            tmp = kol_cof.toInt() * Get_Cost_ElekCoffee();
            tmp += kol_myas.toInt() * Get_Cost_ElekMyasoR();
            tmp += kol_bl.toInt() * Get_Cost_ElekBlender();
            //tmp = total_cost_elekCoffee + total_cost_elekMyasoR + total_cost_elekBlender;
            ui->total_cost_sell_product_label->setText(QString::number(tmp) + "руб");
        }else{
            if(kol_cof.isEmpty())
            {
                ui->countSell_cof_line->setFocus();
                ui->Cof_label->setStyleSheet("color: red");
            }
            if(kol_bl.isEmpty())
            {
                ui->countSell_Bl_line->setFocus();
                ui->Bl_label->setStyleSheet("color: red");
            }
            if(kol_myas.isEmpty())
            {
                ui->countSell_MyasoR_line->setFocus();
                ui->MyasoR_label->setStyleSheet("color: red");
            }
        }
    }else
        //Если вы хотите Рассчитать общую стоимость двух продуктов Кофемолки и блендера
        if(ui->sell_elCof_check->isChecked() && ui->sell_elBl_check->isChecked())
        {
             /*Проверяем LineEdit на пустоту(Введены ли данные в поле) и если кол-во Установленных продуктов для рассчета общей стоимости не равно 0*/
            if(!kol_cof.isEmpty() && !kol_bl.isEmpty() && kol_bl.toInt()!=0 && kol_cof.toInt()!=0)
            {
                //рассчет общей стоимости заданного кол-ва продуктов
                tmp = kol_cof.toInt() * Get_Cost_ElekCoffee();
                tmp += kol_bl.toInt() * Get_Cost_ElekBlender();
                //tmp = total_cost_elekCoffee + total_cost_elekBlender;
                ui->total_cost_sell_product_label->setText(QString::number(tmp) + "руб");
            }else{
                if(kol_cof.isEmpty())
                {
                    ui->countSell_cof_line->setFocus();
                    ui->Cof_label->setStyleSheet("color: red");
                }
                if(kol_bl.isEmpty())
                {
                    ui->countSell_Bl_line->setFocus();
                    ui->Bl_label->setStyleSheet("color: red");
                }
            }
        }else
            //Если вы хотите Рассчитать общую стоимость двух продуктов Блендера и Мсорубки
            if(ui->sell_elBl_check->isChecked() && ui->sell_elMyasoR_check->isChecked())
            {
                 /*Проверяем LineEdit на пустоту(Введены ли данные в поле) и если кол-во Установленных продуктов для рассчета общей стоимости не равно 0*/
                if(!kol_bl.isEmpty() && !kol_myas.isEmpty() && kol_bl.toInt()!=0 && kol_myas.toInt()!=0)
                {
                    //рассчет общей стоимости заданного кол-ва продуктов
                    tmp = kol_myas.toInt() * Get_Cost_ElekMyasoR();
                    tmp += kol_bl.toInt() * Get_Cost_ElekBlender();
                    //tmp = total_cost_elekMyasoR + total_cost_elekBlender;
                    ui->total_cost_sell_product_label->setText(QString::number(tmp) + "руб");
                }else{
                    if(kol_bl.isEmpty())
                    {
                        ui->countSell_Bl_line->setFocus();
                        ui->Bl_label->setStyleSheet("color: red");
                    }
                    if(kol_myas.isEmpty())
                    {
                        ui->countSell_MyasoR_line->setFocus();
                        ui->MyasoR_label->setStyleSheet("color: red");
                    }
                }
            }else
                //Если вы хотите Рассчитать общую стоимость двух продуктов Кофемолки и Мясорубки
                if(ui->sell_elCof_check->isChecked() && ui->sell_elMyasoR_check->isChecked())
                {
                     /*Проверяем LineEdit на пустоту(Введены ли данные в поле) и если кол-во Установленных продуктов для рассчета общей стоимости не равно 0*/
                    if(!kol_cof.isEmpty() && !kol_myas.isEmpty() && kol_cof.toInt()!=0 && kol_myas.toInt()!=0)
                    {
                        //рассчет общей стоимости заданного кол-ва продуктов
                        tmp = kol_cof.toInt() * Get_Cost_ElekCoffee();
                        tmp += kol_myas.toInt() * Get_Cost_ElekMyasoR();
                        //tmp = total_cost_elekCoffee + total_cost_elekMyasoR + total_cost_elekBlender;
                        ui->total_cost_sell_product_label->setText(QString::number(tmp) + "руб");
                    }else{
                        if(kol_cof.isEmpty())
                        {
                            ui->countSell_cof_line->setFocus();
                            ui->Cof_label->setStyleSheet("color: red");
                        }
                        if(kol_myas.isEmpty())
                        {
                            ui->countSell_MyasoR_line->setFocus();
                            ui->MyasoR_label->setStyleSheet("color: red");
                        }
                    }
                }else
                    //Если вы хотите Рассчитать общую стоимость одного продукта Кофемолки
                    if(ui->sell_elCof_check->isChecked())
                    {
                         /*Проверяем LineEdit на пустоту(Введены ли данные в поле) и если кол-во Установленных продуктов для рассчета общей стоимости не равно 0*/
                        if(!kol_cof.isEmpty() && kol_cof.toInt() != 0)
                        {
                            //рассчет общей стоимости заданного кол-ва продуктов
                            tmp = kol_cof.toInt() * Get_Cost_ElekCoffee();
                            ui->total_cost_sell_product_label->setText(QString::number(tmp) + "руб");
                        }else{
                            ui->countSell_cof_line->setFocus();
                            ui->Cof_label->setStyleSheet("color: red");
                        }
                    }else
                        //Если вы хотите Рассчитать общую стоимость одного продукта Блендера
                        if(ui->sell_elBl_check->isChecked())
                        {
                             /*Проверяем LineEdit на пустоту(Введены ли данные в поле) и если кол-во Установленных продуктов для рассчета общей стоимости не равно 0*/
                            if(!kol_bl.isEmpty() && kol_bl.toInt() != 0)
                            {
                                //рассчет общей стоимости заданного кол-ва продуктов
                                tmp = kol_bl.toInt() * Get_Cost_ElekBlender();
                                ui->total_cost_sell_product_label->setText(QString::number(tmp) + "руб");
                            }else{
                                ui->countSell_Bl_line->setFocus();
                                ui->Bl_label->setStyleSheet("color: red");
                            }
                        }else
                            //Если вы хотите Рассчитать общую стоимость одного продукта Мясорубки
                            if(ui->sell_elMyasoR_check->isChecked())
                            {
                                 /*Проверяем LineEdit на пустоту(Введены ли данные в поле) и если кол-во Установленных продуктов для рассчета общей стоимости не равно 0*/
                                if(!kol_myas.isEmpty() && kol_myas.toInt() != 0)
                                {
                                    //рассчет общей стоимости заданного кол-ва продуктов
                                    tmp = kol_myas.toInt() * Get_Cost_ElekMyasoR();
                                    ui->total_cost_sell_product_label->setText(QString::number(tmp) + "руб");
                                }else{
                                    ui->countSell_MyasoR_line->setFocus();
                                    ui->MyasoR_label->setStyleSheet("color: red");
                                }
                            }
}

