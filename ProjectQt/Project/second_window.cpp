#include "second_window.h"
#include "ui_second_window.h"
#include <QMessageBox>

Second_Window::Second_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Second_Window)
{
    ui->setupUi(this);

    //Блокируем кнопку закрытия окна
    setWindowFlags(Qt::Window
         | Qt::WindowMinimizeButtonHint
         | Qt::WindowMaximizeButtonHint
         | Qt::CustomizeWindowHint);

    /*Это то, что заставляет форму автоматически изменять размер  автоматическое изменение размера на виджете hide/show*/
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);

    //Показываем окно
    ui->CreateProduct->show();
    //Скрываем окна
    ui->collectProduct->hide();
    ui->Find_SNP_delete->hide();
    ui->find_worker_phone_delete->hide();
    ui->Choce_Find_delete->hide();

    ui->Install_zpCost_Box->hide();
    ui->install_ZP_Box->hide();
    ui->install_costProduct_Box->hide();
    ui->Print_costProduct_Box->hide();

    ui->InstallWorkerCreate->hide();
    ui->choiceCreate->hide();

    ui->BackChoiceCreate_Btn->hide();
    ui->CollectProduct_Btn->hide();
    ui->elKof->hide();
    ui->elMyasoR->hide();

    N_Employees = 0; //Количество сотрудников которое будет собирать продукты
    count_product_create = 0; //Количество продуктов которое мы будем собирать

    zp = 0; //Зарплата
    cost = 0; //цена продукта
    n=0;   // Помогает выбрать условие

    _sup = new Supplier(this);
    _work = new Worker(this);
    _sklad = new Storage(this);
    _save = new Save_Data(this);

    //Устанавливаем ограничение на ввод
    QRegExp phone("[0-9]{1,11}");
    QRegExp Zp("[0-9]{1,11}");
    QRegExp str_line("[a-zA-Zа-яА-Я]{1,999}");

    //Устанавливаем, где строки будут ограничены
    ui->find_phone_line->setValidator(new QRegExpValidator(phone, this));

    ui->zp_line->setValidator(new QRegExpValidator(Zp, this));
    ui->CostProduct_line->setValidator(new QRegExpValidator(Zp, this));
    ui->introduceCountWorker_line->setValidator(new QRegExpValidator(Zp, this));
    ui->countCreate_elBL_line->setValidator(new QRegExpValidator(Zp, this));
    ui->elMyasoR_line->setValidator(new QRegExpValidator(Zp, this));
    ui->elKof_line->setValidator(new QRegExpValidator(Zp, this));
    ui->zp_line->setValidator(new QRegExpValidator(Zp, this));

    ui->FindLastName->setValidator(new QRegExpValidator(str_line, this));
    ui->FindName->setValidator(new QRegExpValidator(str_line, this));
    ui->FindPatronymic->setValidator(new QRegExpValidator(str_line, this));
}

Second_Window::~Second_Window()
{
    delete ui;
}

//Создание продукта или установка кол-ва сотрудников для сборки продукта
void Second_Window::create_Product(Worker &work, Storage & sklad)
{
    show();
    _sklad=&sklad;
    _work=&work;
    ui->CreateProduct->show();//Показываем окно
    ui->InstallWorkerCreate->hide();//срываем окна
    ui->choiceCreate->hide();
    ui->CreateProduct_check->setChecked(false);//Убираем галочки
    ui->createProductWorker_Check->setChecked(false);
    exec();
}

//Кнопка ОК определяем какой из checkBox-сов выбрать
void Second_Window::on_CreateProductCheck_Btn_clicked()
{
    //Если поставлено две галочки
    if(ui->CreateProduct_check->isChecked()==false && ui->createProductWorker_Check->isChecked()==false)
        QMessageBox::warning(this, "Ошибка", "Сделайте выбор!");

    //Если выбрали установку количества сотрудников которые будут собирать продукт
    if(ui->createProductWorker_Check->isChecked())
    {
        if(_work->Get_Work().empty())//Если сотрудников нет
        {
            QMessageBox::warning(this, "Ошибка", "Нет сотрудников! Дабавьте сотрудника");
            ui->createProductWorker_Check->setChecked(false);
        } else {
            //Показываем окно, установки кол-ва сотрудников, которые будут собирать продукт
            ui->InstallWorkerCreate->show();
            //скрываем выбор создания продукта или установки кол-ва сотрудников
            ui->CreateProduct->hide();
        }
    }

    //Если выбрали создание продукта
    if(ui->CreateProduct_check->isChecked())
    {
        if(_work->Get_Work().empty())//Проверка на наличие сотрудников
        {
            QMessageBox::warning(this,"Ошибка", "Нет сотрудников!\nДабавьте сотрудника!");
            ui->CreateProduct_check->setChecked(false);
        }else
            if(N_Employees == 0)/*Если не установлено кол-во сотрудников которое будет собирать продукт*/
            {
                QMessageBox::warning(this, "Ошибка!", "Кто будет собирать продукты?\n"
                                                      "Вы не указали сколько сотрудников будет собирать продукт!"
                                                      "Установите кол-во сотрудников!\nВыберите в меню пунк 7 затем 1\n");
                ui->CreateProduct_check->setChecked(false);
            }else {
                //Показать окно выбора того что вы хотите создать
                ui->choiceCreate->show();
                //скрываем выбор создания продукта или установки кол-ва сотрудников
                ui->CreateProduct->hide();
        }
    }
}

//Вернуться в меню
void Second_Window::on_backToMenu_Btn_clicked()
{
    ui->CreateProduct->hide();//скрывааем, выбор создания продукта или установки кол-ва сотрудников
    ui->createProductWorker_Check->setChecked(false);//Убираем галочки с выбора
    ui->CreateProduct_check->setChecked(false);
    close();//закрываем окно
}

/*Устанавливаем кол-во сотрудников собирающих бытовую технику*/
void Second_Window::on_introduceWorker_Btn_clicked()
{
    //Если строка кол-ва сотрудников НЕ пуста
    if(!ui->introduceCountWorker_line->text().isEmpty())
    {
        //Записываем кол-восотрудников собирающих бытовую технику в N_Employees
        N_Employees = ui->introduceCountWorker_line->text().toUInt();
        //Отчищаем строку кол-ва сотрудников собирающих бытовую технику
        ui->introduceCountWorker_line->clear();

        //Если кол-во сотрудников собирающих бытовую технику установлено больше сотрудников которые есть
        if(N_Employees > _work->Get_Work().size())
        {
            QMessageBox::warning(this, "Ошибка!", "Недостаточно сотрудников, попробуйте снова!");
            N_Employees = 0;
        }
        //Скрываем окно установки кол-ва сотрудников собирающих бытовую технику
        ui->InstallWorkerCreate->hide();
        //Показываем окно выбора, создани продукта или установки кол-ва сотрудников
        ui->CreateProduct->show();
        //Убираем галочку с выбора установки кол-ва сотрудников собирающих бытовую технику
        ui->createProductWorker_Check->setChecked(false);
    }else{//Если строка кол-ва сотрудников пуста
        ui->introduceCountWorker_line->setFocus();
        ui->introduceCountWorker_label->setStyleSheet("color: red");
    }
}

//кнопка Назад возвращающая в окно выбора, создани продукта или установки кол-ва сотрудников
void Second_Window::on_BackCreateProduct_Btn_clicked()
{
    ui->introduceCountWorker_label->setStyleSheet("color: black");
    //Показываем окно выбора, создани продукта или установки кол-ва сотрудников
    ui->CreateProduct->show();
    //Скрываем окно установки кол-ва сотрудников собирающих бытовую технику
    ui->InstallWorkerCreate->hide();
    //Срываем окно выбора того что вы хотите создать
    //ui->choiceCreate->hide();
    //Отчищаем строку установки кол-ва сотрудников собирающих бытовую технику
    ui->introduceCountWorker_line->clear();
    //Убираем галочки с выбора, создани продукта или установки кол-ва сотрудников
    ui->CreateProduct_check->setChecked(false);
    ui->createProductWorker_Check->setChecked(false);
}

//Кнопка возвращает в окно выбора, создани продукта или установки кол-ва сотрудников
void Second_Window::on_backCreateProduct_btn_clicked()
{
    //Показываем окно выбора, создани продукта или установки кол-ва сотрудников
    ui->CreateProduct->show();
    //Скрываем окно установки кол-ва сотрудников собирающих бытовую технику
    //ui->InstallWorkerCreate->hide();
    //Скрываем окно выбора того что вы хотите создать
    ui->choiceCreate->hide();
    //Убираем галочки с выбора, создании продукта или установки кол-ва сотрудников
    ui->CreateProduct_check->setChecked(false);
    ui->createProductWorker_Check->setChecked(false);
    //Убираем галочки с выбора какие продукты собрать
    ui->toCollectElCoffee_check->setChecked(false);
    ui->toCollectElMyasoR_check->setChecked(false);
    ui->toCollectElBlender_check->setChecked(false);
}

//Убираем галочки с выбора сборки
void Second_Window::ChoiceCollectProduct_setChecked_false()
{
    ui->toCollectElCoffee_check->setChecked(false);
    ui->toCollectElMyasoR_check->setChecked(false);
    ui->toCollectElBlender_check->setChecked(false);
    close();
}

//Кнопка выбора какие продукты собрать
void Second_Window::on_toCollect_Btn_clicked()
{
    //Убираем галочку с выбора, создании продукта
    ui->CreateProduct_check->setChecked(false);
    //Если выбор всех трех продуктов сделан
    if(ui->toCollectElCoffee_check->isChecked() && ui->toCollectElMyasoR_check->isChecked() && ui->toCollectElBlender_check->isChecked())
    {
        if(_sklad->Get_kit_ElekBlender() != 0)//Если детали есть
        {
            if(_sklad->Get_kit_ElekCoffee() != 0)
            {
                if(_sklad->Get_kit_ElekMyasoR() != 0)
                {
                    //Показать окно эл.блендера
                    ui->collectProduct->show();
                    /*скрыть окно выбора сборки и окно выбора создать продукт или установить кол-во сотрудников собирающих бытовую технику*/
                    ui->choiceCreate->hide();
                    ui->CreateProduct->hide();
                    //Показать окно эл.Мясорубки
                    ui->elMyasoR->show();
                    //Показать окно эл.Кофемолки
                    ui->elKof->show();
                    //Показать кнопки назад и сборки
                    ui->BackChoiceCreate_Btn->show();
                    ui->CollectProduct_Btn->show();
                } else {
                    QMessageBox::warning(this, "Ошибка!", "Вы не можете собрать все три продукта!\n"
                                                          "У вас нет комплекта деталей чтобы собрать Мясорубку!\n"
                                                          "Закажите N-ое кол-во деталей у паставщика!");
                    ChoiceCollectProduct_setChecked_false();//Убираем галочки с выбора сборки
                }
            } else {
                QMessageBox::warning(this, "Ошибкa!", "Вы не можете собрать все три продукта!\n"
                                                      "У вас нет комплекта деталей чтобы собрать кофемолку!\n"
                                                      "Закажите N-ое кол-во деталей у паставщика!");
                ChoiceCollectProduct_setChecked_false();//Убираем галочки с выбора сборки
            }
        } else {
            QMessageBox::warning(this, "Ошибка!", "Вы не можете собрать все три продукта!\n"
                                       "У вас нет комплекта деталей чтобы собрать блендер!\n"
                                       "Закажите N-ое кол-во деталей у паставщика!");
            ChoiceCollectProduct_setChecked_false();//Убираем галочки с выбора сборки
        }
    }else
        //Если выбор двух продуктов сделан(Кофемолка и Мясорубка)
        if(ui->toCollectElCoffee_check->isChecked() && ui->toCollectElMyasoR_check->isChecked())
        {
            if(_sklad->Get_kit_ElekCoffee() != 0)
            {
                if(_sklad->Get_kit_ElekMyasoR() != 0)
                {
                    /*скрыть окно выбора сборки и окно выбора создать продукт или установить кол-во сотрудников собирающих бытовую технику*/
                    ui->choiceCreate->hide();
                    ui->CreateProduct->hide();
                    //Скрыть окно эл.блендера
                    ui->collectProduct->hide();
                    //Показать окно эл.Мясорубки
                    ui->elMyasoR->show();
                    //Показать окно эл.Кофемолки
                    ui->elKof->show();
                    //Показать кнопки назад и сборки
                    ui->BackChoiceCreate_Btn->show();
                    ui->CollectProduct_Btn->show();
                } else {
                    QMessageBox::warning(this, "Ошибка!", "Вы не можете собрать все три продукта!\n"
                                                          "У вас нет комплекта деталей чтобы собрать Мясорубку!\n"
                                                          "Закажите N-ое кол-во деталей у паставщика!");
                    ChoiceCollectProduct_setChecked_false();//Убираем галочки с выбора сборки
                }
            } else {
                QMessageBox::warning(this, "Ошибкa!", "Вы не можете собрать все три продукта!\n"
                                                      "У вас нет комплекта деталей чтобы собрать кофемолку!\n"
                                                      "Закажите N-ое кол-во деталей у паставщика!");
                ChoiceCollectProduct_setChecked_false();//Убираем галочки с выбора сборки
            }
        }else
            //Если выбор двух продуктов сделан(Мясорубка и Блендер)
            if(ui->toCollectElMyasoR_check->isChecked() && ui->toCollectElBlender_check->isChecked())
            {
                if(_sklad->Get_kit_ElekBlender() != 0)//Если детали есть
                {
                    if(_sklad->Get_kit_ElekMyasoR() != 0)
                    {
                        /*скрыть окно выбора сборки и окно выбора создать продукт или установить кол-во сотрудников собирающих бытовую технику*/
                        ui->choiceCreate->hide();
                        ui->CreateProduct->hide();
                        //Показать окно эл.блендера
                        ui->collectProduct->show();
                        //Показать окно эл.Мясорубки
                        ui->elMyasoR->show();
                        //Скрыть окно эл.Кофемолки
                        ui->elKof->hide();
                        //Показать кнопки назад и сборки
                        ui->BackChoiceCreate_Btn->show();
                        ui->CollectProduct_Btn->show();
                    } else {
                        QMessageBox::warning(this, "Ошибка!", "Вы не можете собрать все три продукта!\n"
                                                              "У вас нет комплекта деталей чтобы собрать Мясорубку!\n"
                                                              "Закажите N-ое кол-во деталей у паставщика!");
                        ChoiceCollectProduct_setChecked_false();//Убираем галочки с выбора сборки
                    }
                } else {
                    QMessageBox::warning(this, "Ошибка!", "Вы не можете собрать все три продукта!\n"
                                           "У вас нет комплекта деталей чтобы собрать блендер!\n"
                                           "Закажите N-ое кол-во деталей у паставщика!");
                    ChoiceCollectProduct_setChecked_false();//Убираем галочки с выбора сборки
                }
            }else
                //Если выбор двух продуктов сделан(Кофемолка и Блендер)
                if(ui->toCollectElCoffee_check->isChecked() && ui->toCollectElBlender_check->isChecked())
                {
                    if(_sklad->Get_kit_ElekBlender() != 0)//Если детали есть
                    {
                        if(_sklad->Get_kit_ElekCoffee() != 0)
                        {
                            /*скрыть окно выбора сборки и окно выбора создать продукт или установить кол-во сотрудников собирающих бытовую технику*/
                            ui->CreateProduct->hide();
                            ui->choiceCreate->hide();
                            //Показать окно эл.блендера
                            ui->collectProduct->show();
                            //Скрыть окно эл.Мясорубки
                            ui->elMyasoR->hide();
                            //Показать окно эл.Кофемолки
                            ui->elKof->show();
                            //Показать кнопки назад и сборки
                            ui->BackChoiceCreate_Btn->show();
                            ui->CollectProduct_Btn->show();
                        } else {
                            QMessageBox::warning(this, "Ошибкa!", "Вы не можете собрать все три продукта!\n"
                                                              "У вас нет комплекта деталей чтобы собрать кофемолку!\n"
                                                              "Закажите N-ое кол-во деталей у паставщика!");
                            ChoiceCollectProduct_setChecked_false();//Убираем галочки с выбора сборки
                        }
                    } else {
                        QMessageBox::warning(this, "Ошибка!", "Вы не можете собрать все три продукта!\n"
                                                   "У вас нет комплекта деталей чтобы собрать блендер!\n"
                                                   "Закажите N-ое кол-во деталей у паставщика!");
                        ChoiceCollectProduct_setChecked_false();//Убираем галочки с выбора сборки
                    }
                }else
                    //Если продукта сделан(Кофемолка)
                    if(ui->toCollectElCoffee_check->isChecked())
                    {
                        //Если на складе комплектов деталей для сборки кофемолки нет
                        if(_sklad->Get_kit_ElekCoffee() == 0)
                        {
                            QMessageBox::warning(this, "Ошибка!", "У вас нет деталей для сборки эл. кофемолки!\nЗакажите у паставщика");
                            ChoiceCollectProduct_setChecked_false();//Убираем галочки с выбора сборки
                        }
                        else {//Если есть
                            /*скрыть окно выбора сборки и окно выбора создать продукт или установить кол-во сотрудников собирающих бытовую технику*/
                            ui->choiceCreate->hide();
                            ui->CreateProduct->hide();
                            //Скрыть окно эл.блендера
                            ui->collectProduct->hide();
                            //Скрыть окно эл.Мясорубки
                            ui->elMyasoR->hide();
                            //Показать окно эл.Кофемолки
                            ui->elKof->show();
                            //Показать кнопки назад и сборки
                            ui->BackChoiceCreate_Btn->show();
                            ui->CollectProduct_Btn->show();
                        }
                    }else
                        //Если продукта сделан(Блендер)
                        if(ui->toCollectElBlender_check->isChecked())
                        {
                            //Если на складе комплектов деталей для сборки блендера нет
                            if(_sklad->Get_kit_ElekBlender() == 0)
                            {
                                QMessageBox::warning(this, "Ошибка!", "У вас нет деталей для сборки эл. блендера!\nЗакажите у паставщика!");
                                ChoiceCollectProduct_setChecked_false();//Убираем галочки с выбора сборки
                            }
                            else {//Если есть
                                /*скрыть окно выбора сборки и окно выбора создать продукт или установить кол-во сотрудников собирающих бытовую технику*/
                                ui->choiceCreate->hide();
                                ui->CreateProduct->hide();
                                //Показать окно эл.блендера
                                ui->collectProduct->show();
                                //Скрыть окно эл.Мясорубки
                                ui->elMyasoR->hide();
                                //Скрыть окно эл.Кофемолки
                                ui->elKof->hide();
                                //Показать кнопки назад и сборки
                                ui->BackChoiceCreate_Btn->show();
                                ui->CollectProduct_Btn->show();
                            }
                        }else
                            //Если продукта сделан(Мясорубка)
                            if(ui->toCollectElMyasoR_check->isChecked())
                            {
                                //Если на складе комплектов деталей для сборки мясорубки нет
                                if(_sklad->Get_kit_ElekMyasoR() == 0)
                                {
                                    QMessageBox::warning(this, "Ошибка!", "У вас нет деталей для сборки эл. мясорубки!\nЗакажите у паставщика");
                                    ChoiceCollectProduct_setChecked_false();//Убираем галочки с выбора сборки
                                }
                                else {//Если есть
                                    /*скрыть окно выбора сборки и окно выбора создать продукт или установить кол-во сотрудников собирающих бытовую технику*/
                                    ui->choiceCreate->hide();
                                    ui->CreateProduct->hide();
                                    //Скрыть окно эл.блендера
                                    ui->collectProduct->hide();
                                    //Показать окно эл.Мясорубки
                                    ui->elMyasoR->show();
                                    //Скрыть окно эл.Кофемолки
                                    ui->elKof->hide();
                                    //Показать кнопки назад и сборки
                                    ui->BackChoiceCreate_Btn->show();
                                    ui->CollectProduct_Btn->show();
                                }
                            }else{
                                QMessageBox::warning(this, "Ошибка", "Сделайте выбор!");
                            }
}

//Завершение сборки продукта
void Second_Window::collect_product_finish()
{
    close();//Закрыть окно
    //Скрыть окна
    ui->BackChoiceCreate_Btn->hide();
    ui->CollectProduct_Btn->hide();
    ui->collectProduct->hide();
    ui->elKof->hide();
    ui->elMyasoR->hide();
    //Отчистить строки
    ui->countCreate_elBL_line->clear();
    ui->elKof_line->clear();
    ui->elMyasoR_line->clear();
    //убрать галочки с выбора сборки
    ui->toCollectElCoffee_check->setChecked(false);
    ui->toCollectElMyasoR_check->setChecked(false);
    ui->toCollectElBlender_check->setChecked(false);
}

//Собрать продукт
void Second_Window::on_CollectProduct_Btn_clicked()
{
    //Если выбрали все три продукта для сборки
    if(ui->toCollectElCoffee_check->isChecked() && ui->toCollectElMyasoR_check->isChecked() && ui->toCollectElBlender_check->isChecked())
    {
        //Если строки для количества продуктов НЕ пусты
        if(!ui->countCreate_elBL_line->text().isEmpty() && !ui->elMyasoR_line->text().isEmpty() && !ui->elKof_line->text().isEmpty())
        {
            //присваиваем кол-во продуктов
            count_product_create = ui->countCreate_elBL_line->text().toUInt();
            int kof = ui->elKof_line->text().toUInt();
            int myas = ui->elMyasoR_line->text().toUInt();

            /*Вызываем метод собирающий все продукты*/
            _sklad->Collect_All_Product(kof, count_product_create, myas, *_work, N_Employees);
            //Завершение сборки продукта
            collect_product_finish();
        }else{//Если строки для количества продуктов пусты
            if(ui->countCreate_elBL_line->text().isEmpty())//Если пусто
            {
                ui->countCreate_elBL_line->setFocus();
                ui->countCreate_elBL_label->setStyleSheet("color: red");//красим в красный "Количество Эл. Блендеров"
            }
            if(ui->elMyasoR_line->text().isEmpty())//Если пусто
            {
                ui->elMyasoR_line->setFocus();
                ui->elMyas_label->setStyleSheet("color: red");//красим в красный "Количество Эл. Мясорубок"
            }
            if(ui->elKof_line->text().isEmpty())//Если пусто
            {
                ui->elKof_line->setFocus();
                ui->elCof_label->setStyleSheet("color: red");//красим в красный "Количество Эл. Кофемолок"
            }
        }
    }else
        //Если выбрали два продукта для сборки(Кофемолка и Мясорубка)
        if(ui->toCollectElCoffee_check->isChecked() && ui->toCollectElMyasoR_check->isChecked())
        {
            //Если строки для количества продуктов НЕ пусты
            if(!ui->elMyasoR_line->text().isEmpty() && !ui->elKof_line->text().isEmpty())
            {
                //присваиваем кол-во продуктов
                count_product_create = ui->elKof_line->text().toInt();
                //Вызываем метод сборки Кофемолки
                _sklad->collect_ElekCoffee(count_product_create, *_work, N_Employees);

                count_product_create = ui->elMyasoR_line->text().toUInt();
                //Вызываем метод сборки Мясорубки
                _sklad->collect_ElekMyasoR(count_product_create, *_work, N_Employees);
                //Завершение сборки продукта
                collect_product_finish();
            }
            else{//Если строки для количества продуктов пусты
                if(ui->elMyasoR_line->text().isEmpty())
                {
                    ui->elMyasoR_line->setFocus();
                    ui->elMyas_label->setStyleSheet("color: red");
                }
                if(ui->elKof_line->text().isEmpty())
                {
                    ui->elKof_line->setFocus();
                    ui->elCof_label->setStyleSheet("color: red");
                }
            }
        }else
            //Если выбрали два продукта для сборки(Мясорубка и Блендер)
            if(ui->toCollectElMyasoR_check->isChecked() && ui->toCollectElBlender_check->isChecked())
            {
                //Если строки для количества продуктов НЕ пусты
                if(!ui->countCreate_elBL_line->text().isEmpty() && !ui->elMyasoR_line->text().isEmpty())
                {

                    count_product_create = ui->countCreate_elBL_line->text().toUInt();
                    //Вызываем метод сборки блендера
                    _sklad->collect_ElekBlender(count_product_create, *_work, N_Employees);

                    count_product_create = ui->elMyasoR_line->text().toInt();
                    //Вызываем метод сборки Мясорубки
                    _sklad->collect_ElekMyasoR(count_product_create, *_work, N_Employees);
                    //Завершение сборки продукта
                    collect_product_finish();
                }else{//Если строки для количества продуктов пусты
                    if(ui->countCreate_elBL_line->text().isEmpty())
                    {
                        ui->countCreate_elBL_line->setFocus();
                        ui->countCreate_elBL_label->setStyleSheet("color: red"); //Блендер
                    }
                    if(ui->elMyasoR_line->text().isEmpty())
                    {
                        ui->elMyasoR_line->setFocus();
                        ui->elMyas_label->setStyleSheet("color: red");
                    }
                }
            }else
                //Если выбрали два продукта для сборки(Кофемолки и Блендера)
                if(ui->toCollectElCoffee_check->isChecked() && ui->toCollectElBlender_check->isChecked())
                {
                    //Если строки для количества продуктов НЕ пусты
                    if(!ui->countCreate_elBL_line->text().isEmpty() && !ui->elKof_line->text().isEmpty())
                    {
                        count_product_create = ui->elKof_line->text().toUInt();
                        //Вызываем метод сборки Кофемолки
                        _sklad->collect_ElekCoffee(count_product_create, *_work, N_Employees);

                        count_product_create = ui->countCreate_elBL_line->text().toUInt();
                        //Вызываем метод сборки блендера
                        _sklad->collect_ElekBlender(count_product_create, *_work, N_Employees);
                        //Завершение сборки продукта
                        collect_product_finish();
                    }else{//Если строки для количества продуктов пусты
                        if(ui->countCreate_elBL_line->text().isEmpty())
                        {
                            ui->countCreate_elBL_line->setFocus();
                            ui->countCreate_elBL_label->setStyleSheet("color: red");
                        }
                        if(ui->elKof_line->text().isEmpty())
                        {
                            ui->elKof_line->setFocus();
                            ui->elCof_label->setStyleSheet("color: red");
                        }
                    }
                }else
                    //Если выбрали продукт для сборки(Кофемолки)
                    if(ui->toCollectElCoffee_check->isChecked())
                    {
                        //Если строки для количества продуктов НЕ пусты
                        if(!ui->elKof_line->text().isEmpty())
                        {
                            count_product_create = ui->elKof_line->text().toUInt();
                            //Вызываем метод сборки Кофемолки
                            _sklad->collect_ElekCoffee(count_product_create, *_work, N_Employees);
                            //Завершение сборки продукта
                            collect_product_finish();
                        }else{//Если строки для количества продуктов пусты
                            ui->elKof_line->setFocus();
                            ui->elCof_label->setStyleSheet("color: red");
                        }
                    }else
                        //Если выбрали продукт для сборки(Блендера)
                        if(ui->toCollectElBlender_check->isChecked())
                        {
                            //Если строки для количества продуктов НЕ пусты
                            if(!ui->countCreate_elBL_line->text().isEmpty())
                            {
                                count_product_create = ui->countCreate_elBL_line->text().toUInt();
                                //Вызываем метод сборки блендера
                                _sklad->collect_ElekBlender(count_product_create, *_work, N_Employees);
                                //Завершение сборки продукта
                                collect_product_finish();
                               // QMessageBox::information(this, "Результат", "Эл. блендер(ы) собран(ы)!");
                            }else{//Если строки для количества продуктов пусты
                                ui->countCreate_elBL_line->setFocus();
                                ui->countCreate_elBL_label->setStyleSheet("color: red");
                            }
                        }else
                            //Если выбрали продукт для сборки(Мясорубки)
                            if(ui->toCollectElMyasoR_check->isChecked())
                            {
                                //Если строки для количества продуктов НЕ пусты
                                if(!ui->elMyasoR_line->text().isEmpty())
                                {
                                    count_product_create = ui->elMyasoR_line->text().toUInt();
                                    /*Вызываем метод для сборки Мясорубки*/
                                    _sklad->collect_ElekMyasoR(count_product_create, *_work, N_Employees);
                                    //Завершение сборки продукта
                                    collect_product_finish();
                                }else{//Если строки для количества продуктов пусты
                                    ui->elMyasoR_line->setFocus();
                                    ui->elMyas_label->setStyleSheet("color: red");
                                }
                            }
}

//Кнопка назад, Вернутьс к выбору одного из продуктов которые хотим собрать
void Second_Window::on_BackChoiceCreate_Btn_clicked()
{
    ui->elCof_label->setStyleSheet("color: black");
    ui->countCreate_elBL_label->setStyleSheet("color: black");
    ui->elMyas_label->setStyleSheet("color: black");
    //Скрываем кнопки
    ui->BackChoiceCreate_Btn->hide();
    ui->CollectProduct_Btn->hide();
    //Скрываем окна сборки Кофемолки, Мясорубки, Блендера
    ui->elKof->hide();
    ui->elMyasoR->hide();
    ui->collectProduct->hide();
    //Показываем окно выбора сборки
    ui->choiceCreate->show();
    //отчищаем строки кол-ва продуктов котрые хотим собрать
    ui->countCreate_elBL_line->clear();
    ui->elMyasoR_line->clear();
    ui->elKof_line->clear();
    //Убираем галочки с выбора сборки
    ui->toCollectElCoffee_check->setChecked(false);
    ui->toCollectElMyasoR_check->setChecked(false);
    ui->toCollectElBlender_check->setChecked(false);
}

//Узнаем сколько сотрудников собирают один продукт
void Second_Window::on_informationCountWorker_Create_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        QString str = "Один продукт собирают " + QString::number(N_Employees) + " сотрудника";
        QMessageBox::information(this, "Количество сотрудников собирающиих продукт", str);
        ui->informationCountWorker_Create->setChecked(false);
    }
}

//выбор способа Удаление сотрудников
void Second_Window::Delete()
{
    show();
    /*скрыть окно выбора, создать продукт или установить кол-во сотрудников собирающих бытовую технику и окно выбора сборки */
    ui->CreateProduct->hide();
    //Показываем окно выбора поиска сотрудника для удаления
    ui->Choce_Find_delete->show();
    exec();
}

//Поиск и удаление по ФИО
void Second_Window::Delete_Worker()
{
    ui->Find_SNP_delete->show();
}

//Кнопка выбора поиска для удаления сотрудника по ФИО
void Second_Window::on_to_SNP_delete_Btn_clicked()
{
    //скрываем окно выбора поиска для удаления сотрудника
    ui->Choce_Find_delete->hide();
    //Вызываем метод поиска и удаления по ФИО
    emit Delete_Worker();
}

//Поиск и удаление сотрудника по номеру телефона
void Second_Window::Delete_Worker_Phone()
{
    ui->find_worker_phone_delete->show();
}

//Кнопка выбора поиска для удаления сотрудника по номеру телефона
void Second_Window::on_to_Phone_delete_Btn_clicked()
{
    //скрываем окно выбора поиска для удаления сотрудника
    ui->Choce_Find_delete->hide();
    //Вызываем метод для поиска и удаления сотрудника по номеру телефона
    emit Delete_Worker_Phone();
}

//Кнопка Врнуться обратно в меню
void Second_Window::on_back_toMenu_clicked()
{
    //скрываем окно выбора поиска для удаления сотрудника
    ui->Choce_Find_delete->hide();
    //Закрываем окно
    close();
}

//Кнопка запуска процесса поиска сотрудника по ФИО
void Second_Window::on_FindWorker_delete_Btn_clicked()
{
    //Если строки ФИО НЕ пусты
    if(!ui->FindLastName->text().isEmpty() && !ui->FindName->text().isEmpty() && !ui->FindPatronymic->text().isEmpty())
    {
        //присваиваем строки ФИО
        find_surname = ui->FindLastName->text();
        find_name = ui->FindName->text();
        find_patronymic = ui->FindPatronymic->text();

        //Скрываем окно
        hide();

        //Вызываем сигнал Удаления сотрудника который вызывает слот Delete_Worker в класске Worker
        emit Delete_findSNP_Signal(find_surname, find_name, find_patronymic);

        //Отчещаем строки
        ui->FindLastName->clear();
        ui->FindName->clear();
        ui->FindPatronymic->clear();

        //Скрываем окно поиска сотрудника по ФИО
        ui->Find_SNP_delete->hide();
        //Закрываем окно
        close();
    }else{//Если строки ФИО пусты
        if(ui->FindLastName->text().isEmpty())
        {
            ui->FindLastName->setFocus();
            ui->Surname_delete_label->setStyleSheet("color: red");
        }
        if(ui->FindName->text().isEmpty())
        {
            ui->FindName->setFocus();
            ui->Name_delete_label->setStyleSheet("color: red");
        }
        if(ui->FindPatronymic->text().isEmpty())
        {
            ui->FindPatronymic->setFocus();
            ui->patronymic_delete_label->setStyleSheet("color: red");
        }


    }
}

//Кнопка Возвращает к выбору поиска сотрудника для удаления
void Second_Window::on_back_Choce_Find_delete_Btn_clicked()
{
    ui->Surname_delete_label->setStyleSheet("color: black");
    ui->Name_delete_label->setStyleSheet("color: black");
    ui->patronymic_delete_label->setStyleSheet("color: black");
    //Отчещаем строки
    ui->FindLastName->clear();
    ui->FindName->clear();
    ui->FindPatronymic->clear();
    //Скрываем окно поиска сотрудника по ФИО
    ui->Find_SNP_delete->hide();
    //Показываем окно выбора поиска сотрудника для удаления
    ui->Choce_Find_delete->show();
}

//Строка поиска по фамилии
void Second_Window::on_FindLastName_textChanged(const QString &arg1)
{
    //Если строка поиска по фамилии не пуста
    if(!arg1.isEmpty())
    {
        ui->Surname_delete_label->setStyleSheet("color: black");
    }
}

//строка поиска по имени
void Second_Window::on_FindName_textChanged(const QString &arg1)
{
    //Если строка поиска по имени не пуста
    if(!arg1.isEmpty())
    {
        ui->Name_delete_label->setStyleSheet("color: black");
    }
}

//Строка поиска по Отчеству
void Second_Window::on_FindPatronymic_textChanged(const QString &arg1)
{
    //Если строка поиска по Отчеству НЕ пуста
    if(!arg1.isEmpty())
    {
        ui->patronymic_delete_label->setStyleSheet("color: black");
    }
}

//Кнопка поиска сотрудника, по номеру телефона, для удаления
void Second_Window::on_FindWorkerPhone_delete_clicked()
{
    //Если строка поиска по номеру телефона НЕ пуста
    if(!ui->find_phone_line->text().isEmpty())
    {
        //Присваиваем номер телефона
        find_phone = ui->find_phone_line->text();

        //Скрываем окно
        hide();

        int k;
        /*Вызываем сигнал поиска сотрудника по номеру телефона который вызывает слот Delete_Worker_PHONE в классе Worker*/
        k = emit Delete_findPhone_Signal(find_phone);

        if(k == 1) //Нажал кнопку назад
        {
            show();
            //Отчищаем строку поиска по номеру телефона
            ui->find_phone_line->clear();
        }else
        {
            //Скрываем окно поиска сотрудника по номеру телефона
            ui->find_worker_phone_delete->hide();
            //Отчищаем строку поиска по номеру телефона
            ui->find_phone_line->clear();
            //Закрываем окно
            close();
        }
    }else{//Если строка поиска по номеру телефона пуста
        ui->find_phone_line->setFocus();
        ui->find_phone_label->setStyleSheet("color: red");
    }
}

//Кнопка Возвращает к выбору поиска сотрудника для удаления
void Second_Window::on_Back_Choce_Find_delete_btn_clicked()
{
    ui->find_phone_label->setStyleSheet("color: black");
    //Отчищаем строку поиска по номеру телефона
    ui->find_phone_line->clear();
    //Скрываем окно поиска по номеру телефона
    ui->find_worker_phone_delete->hide();
    //Показываем окно выбора поиска сотрудника для удаления
    ui->Choce_Find_delete->show();
}

//Строка поиска сотрудника по номеру телефона
void Second_Window::on_find_phone_line_textChanged(const QString &arg1)
{
    //Если строка не пуста
    if(!arg1.isEmpty())
    {
        ui->find_phone_label->setStyleSheet("color: black");
    }
}

//Устанока зарплаты сотрудникам или цены на продукты. Просмотр цен на товары
void Second_Window::zp_Cost(Worker &work, Storage &sklad, Supplier &sup)
{
    show();
    _work = &work;
    _sklad = &sklad;
    _sup = &sup;
    /*скрыть окно выбора создать продукт или установить кол-во сотрудников собирающих бытовую технику и окно выбора сборки */
    ui->CreateProduct->hide();
    //Показываем окно установки зарплаты и цен, а также их просмотр
    ui->Install_zpCost_Box->show();
    exec();
    ui->CreateProduct->show();
}

//Кнопка Вернуться в меню
void Second_Window::on_Back_Btn_clicked()
{
    //Закрыть окно
    close();
    //Отчищаем строки ввод зарплаты сотрудникам, Установка цен на продукты
    ui->zp_line->clear();
    ui->CostProduct_line->clear();
    //Скрываем окно установки зарплаты и цен, а также их просмотр
    ui->Install_zpCost_Box->hide();
    //Убираем галочки с установки цены на продукт
    ui->install_costKof_check->setChecked(false);
    ui->install_costBl_check->setChecked(false);
    ui->install_costMyasR_check->setChecked(false);
    //Убираем галочки с Установки зарплаты сотрудникам и цены на продукты, и просмотр цен
    ui->Print_costProduct_check->setChecked(false);
    ui->install_costProduct_check->setChecked(false);
    ui->install_zpWorker_check->setChecked(false);
}

//Установка зарплаты сотрудникам
void Second_Window::on_install_zpWorker_check_stateChanged(int arg1)
{
    ui->zp_label->setStyleSheet("color: black");
    //Если выбрали установку зарплаты сотрудникам
    if(arg1 == Qt::Checked)
    {
        if(!_work->Get_Work().empty())//Если сотрудник есть
        {
            //Показать окно для установки зарплаты
            ui->install_ZP_Box->show();
        }else{
            QMessageBox::warning(this, "Ошибка!", "Добавьте сотрудника!");
            //Убираем галочку с установки зарплаты сотрудникам
            ui->install_zpWorker_check->setChecked(false);
            //И скрываем это окно
            ui->Install_zpCost_Box->hide();
            //Закрыть окно
            close();
        }
    }else{
        //Скрыть окно для установки зарплаты
        ui->install_ZP_Box->hide();
        //Отчищаем строку установки зарплаты
        ui->zp_line->clear();
    }
}

//Установка цен на продукты
void Second_Window::on_install_costProduct_check_stateChanged(int arg1)
{
    //Если выбрали установку цен на продукты
    if(arg1 == Qt::Checked)
    {
        //Если есть готовый продукт устанавливаем цену
        if(_sklad->Get_collected_ElekCoffee()!=0||_sklad->Get_collected_ElekMyasoR()!=0||_sklad->Get_collected_ElekBlender()!=0)
        {
            //Показываем окно Установки цен на продукты и выбираем на что установить цену
            ui->install_costProduct_Box->show();
            //Скрываем строку ввода цены на продукт и кнопки для установки этих цен
            ui->CostProduct_line->hide();
            ui->costProduct_label->hide();
            ui->CostProduct_btn->hide();
            ui->Baack_install_cost_Btn->hide();
        }else{
            QMessageBox::warning(this, "Ошибка", "Соберите продукт бытовой техники!");
            //Убираем галочку с установки цен на продукты
            ui->install_costProduct_check->setChecked(false);
        }
    }else{//Иначе
        //Скрываем окно Установки цен на продукты
        ui->install_costProduct_Box->hide();
        //Скрываем строку ввода цены на продукт и кнопки для установки этих цен
        ui->CostProduct_line->hide();
        ui->costProduct_label->hide();
        ui->CostProduct_btn->hide();
        ui->Baack_install_cost_Btn->hide();

        //Убираем галочки с установки цены на продукт
        ui->install_costKof_check->setChecked(false);
        ui->install_costBl_check->setChecked(false);
        ui->install_costMyasR_check->setChecked(false);

        //Показать окна выбора на что установить цену
        ui->install_costKof_check->show();
        ui->install_costBl_check->show();
        ui->install_costMyasR_check->show();
        //Показать кнопку перехода к строке для установки цены на продукт
        ui->CostProduct_check_btn->show();
        //Показать Кнопку Отмены установленных галочек
        ui->cancel_Btn->show();
        //Отчищаем строку ввода цен на продукты
        ui->CostProduct_line->clear();
    }
}

//Просмотр стоимости товаров
void Second_Window::on_Print_costProduct_check_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        //Если стоимость деталей установлена
        if(_sup->Get_Cost_KitD_Sup_ElCoffee()!=0||_sup->Get_Cost_KitD_Sup_ElMyasoR()!=0||_sup->Get_Cost_KitD_Sup_ElBlender()!=0)
        {
            //Если стоимость продуктов установлена
            if(_sklad->Get_Cost_ElekCoffee()!=0|| _sklad->Get_Cost_ElekBlender()!=0||_sklad->Get_Cost_ElekMyasoR()!=0)
            {
                //Показываем окно вывода стоимости товаров
                ui->Print_costProduct_Box->show();
                str = "(1) Эл. Кофемолка - " + QString::number(_sup->Get_Cost_KitD_Sup_ElCoffee()) + "\n"
                 +"(2) Эл. Блендер - " + QString::number(_sup->Get_Cost_KitD_Sup_ElBlender()) + "\n"
                + "(3) Эл. Мясорубка - " + QString::number(_sup->Get_Cost_KitD_Sup_ElMyasoR());
                ui->costKit_textBrowser->setText(str);
                str="";

                str = "(1) Эл. Кофемолка - " + QString::number(_sklad->Get_Cost_ElekCoffee()) + "\n"
                     + "(2) Эл. Блендер - " + QString::number(_sklad->Get_Cost_ElekBlender()) + "\n"
                     + "(3) Эл. Мясорубка - " + QString::number(_sklad->Get_Cost_ElekMyasoR());
                //Устанавливаем текст
                ui->costProduct_textBrowser_2->setText(str);
                str="";
            }else{
                QMessageBox::warning(this, "Ошибка", "Цена на готовый продукт не установлена!\n Установите цену!");
                ui->Print_costProduct_check->setChecked(false);
            }
        }else{
            QMessageBox::warning(this, "Ошибка", "Цена на комплекты деталей не установлена!\nУстановите цену!");
            ui->Print_costProduct_check->setChecked(false);
        }
    }else{
        //Скрываем окно вывода стоимости товаров
        ui->Print_costProduct_Box->hide();
    }
}

//Кнопка Выбрать для перехода с выбора на что установить цену, на установку цены
void Second_Window::on_CostProduct_check_btn_clicked()
{
    if(ui->install_costKof_check->isChecked() || ui->install_costBl_check->isChecked() || ui->install_costMyasR_check->isChecked())
    {
        //Показываем строку ввода цены
        ui->CostProduct_line->show();
        ui->costProduct_label->show();
        //Показываем кнопку установки цены на продукт
        ui->CostProduct_btn->show();
        ui->Baack_install_cost_Btn->show();

        //Скрываем CheckBox выбора установки цены на продукт
        ui->install_costKof_check->hide();
        ui->install_costBl_check->hide();
        ui->install_costMyasR_check->hide();
        //Скрываем кнопку перехода к установке цен
        ui->CostProduct_check_btn->hide();
        //Скрываем кнопку отмены поставленных галочек в выборе установки цен
        ui->cancel_Btn->hide();
    }else{
        QMessageBox::warning(this, "Ошибка", "На что вы хотите установить цену?\nСделайте выбор!");
    }
}

//Отмена выбранных галочек(убираем галочки) для установки цен на продукты
void Second_Window::on_cancel_Btn_clicked()
{
    //Скрываем строку ввода цены
    ui->CostProduct_line->hide();
    ui->costProduct_label->hide();
    //Скрываем кнопку установки цены на продукт
    ui->CostProduct_btn->hide();
    ui->Baack_install_cost_Btn->hide();

    //Показываем CheckBox выбора установки цены на продукт
    ui->install_costKof_check->show();
    ui->install_costBl_check->show();
    ui->install_costMyasR_check->show();
    ui->CostProduct_line->clear();
    //Убираем галочки с выбора установки цен на продукт
    ui->install_costBl_check->setChecked(false);
    ui->install_costKof_check->setChecked(false);
    ui->install_costMyasR_check->setChecked(false);
}

//Кнопка Назад к выбору установки цен на продукт
void Second_Window::on_Baack_install_cost_Btn_clicked()
{
    ui->costProduct_label->setStyleSheet("color: black");
    //Скрываем строку ввода цены
    ui->CostProduct_line->hide();
    ui->costProduct_label->hide();
    //Скрываем кнопку установки цены на продукт
    ui->CostProduct_btn->hide();
    //Скрываем кнопку Назад к выбору установки цен на продукт
    ui->Baack_install_cost_Btn->hide();
    //Убираем галочки с выбора установки цен на продукт
    ui->install_costKof_check->setChecked(false);
    ui->install_costBl_check->setChecked(false);
    ui->install_costMyasR_check->setChecked(false);
    //Отчищаем строку ввода цены
    ui->CostProduct_line->clear();

    //Показываем CheckBox выбора установки цены на продукт
    ui->install_costKof_check->show();
    ui->install_costBl_check->show();
    ui->install_costMyasR_check->show();
    //Показываем кнопку перехода к установке цен
    ui->CostProduct_check_btn->show();
    //Показываем кнопку отмены поставленных галочек в выборе установки цен
    ui->cancel_Btn->show();
}

//Строка ввода цены на продукт
void Second_Window::on_CostProduct_line_textChanged(const QString &arg1)
{
    //Если строка ввода цены на продукт не пуста
    if(!arg1.isEmpty())
    {
        ui->costProduct_label->setStyleSheet("color: balck");
    }
}

//Кнопка Установки цен на продукты
void Second_Window::on_CostProduct_btn_clicked()
{
    //Если строка ввода цен на продукты не пуста
    if(!ui->CostProduct_line->text().isEmpty())
    {
        cost = ui->CostProduct_line->text().toUInt();
        //Отчищаем строку ввода цен на продукты
        ui->CostProduct_line->clear();
        //Скрываем окно Установки цен на продукты
        ui->install_costProduct_Box->hide();
        //Если Выбрано установка на три продукта
        if(ui->install_costKof_check->isChecked() && ui->install_costBl_check->isChecked() && ui->install_costMyasR_check->isChecked())
        {
            _sklad->Set_Cost_ElekCoffee(cost);//Вызываем метод Установления цены на продукты
            _sklad->Set_Cost_ElekBlender(cost);
            _sklad->Set_Cost_ElekMyasoR(cost);
        }else
            //Если выбрано установка цен на два продукта
            if(ui->install_costKof_check->isChecked() && ui->install_costBl_check->isChecked())
            {
                _sklad->Set_Cost_ElekCoffee(cost);//Вызываем метод Установления цены на продукты
                _sklad->Set_Cost_ElekBlender(cost);
            }else
                //Если выбрано установка цен на два продукта
                if(ui->install_costBl_check->isChecked() && ui->install_costMyasR_check->isChecked())
                {
                    _sklad->Set_Cost_ElekBlender(cost);
                    _sklad->Set_Cost_ElekMyasoR(cost);
                }else
                    //Если выбрано установка цен на два продукта
                    if(ui->install_costKof_check->isChecked() && ui->install_costMyasR_check->isChecked())
                    {
                        _sklad->Set_Cost_ElekCoffee(cost);//Вызываем метод Установления цены на продукты
                        _sklad->Set_Cost_ElekMyasoR(cost);
                    }else
                        //Если выбрано установка цен продукт
                        if(ui->install_costKof_check->isChecked())
                        {
                            _sklad->Set_Cost_ElekCoffee(cost);//Установить стоимость эл. Кофемолки
                        }else
                            //Если выбрано установка цен продукт
                            if(ui->install_costBl_check->isChecked())
                            {
                                _sklad->Set_Cost_ElekBlender(cost);//Установить стоимость эл. Блендера
                            }else
                                //Если выбрано установка цен продукт
                                if(ui->install_costMyasR_check->isChecked())
                                {
                                    _sklad->Set_Cost_ElekMyasoR(cost);//Установить стоимость эл. Мясорубки
                                }
        //Убираем галочки с checkBox-са Установка цены на продукты и выбора продуктов для установки цены
        ui->install_costProduct_check->setChecked(false);
        ui->install_costBl_check->setChecked(false);
        ui->install_costKof_check->setChecked(false);
        ui->install_costMyasR_check->setChecked(false);
    }else{
        ui->CostProduct_line->setFocus();
        ui->costProduct_label->setStyleSheet("color: red");
    }
}

//Кнопка установки зарплаты сотрудникам
void Second_Window::on_ZP_Btn_clicked()
{
    //Если строка установки зп сотрудникам не пуста
    if(!ui->zp_line->text().isEmpty())
    {
        zp = ui->zp_line->text().toUInt();

        _work->ZP_Work(zp); //Вызываем метод для установления зарплаты

        //скрываем окно установки зарплаты сотрудникам
        ui->install_ZP_Box->hide();
        //Отчищаем строку установки зарплаты сотрудникам
        ui->zp_line->clear();
        /*Убираем галочку с окна выбора установки зарплаты сотрудникам или цен на продукты. Простмотр цен на продукты*/
        ui->install_zpWorker_check->setChecked(false);
    }else{
        ui->zp_line->setFocus();
        ui->zp_label->setStyleSheet("color: red");
    }
}

//Проверка строки установки зарплаты сотрудникам на пустату
void Second_Window::on_zp_line_textChanged(const QString &arg1)
{
    //Если строка не пуста
    if(!arg1.isEmpty())
    {
        ui->zp_label->setStyleSheet("color: black");
    }
}

//проверка строки кол-ва кофемолок, которые надо собрать
void Second_Window::on_elKof_line_textChanged(const QString &arg1)
{
    //Если первый символ не 0
    if(arg1 != "0")
    {
        //Если строка не пуста
        if(!arg1.isEmpty())
        {
            ui->elCof_label->setStyleSheet("color: black");
        }
    }else{//иначе
        //отчищаем строку
        ui->elKof_line->clear();
    }
}

//Проверка строки кол-ва блендеров которые надо собрать
void Second_Window::on_countCreate_elBL_line_textChanged(const QString &arg1)
{
    //Если первый символ не 0
    if(arg1 != "0")
    {
        //Если строка не пуста
        if(!arg1.isEmpty())
        {
            ui->countCreate_elBL_label->setStyleSheet("color: black");
        }
    }else{
        //отчищаем строку
        ui->countCreate_elBL_line->clear();
    }
}

//Проверка строки кол-ва мясорубок, которые надо собрать
void Second_Window::on_elMyasoR_line_textChanged(const QString &arg1)
{
    //Если первый символ не 0
    if(arg1 != "0")
    {
        //Если строка не пуста
        if(!arg1.isEmpty())
        {
            ui->elMyas_label->setStyleSheet("color: black");
        }
    }else{
        //отчищаем строку
        ui->elMyasoR_line->clear();
    }
}

//проверка строки на ввод, кол-ва сотрудников собирающих продукты
void Second_Window::on_introduceCountWorker_line_textChanged(const QString &arg1)
{
    //если строка не пуста
    if(!arg1.isEmpty())
    {
        ui->introduceCountWorker_label->setStyleSheet("color: black");
    }
}
