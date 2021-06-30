#include "save_data.h"
#include "ui_save_data.h"
#include <QTextCodec>

Save_Data::Save_Data(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Save_Data)
{
    ui->setupUi(this);

    cost_elCof = 0;
    cost_elBl = 0;
    cost_elMyas = 0;

    //Блокируем кнопку закрытия окна
    setWindowFlags(Qt::Window
         | Qt::WindowMinimizeButtonHint
         | Qt::WindowMaximizeButtonHint
         | Qt::CustomizeWindowHint);

    work_save = new Worker(this);
    sup_save = new Supplier(this);
    sklad_save = new Storage(this);
}

Save_Data::~Save_Data()
{
    delete ui;
}

void Save_Data::SaveData(Worker &work, Supplier &sup, Storage &sklad)
{
    show();
    work_save = &work;
    sup_save = &sup;
    sklad_save = &sklad;
    exec();
}

//Запись в файл сотрудников
void Save_Data::Save_Data_toFile_W(QString fileNameW)
{
    //Создать поток для записи в файл
    QFile record_W(fileNameW);//Устанавливаем путь к файлу fileNameW

    if(record_W.open(QFile::WriteOnly | QFile::Text))//Если файл  открылся
    {
        QTextStream out(&record_W);//Помогает записать данные в файл
        out.setCodec("Windows-1251"); //Помогает записать данные на кириллице

        out << tr("Количество сотрудников:\t") <<  work_save->Get_Work().size() << endl;
        for(i = 0; i < work_save->Get_Work().size(); i++) // Запись сотрудников
        {
            out << i+1 <<tr(")ФИО:\t") <<  work_save->Get_Work()[i] << tr("\t")
                    << work_save->Get_Work_Name()[i] << tr("\t")
                    << work_save->Get_Work_Ochestvo()[i] << endl;
            out << tr("Зарплата:\t") << work_save->Get_Work_ZP() << endl;

            //Если это не последий сотрудник
            if(i < work_save->Get_Work().size() - 1)
                out << tr("Номер телефона:\t") << work_save->Get_Work_Phone()[i] << endl;
            else//Если это последий сотрудник
                out << tr("Номер телефона:\t") << work_save->Get_Work_Phone()[i];
        }
        QMessageBox::information(this, "Результат", "Данные о сотрудниках сохранены!");
    }else
        QMessageBox::warning(this, "Ошибка", "Ошибка открытия файла для записи сотрудников!");

    record_W.close();
}


/*Запись в файл Поставщика, стоимость продуктов и комплектов деталей, количество комлектов деталей и собранных продуктов*/
void Save_Data::Save_Data_toFile_SP(QString fileNameS, QString fileNameP)
{
    //Создать поток для записи в файл
    QFile record_S(fileNameS);//Устанавливаем путь к файлу fileNameS, fileNameP
    QFile record_P(fileNameP);

    if(record_S.open(QFile::WriteOnly | QFile::Text))//Если файл открылся
    {
        QTextStream out_S(&record_S);//Помогает записать данные в файл
        out_S.setCodec("Windows-1251");//помогает записать кириллицу

        // Запись данных поставщика
        out_S << tr("ФИО и номер телефона:\t");
        for(i = 0; i < sup_save->Get_Supplier().size(); i++)
        {
            if(i < sup_save->Get_Supplier().size() - 1)
                out_S << sup_save->Get_Supplier()[i] << tr("\t");
            else
                out_S << sup_save->Get_Supplier()[i];
        }

        QMessageBox::information(this, "Результат", "Данные о поставщике сохранены!");
    }else
        QMessageBox::warning(this, "Ошибка", "Ошибка открытия файла для записи паставщика!");


            if(record_P.open(QFile::WriteOnly | QFile::Text))
            {
                QTextStream out_P(&record_P);
                out_P.setCodec("Windows-1251");

                out_P << tr("\nСтоимость комлекта деталей для:") << endl;
                out_P << tr("1) Электрической Кофемолки - ") << sup_save->Get_Cost_KitD_Sup_ElCoffee() << tr(" руб") << endl;
                out_P << tr("2) Электрического Блендера - ") << sup_save->Get_Cost_KitD_Sup_ElBlender() << tr(" руб") << endl;
                out_P << tr("3) Электрической Мясорубки - ") << sup_save->Get_Cost_KitD_Sup_ElMyasoR() << tr(" руб") << endl;

                cost_elCof = sklad_save->Get_kit_ElekCoffee() * sup_save->Get_Cost_KitD_Sup_ElCoffee();
                cost_elBl = sklad_save->Get_kit_ElekBlender() * sup_save->Get_Cost_KitD_Sup_ElBlender();
                cost_elMyas = sklad_save->Get_kit_ElekMyasoR() * sup_save->Get_Cost_KitD_Sup_ElMyasoR();

                //Запись кол-ва комлекта деталей
                out_P << tr("Количесиво комлектов деталей для сборки бытовой техники находящиеся в складе:") << endl;

                out_P << tr("1)Для Электрической Кофемолки - ") << sklad_save->Get_kit_ElekCoffee()
                      << tr(". Общая стоимость - ") << cost_elCof << tr(" руб") << endl;
                out_P << tr("2)Для Электрического Блендера - ") << sklad_save->Get_kit_ElekBlender()
                      << tr(". Общая стоимость - ") << cost_elBl << tr(" руб") << endl;
                out_P << tr("3)Для Электрической Мясорубки - ") << sklad_save->Get_kit_ElekMyasoR()
                      << tr(". Общая стоимость - ") << cost_elMyas << tr(" руб") << endl << endl;

                cost_elCof = sklad_save->Get_collected_ElekCoffee() * sklad_save->Get_Cost_ElekCoffee();
                cost_elBl = sklad_save->Get_collected_ElekBlender() * sklad_save->Get_Cost_ElekBlender();
                cost_elMyas = sklad_save->Get_collected_ElekMyasoR() * sklad_save->Get_Cost_ElekMyasoR();

                //Запись количествa готового продукта бытовой техники
                out_P << tr("Количество готового продукта бытовой техники которое находится в складе:") << endl;
                out_P << tr("1) Электрической Кофемолки - ") << sklad_save->Get_collected_ElekCoffee()
                      << tr(". Общая стоимость - ") << cost_elCof << tr(" руб") << endl;
                out_P << tr("2) Электрического Блендера - ") << sklad_save->Get_collected_ElekBlender()
                      << tr(". Общая стоимость - ") << cost_elBl << tr(" руб") << endl;
                out_P << tr("3) Электрической Мясорубки - ") << sklad_save->Get_collected_ElekMyasoR()
                      << tr(". Общая стоимость - ") << cost_elMyas << tr(" руб") << endl << endl;
                //Запись цены готового продукта
                out_P << tr("Стоимость одного готового продукта бытовой техники для:") << endl;
                out_P << tr("1) Электрической Кофемолки - ") << sklad_save->Get_Cost_ElekCoffee() << endl;
                out_P << tr("2) Электрического Блендера - ") << sklad_save->Get_Cost_ElekBlender() << endl;
                out_P << tr("3) Электрической Мясорубки - ") << sklad_save->Get_Cost_ElekMyasoR() << endl << endl;

                out_P << tr("Кол-во комплектов деталей заказаных за все время и их общая стоимость:") << endl;
                out_P << tr("Вы за все время заказали - ") << sklad_save->get_count_kit_ElekCoffee()
                      << tr(" детаей для кофемолки, ") << tr("их общая стоимость - ")
                      << sklad_save->get_Total_costOrder_elCoffee() << tr(" руб") << endl;
                out_P << tr("Вы за все время заказали - ") << sklad_save->get_count_kit_ElekBlender() <<
                      tr(" деталей для блендера, ") << tr("их общая стоимость - ")
                      << sklad_save->get_Total_costOrder_elBlender() << tr(" руб") << endl;
                out_P << tr("Вы за все время заказали - ") << sklad_save->get_count_kit_ElekCoffee() <<
                      tr(" деталей для мясорубки, ") << tr("их общая стоимость - ")
                      << sklad_save->get_Total_costOrder_elMyasoR() << tr(" руб") << endl << endl;

                out_P << tr("кол-во продуктов бытовой техники, проданных за все времмя и общая их стоимость") << endl;
                out_P <<tr("Вы за все время продали - ") << sklad_save->get_quantity_SEllelekCoffee()
                      << tr(" кофемолок, ") << tr("их общая стоимость - ")
                      << sklad_save->get_total_costSell_elekCoffee() << tr("руб") << endl;
                out_P <<tr("Вы за все время продали - ") << sklad_save->get_quantity_SEllelekBlender()
                      << tr(" блендеров, ") << tr("их общая стоимость - ")
                      << sklad_save->get_total_costSell_elekBlender() << tr("руб") << endl;
                out_P <<tr("Вы за все время продали - ") << sklad_save->get_quantity_SEllelekMyasoR()
                      << tr(" мясорубок, ") << tr("их общая стоимость - ")
                      << sklad_save->get_total_costSell_elekMyasoR() << tr("руб") << endl << endl;

                QMessageBox::information(this, "Результат", "Данные о товарах сохранены!");
            }else
                QMessageBox::warning(this, "Ошибка", "Ошибка открытия файла для записи цен на готовый продукт бытовой техники!");


    record_P.close();
    record_S.close();
}

//возвращаемся в меню
void Save_Data::on_to_Menu_clicked()
{
    ui->worker_toFile_label->setStyleSheet("color: black");
    ui->supCost_toFile_label->setStyleSheet("color: black");
    ui->kitProductCost_toFile_label->setStyleSheet("color: black");
    ui->worker_toFile_line->clear();
    ui->supCost_toFile_line->clear();
    ui->kitProductCost_toFile_line->clear();
    close();
}

//ЗАписать данные в файл
void Save_Data::on_to_File_btn_clicked()
{
    //Если строки(указание пути к файлу) НЕ пусты
    if(!ui->worker_toFile_line->text().isEmpty() && !ui->supCost_toFile_line->text().isEmpty() && !ui->kitProductCost_toFile_line->text().isEmpty())
    {
        if(!work_save->Get_Work().empty())//Если Сотрудники есть
        {
            fileName_W = ui->worker_toFile_line->text();//записываем путь к файлу в fileName_W

            Save_Data_toFile_W(fileName_W); //Вызываем метод, для записи данных сотрудников  в файл
        }else
            QMessageBox::warning(this, "Ошибка", "У вас нет сотрудников, добавьте сотрудников чтобы сохранить их данные");

        if(!sup_save->Get_Supplier().empty())//Если поставщик есть
        {
            /*записываем путь к файлу в fileName_S для записи данных поставщика*/
            fileName_S = ui->supCost_toFile_line->text();

            /*записываем путь к файлу для записи данных о деталях и продуктах в fileName_P*/
            fileName_P = ui->kitProductCost_toFile_line->text();
            //Вызываем метод сохранения данных в файл поставщикаб деталей и продукта
            Save_Data_toFile_SP(fileName_S, fileName_P);
        }else
            QMessageBox::warning(this, "Ошибка", "У вас нет поставщика, добавьте его чтобы сохранить его данные");
        close();//Закрываем окно
    }else{//иначе Если строки(указание пути к файлу) пусты
        if(ui->worker_toFile_line->text().isEmpty())//Если пусто
        {
            ui->worker_toFile_line->setFocus();
            ui->worker_toFile_label->setStyleSheet("color: red");/*worker_toFile_label(ПУТЬ К ФАЙЛУ) красим в красный*/
        }
        if(ui->supCost_toFile_line->text().isEmpty())//Если пусто
        {
            ui->supCost_toFile_line->setFocus();
            ui->supCost_toFile_label->setStyleSheet("color: red");
        }
        if(ui->kitProductCost_toFile_line->text().isEmpty())//Если пусто
        {
            ui->kitProductCost_toFile_line->setFocus();
            ui->kitProductCost_toFile_label->setStyleSheet("color: red");
        }
    }

}

//Проверка на пустоту
void Save_Data::on_worker_toFile_line_textChanged(const QString &arg1)
{
    //Если строка, для записи данных о сотрудниках, не пуста
    if(!arg1.isEmpty())
    {
        ui->worker_toFile_label->setStyleSheet("color: black");//worker_toFile_label(ПУТЬ К ФАЙЛУ) красим в черный
    }
}
//Проверка на пустоту
void Save_Data::on_supCost_toFile_line_textChanged(const QString &arg1)
{
    //Если строка, для записи данных о поставщике, не пуста
    if(!arg1.isEmpty())
    {
        ui->supCost_toFile_label->setStyleSheet("color: black");
    }
}
//Проверка на пустоту
void Save_Data::on_kitProductCost_toFile_line_textChanged(const QString &arg1)
{
    //Если строка, для записи данных о комлектах деталей и продуктах, не пуста
    if(!arg1.isEmpty())
    {
        ui->kitProductCost_toFile_label->setStyleSheet("color: black");
    }
}
