#include "find_employee.h"
#include "ui_find_employee.h"

Find_employee::Find_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Find_employee)
{
    ui->setupUi(this);

    //Блокируем кнопку закрытия окна
    setWindowFlags(Qt::Window
         | Qt::WindowMinimizeButtonHint
         | Qt::WindowMaximizeButtonHint
         | Qt::CustomizeWindowHint);

    flag =0;
    tmp=0;

    //Устанавливаем ограничение на ввод
    QRegExp phone("[0-9]{1,11}");
    QRegExp str("[a-zA-Zа-яА-я]{1,999}");
    ui->surnameFind_line->setValidator(new QRegExpValidator(str, this));//str
    ui->nameFind_line->setValidator(new QRegExpValidator(str, this));
    ui->patranomicFind_line->setValidator(new QRegExpValidator(str, this));
    ui->phoneFind_line->setValidator(new QRegExpValidator(phone, this));//num

    print_find_worker = new Print_Workers;

    this->layout()->setSizeConstraint(QLayout::SetFixedSize);  //Это то, что заставляет форму автоматически изменять размер  автоматическое изменение размера на виджете hide/show.

    //При срабатывании сигнала вызывается слот DataWorkers_slot
    connect(this, &Find_employee::DataWorkers_slot_Signal, print_find_worker, &Print_Workers::DataWorkers_slot);
}

Find_employee::~Find_employee()
{
    delete ui;
}

//Поиск сотрудника
void Find_employee::Find_Worker(QVector<QString> &_Name, QVector<QString> &_Surname, QVector<QString> &_Patronymic, QVector<QString> _Phone)
{
    Name = _Name;
    Surname = _Surname;
    Patronymic = _Patronymic;
    Phone = _Phone;
    show();
    ui->choiceFind->show(); //Показываем окно "Выбор поиска"
    ui->find_to_SNP->hide(); //Срываем окно поиска сотрудника по ФИО
    ui->find_to_phine->hide(); //Скрываем окно поиска сотрудника по номеру телефона
    exec();
}

//Выбор способа поиска
void Find_employee::on_OkFind_Btn_clicked()
{
    //Срываем окно "Выбор поиска"
    ui->choiceFind->hide();
    //Если выбрали сразу два поиска по ФИО и номеру телефона выводить предупреждение
    if(ui->findSNP_check->isChecked() && ui->findPhone_check->isChecked())
    {
        hide();
        QMessageBox::warning(this, "Ошибка", "Выберите что то одно!");
        show();
        ui->choiceFind->show();
    }else
        //Если выбрали только поиск по ФИО
        if(ui->findSNP_check->isChecked())
        {
            //Показать окно поиска сотрудника по ФИО
            ui->find_to_SNP->show();
        }else
            //Если выбрали поиск по номеру телефона
            if(ui->findPhone_check->isChecked())
            {
                //Показать окно поиска сотрудника по номеру телефона
                ui->find_to_phine->show();
            }else{//иначе если не был сделан выбор выводить предупреждение
                hide();
                QMessageBox::warning(this, "Ошибка", "Вы не сделали выбор поиска!");
                show();
                ui->choiceFind->show();
            }

    //Убераем галочки с CheckBox-са
    ui->findSNP_check->setChecked(false);
    ui->findPhone_check->setChecked(false);
}

//Поиск сотрудника по ФИО
void Find_employee::on_OkFindSNP_Btn_clicked()
{
    //Если строки поиска ФИО НЕ пусты
    if(!ui->surnameFind_line->text().isEmpty() && !ui->nameFind_line->text().isEmpty() && !ui->patranomicFind_line->text().isEmpty())
    {
        flag =0;
        tmp=0;
        //Проходимся по списку сотрудников
         for(int i = 0; i < Surname.size(); i++)
         {
             //Если совпадения есть
             if(ui->surnameFind_line->text() == Surname[i] && ui->nameFind_line->text() == Name[i] && ui->patranomicFind_line->text() == Patronymic[i])//Если номер совпал
             {
                 flag++;//для отслеживания повторов
                 tmp = i; //запоминаем позицию ячейки
             }
         }

         //если флаг равен 1(найден один такой сотрудник)
         if(flag == 1)
         {
             //Записываем данные сотрудника в res
             res = Surname[tmp] + "\t" + Name[tmp] + "\t" + Patronymic[tmp] + "\t" + Phone[tmp] + "\n";

             //Скрываем окно поиска сотруника по ФИО
             ui->find_to_SNP->hide();
             close();//закрываем окно
             //Вызываем слот(метод) DataWorkers_slot чтобы вывести всех сотрудников
             emit print_find_worker->DataWorkers_slot(res);
         }else
             if(flag > 1) // Если флаг >1, сотрудников с таким ФИО найдено больше одного
             {
                 //проходимся по всем сотрудникам
                 for(int i = 0; i < Phone.size(); i++)
                 {
                     //Если ФИО совпало записываем в res
                     if(ui->surnameFind_line->text() == Surname[i] && ui->nameFind_line->text() == Name[i] && ui->patranomicFind_line->text() == Patronymic[i])//Если номер совпал
                     {
                         res += Surname[i] + "\t" + Name[i] + "\t" + Patronymic[i] + "\t" + Phone[i] + "\n";
                     }
                 }
                 //Скрываем окно поиска сотруника по ФИО
                 ui->find_to_SNP->hide();
                 close();//закрываем окно
                 //Вызываем сигнал вывода найденного сотрудника
                 emit DataWorkers_slot_Signal(res);
             }else
                 if(flag == 0)//Если 0
                 {
                     hide();
                     QMessageBox::warning(this, "Результат", "Такого сотрудника нет!");
                 }

         res="";//отчищаем строки
         ui->surnameFind_line->clear();
         ui->nameFind_line->clear();
         ui->patranomicFind_line->clear();
         close();//закрываем окно
    }else{
        if(ui->surnameFind_line->text().isEmpty())//Если строка пуста
        {
            ui->surnameFind_line->setFocus();             //устанавливаем курсор
            ui->surname_label->setStyleSheet("color: red");//красим в красный
        }
        if(ui->nameFind_line->text().isEmpty())//Если строка пуста
        {
            ui->nameFind_line->setFocus();
            ui->name_label->setStyleSheet("color: red");
        }
        if(ui->patranomicFind_line->text().isEmpty())//Если строка пуста
        {
            ui->patranomicFind_line->setFocus();
            ui->patrinymic_label->setStyleSheet("color: red");
        }
    }
}

//Поиск сотрудника по номеру телефона
void Find_employee::on_OkFindPhone_Btn_clicked()
{
    if(!ui->phoneFind_line->text().isEmpty())
    {
        flag =0;
        tmp=0;
        //Проходимся по всем сотрудникам
        for(int i = 0; i < Phone.size(); i++)
        {

            if(ui->phoneFind_line->text() == Phone[i])//Если номер совпал
            {
                flag++;//для отслеживания повторов
                tmp = i; //запоминаем позицию ячейки
            }
        }

        close();
        //Если номер совпал
        if(flag == 1)
        {
            res = Surname[tmp] + "\t" + Name[tmp] + "\t" + Patronymic[tmp] + "\t" + Phone[tmp] + "\n";

            ui->find_to_phine->hide();


            emit DataWorkers_slot_Signal(res);
        }else
            if(flag > 1)
            {
                //проходимся по всем сотрудникам
                for(int i = 0; i < Phone.size(); i++)
                {
                    if(ui->phoneFind_line->text() == Phone[i])//Если номер совпал
                    {
                        res += Surname[i] + "\t" + Name[i] + "\t" + Patronymic[i] + "\t" + Phone[i] + "\n";
                    }
                }

                emit DataWorkers_slot_Signal(res);
            }else
                if(flag == 0)//Если прошлись по всем сотрудникам и номер не совпал
                {
                    hide();
                    QMessageBox::warning(this, "Результат", "Такого сотрудника нет!");
                }
        res = "";

        ui->phoneFind_line->clear();
    }else{
        ui->phoneFind_line->setFocus();
        ui->phoneFind_label->setStyleSheet("color: red");
    }
}

//кнопка закрытия окна поиска по выбору
void Find_employee::on_pushButton_clicked()
{
    //Убираем галочки с CheckBox
    ui->findPhone_check->setChecked(false);
    ui->findSNP_check->setChecked(false);
    close();//Закрываем окно
}

//Кнопка назад к выбору поиска
void Find_employee::on_backFindSNP_Btn_clicked()
{
    ui->surname_label->setStyleSheet("color: black");
    ui->name_label->setStyleSheet("color: black");
    ui->patrinymic_label->setStyleSheet("color: black");
    //Скрываем окно Поиск сотрудника по ФИО
    ui->find_to_SNP->hide();
    //Отчищаем строки ФИО
    ui->surnameFind_line->clear();
    ui->nameFind_line->clear();
    ui->patranomicFind_line->clear();
    ui->choiceFind->show();
}


//строка поиска фамилии не пуста
void Find_employee::on_surnameFind_line_textChanged(const QString &arg1)
{
    //Если строка поиска фамилии не пуста
    if(!arg1.isEmpty())
    {
        ui->surname_label->setStyleSheet("color: black");
    }
}
//строка поиска имени не пуста
void Find_employee::on_nameFind_line_textChanged(const QString &arg1)
{
    //Если строка поиска имени не пуста
    if(!arg1.isEmpty())
    {
        ui->name_label->setStyleSheet("color: black");
    }
}
//строка поиска отчества не пуста
void Find_employee::on_patranomicFind_line_textChanged(const QString &arg1)
{
    //Если строка поиска фамилии пуста
    if(!arg1.isEmpty())
    {
        ui->patrinymic_label->setStyleSheet("color: black");
    }
}
//строка поиска номера телефона не пуста
void Find_employee::on_phoneFind_line_textChanged(const QString &arg1)
{
    //Если строка не начинается с нуля
    if(arg1 != "0")
    {
        //Если строка поиска сотрудника по номеру телефона не пуста
        if(!arg1.isEmpty())
        {
            ui->phoneFind_label->setStyleSheet("color: black");
        }
    }else{//Если начилась с нуля отчищаем
        ui->phoneFind_line->clear();
    }
}

void Find_employee::on_Back_find_to_phine_clicked()
{
    ui->phoneFind_label->setStyleSheet("color: black");
    ui->find_to_phine->hide();
    ui->phoneFind_line->clear();
    ui->choiceFind->show();
}
