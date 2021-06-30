#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Menu->show();

    sup = new Supplier(this);
    work = new Worker(this);
    sklad = new Storage(this);
    save = new Save_Data(this);
    second_window = new Second_Window(this);

    //Сочетание горячих клавиш(выход)
    ui->actionQuit->setShortcut(tr("CTRL+Q"));

    QRegExp exp("[0-9]{0,2}");//Позволяет вводить цифры от 0 до 9, до двузначных
    ui->state_menu->setValidator(new QRegExpValidator(exp, this));

    //Сигналы и слоты
    connect(this, &MainWindow::WorkerSignal, work, &Worker::WorkerSlot);
    connect(sklad, &Storage::clicked_changeS_Signal, this, &MainWindow::toChange_supplierSlot);
    connect(this, &MainWindow::ChangeSupp_Signal, sklad, &Storage::ChangeSup_Slot);
    connect(this, &MainWindow::ChoiceSignal, work, &Worker::ChoiceSlot);
    connect(this, &MainWindow::SupplierSignal, sup, &Supplier::supplierEnter);
    connect(this, &MainWindow::SkladSignal, sklad, &Storage::Sklad);
    connect(this, &MainWindow::Find_SureNameOches_Signal, work, &Worker::Find_SureNameOches);
    connect(this, &MainWindow::condition_sklad_Signal, sklad, &Storage::condition_sklad);
    connect(second_window, &Second_Window::Delete_findSNP_Signal, work, &Worker::Delete_Worker);
    connect(second_window, &Second_Window::Delete_findPhone_Signal, work, &Worker::Delete_Worker_PHONE);
    connect(this, &MainWindow::Install_costKit_Signal, sklad, &Storage::ChangeSupCostKit);
    connect(this, &MainWindow::Sell, sklad, &Storage::sell_product);
    connect(this, &MainWindow::Save_toFile, save, &Save_Data::SaveData);
    connect(this, &MainWindow::supplierDataChange_Signal, sklad, &Storage::sklad_supplierDataChange);
    connect(this, &MainWindow::second_window_Signal, second_window, &Second_Window::create_Product);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Меню
void MainWindow::on_option_clicked()
{
    //Если мы сделали выбор
    if(!ui->state_menu->text().isEmpty())
    {
        QString str = ui->state_menu->text();//Присваиваем цифру которую ввели в меню
        ui->state_menu->clear();   //отчищаем QLineEdit
        int num = str.toInt();
        //hide();
        if(num > 11 || num < 0){ //Если наш выбор больше 11 или меньше 0 выводить ошибку
            QMessageBox::critical(this, "Ошибка", "Такого выбора нет!");
        } else {                 //иначе
                switch (num) {//ищем соответствующую цифру
                case 1:
                    if(sup->Get_Supplier().empty() && sklad->num!=1)//Если Поставщика нет
                    {
                        sup->setModal(true);
                        emit SupplierSignal();   //Сигнал, ввод поставщика т цены на комплект детвлей
                    }else{
                        QMessageBox::information(this, "Начальное", "Вы уже ввели поставщика!");
                    }
                    if(work->Get_Work_Ochestvo().empty()) //Если работников нет
                    {
                        work->setModal(true);
                        emit WorkerSignal();       //Сигнал добавления сотрудников
                    }else{
                        QMessageBox::information(this, "Начальное", "Вы уже ввели начальное количество сотрудников!");
                    }
                break;
                case 2:
                    work->setModal(true);
                    emit ChoiceSignal();  //Сигнал Добавления сотрудников
                    break;
                case 3:
                    if(sup->Get_Supplier().empty() && sklad->num!=1){//Если постащика нет выводить предупреждение
                        QMessageBox::warning(this, "Поставщик", "Добавьте поствщика!");
                    } else {
                        sklad->setModal(true);
                        emit SkladSignal(*sup);  //Вызываем Сигнал склада, параметром передаем обьект sup класса Supplier
                    }
                    break;
                case 4:
                    work->setModal(true);
                    work->Print();         //Вызываем метод вывода всех сотрудников
                    break;
                case 5:
                    if(work->Get_Work().empty()) //Если сотрудников нет
                    {
                        QMessageBox::warning(this, "Ошибка!", "Нет сотрудников!\nДабавьте сотрудника!");
                    }else{                      //иначе если есть
                        work->setModal(true);
                        emit Find_SureNameOches_Signal();    //Вызываем сигнал поиска сотрудника
                    }
                    break;
                case 6:
                    if(sup->Get_Supplier().empty())  //Если поставщика нет
                    {
                        QMessageBox::warning(this, "Ошибка!", "Нет поставщика!\nДабавьте поставщика!");
                    }else{                            //Если есть
                        sklad->setModal(true);
                        //Вызываем сигнал просмотр состояния склада
                        emit condition_sklad_Signal();
                    }
                    break;
                case 7:
                    //Если сотрудников нет выводить предупреждение
                    if(work->Get_Work().empty())
                    {
                       QMessageBox::warning(this, "Ошибка!", "Нет сотрудников!\nДабавьте сотрудника!");
                    }else{//Если есть
                        second_window->setModal(true);
                        //Вызываем сигнал собрать продукт
                        emit second_window_Signal(*work, *sklad);
                    }
                    break;
                case 8:
                    //Если сотрудников нет выводить предупреждение
                    if(work->Get_Work().empty())
                    {
                        QMessageBox::warning(this, "Ошибка!", "Нет сотрудников!\nДабавьте сотрудника!");
                    }else{//Если есть
                        second_window->setModal(true);
                        //Вызывваем метод удаления сотрудника
                        emit second_window->Delete();
                    }
                    break;
                case 9:
                    second_window->setModal(true);
                    //Вызываем метод определение зарплаты сотрудникам или цены на продукты. Просмотр цен на товары
                    second_window->zp_Cost(*work, *sklad, *sup);
                    break;
                case 10:
                    //Если Есть собранные продукты
                    if(sklad->Get_collected_ElekCoffee()!=0||sklad->Get_collected_ElekMyasoR()!=0||sklad->Get_collected_ElekBlender()!=0)
                    {
                        //Если есть установленные цены на проукт
                        if(sklad->Get_Cost_ElekCoffee()!=0 || sklad->Get_Cost_ElekMyasoR()!=0 || sklad->Get_Cost_ElekBlender()!=0){
                            sklad->setModal(true);
                            //Вызываем сигнал продажы продуктов
                            emit Sell();
                        }
                        else
                            QMessageBox::warning(this, "Ошибка", "Установите цены на собранные продукты!");
                    }else
                        QMessageBox::warning(this, "Ошибка", "У вас нет собранных продуктов!\n"
                                                             "Соберите продукт!");
                    break;
                case 11:
                    //Если есть сотрудники или поставщик
                    if(!work->Get_Work().empty() || !sup->Get_Supplier().empty())
                    {
                        save->setModal(true);
                        //Вызываем сигнал сохранения продукта
                        Save_toFile(*work, *sup, *sklad);
                    }else
                        QMessageBox::warning(this, "Ошибка", "Нeчиго сохранить!");
                    break;
                case 0:
                    close(); //Закрываем проект
                    break;
                }
        }
    }else{ //Если не сделали выбор
        ui->state_menu->setFocus();//Устанавливаем курсор
        ui->state_menu_label->setStyleSheet("color: red");//Красим в кранный
    }
}

//Опции выбор действия
void MainWindow::toChange_supplierSlot()
{
    if(sklad->num == 0) //Если в опции постащик мы выбрали 0
    {
        emit sklad->Print(*sup); //Выводим данные поставщика
    }else
        if(sklad->num == 1) //Если выбрали 1
        {
            emit ChangeSupp_Signal(*sup); //Вызываем сигнал смены поставщика который вызывает слот ChangeSup_Slot
        }else
            if(sklad->num == 2)//Если выбралли 2
            {
                 supplierDataChange_Signal(*sup);/*Вызываем сигнал смены некоторых данных поставщика котрый вызывает слот sklad_supplierDataChange*/
            }else
                if(sklad->num == 3)//Если выбрали 3
                {
                        emit sklad->kit_Detail(*sup); // Вызываем метод заказа деталей
                }else
                    if(sklad->num == 4)
                    {
                        Install_costKit_Signal(*sup); //Вызываем сигнал Установки цен на детали который вызывает слот ChangeSupCostKit
                    }else{
                        QMessageBox::warning(this,"Ошибка","Такого выбра нет!");
                    }
}


//Проверка на ввод выбора в меню
void MainWindow::on_state_menu_textChanged(const QString &arg1)
{
    //Если строка выбора в меню пуста
    if(!arg1.isEmpty())
    {
        ui->state_menu_label->setStyleSheet("color: black");
    }
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

