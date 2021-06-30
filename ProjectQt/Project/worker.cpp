#include "worker.h"
#include "ui_worker.h"
#include <QDebug>
#include <QTableWidget>

Worker::Worker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Worker)
{
    _zp=0; //Зарплата сотрудников
    i = 0;
    tmp = 0;//для смещения ячейки для удаления
    //Нажата кнопка ок
    del = false; //для определения какая кнопка нажата в окне выбора как удалить сотрудника

    click_Choice_DeleteWorker = false;
    ui->setupUi(this);

    //Блокируем кнопку закрытия окна
    setWindowFlags(Qt::Window
         | Qt::WindowMinimizeButtonHint
         | Qt::WindowMaximizeButtonHint
         | Qt::CustomizeWindowHint);

    //Скрываем Окна
    ui->Choice_DeleteWorker->hide();
    ui->countWorker_2->hide();
    ui->new_Worker->hide();
    ui->Choice->hide();
    ui->deleteChoice_Box->hide();

    ui->saveWorker->setDisabled(true);
    ui->countWorker->setDisabled(true);

   this->layout()->setSizeConstraint(QLayout::SetFixedSize);  /*Это то, что заставляет форму автоматически изменять размер  автоматическое изменение размера на виджете hide/show.*/

    //Устанавливаем ограничение на ввод
    QRegExp count("[0-9]{1,999}");
    QRegExp phone("[0-9]{11}");
    QRegExp str("[а-яА-Яa-zA-Z]{1,20}");

    //Устанавливаем, ограничения на строки
    ui->worker->setValidator(new QRegExpValidator(count, this));
    ui->deleteWorker_line->setValidator(new QRegExpValidator(count, this));

    ui->phone->setValidator(new QRegExpValidator(phone, this));

    ui->surname->setValidator(new QRegExpValidator(str, this));
    ui->name->setValidator(new QRegExpValidator(str, this));
    ui->patronymic->setValidator(new QRegExpValidator(str, this));


    ui->tableWidget->setColumnCount(4);//Столбцы

    printWorkers = new Print_Workers(this);
    find_worker = new Find_employee(this);

    //Сигналы и слоты
    connect(this, &Worker::find_emloyee_Signal, find_worker, &Find_employee::Find_Worker);
}

Worker::~Worker()
{
    delete ui;
}

CChoicePathDelegate::CChoicePathDelegate (QObject *parent)
    :QItemDelegate(parent) {}
Str::Str (QObject *parent)
    :QItemDelegate(parent) {}

//создать редактор ячеек (QLineEdit), установить нужное регулярное выражение ввода:
QWidget *CChoicePathDelegate::createEditor(QWidget *parent,
                                           const QStyleOptionViewItem& /*&option*/, const QModelIndex& /*&index*/) const
{
    QLineEdit *editor = new QLineEdit(parent);
    editor->setValidator(new QRegExpValidator(QRegExp("[0-9]{11}")));
    return editor;
}

QWidget *Str::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const
{
    QLineEdit *editor = new QLineEdit(parent);
    editor->setValidator(new QRegExpValidator(QRegExp("[a-zA-Zа-яА-Я]{1,20}")));
    return editor;
}

//Окно кол-во сотрудников
//Устанавливаем кол-во сотрудников
void Worker::on_countWorker_clicked()
{
    QString str = ui->worker->text();
    int n = str.toInt();

    //Если кол-во сотрудников введено
    if(!ui->worker->text().isEmpty())
    {
        //Убираем блокировку кнопки
        ui->saveWorker->setDisabled(false);
        ui->new_Worker->hide();
        //Устанавливаем кол-во сотрудников
        ui->tableWidget->setRowCount(n);//строка

        //помогает ввести 11 цифр в раздел номер телефона в столбце
        CChoicePathDelegate *delegate = new CChoicePathDelegate(this);
        //Устанавливаем ограничение по вводу в раздел номер телефона
        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            ui->tableWidget->setItemDelegateForColumn(ui->tableWidget->columnCount()-1, delegate); //вот собственно установка делегата
        }

        //Устанавливает ограничение на ввод
        Str *str = new Str(this);
        //Устанавливаем это ограничение на ввод ФИО
        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            ui->tableWidget->setItemDelegateForColumn(ui->tableWidget->columnCount()-2, str); //вот собственно установка делегата
            ui->tableWidget->setItemDelegateForColumn(ui->tableWidget->columnCount()-3, str);
            ui->tableWidget->setItemDelegateForColumn(ui->tableWidget->columnCount()-4, str);
        }

        //Отчищаем строку кол-ва сотрудников
        ui->worker->clear();
        ui->countWorker_2->setFixedSize(450+20, 200+n*20);//задает размер окна добавления сотрудника
    }
}

//Добавление нового сотрудника
void Worker::addWorkSlot()
{
    show();
    ui->countWorker_2->hide();
    ui->new_Worker->show();
    exec();
}

//Окно Количество сотрудников
//Задаем кол-во добавляемых сотрудников
void Worker::WorkerSlot()
{
    show();
    //Показать окно Количество сотрудников
    ui->countWorker_2->show();
    //Задаем размер окна
    ui->countWorker_2->setFixedSize(450, 200);
    //Скрываем окно добавления нового окна
    ui->new_Worker->hide();
    //Скрыть выбор добавления сотрудника
    ui->Choice->hide();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Фамилия" << "Имя" << "Отчество" << "Сотовый");//задаем столбцам имена
    exec();
}

//ОКно Новый сотрудник
//Кнопка Устанавливает нового сотрудника
void Worker::on_newWork_btn_clicked()
{
    //Если Данные нового сотрудника ФИО и номер телефона введены
    if(!ui->surname->text().isEmpty() && !ui->name->text().isEmpty() && !ui->patronymic->text().isEmpty() && !ui->phone->text().isEmpty())
    {
        //Добавление сотрудника
        QString str = ui->surname->text();
        _Surname.push_back(str);

        str = ui->name->text();
        _Name.push_back(str);

        str = ui->patronymic->text();
        _Patronymic.push_back(str);

        str = ui->phone->text();
        _Phone.push_back(str);

        //Отчищаем стоки
        ui->surname->clear();
        ui->name->clear();
        ui->patronymic->clear();
        ui->phone->clear();
        //Скрываем окно Добавления нового сотрудника
        ui->new_Worker->hide();
        //Закрыть окно
        close();
    }else{//Если стоки пусты
        if(ui->surname->text().isEmpty())
        {
            ui->surname->setFocus();
            ui->surname_label->setStyleSheet("color: red");

        }
        if(ui->name->text().isEmpty())
        {

            ui->name->setFocus();
                ui->name_label->setStyleSheet("color: red");
        }
        if(ui->patronymic->text().isEmpty())
        {
            ui->patronymic->setFocus();
            ui->patronymic_label->setStyleSheet("color: red");

        }
        if(ui->phone->text().isEmpty())
        {
            ui->phone->setFocus();
            ui->phone_label->setStyleSheet("color: red");
        }
    }
}

//Окно Количество добавляеых сотрудников
//Кнопка записи сотрудников в базу
void Worker::on_saveWorker_clicked()
{
    QVector<QString> str;

    //Для определения все ли ячейки в столбце заполнены
    bool flag = true;

    //Проходимся по списку
    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        for(int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            //Если какой то элемент ячейки пуст
            if (ui->tableWidget->item(i,j) == 0)
            {
                flag = false;
                break;
            }
        }
    }

    //Если все элементы таблицы заполнины
    if(flag == true)
    {
        //Запись сотрудников во временную переменную
        for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            for(int j = 0; j < ui->tableWidget->columnCount(); j++)
            {
                str.push_back(ui->tableWidget->item(i, j)->text());
            }
        }
        int n=0;//помогает записать нужную строку

        //Запись сотрудников в базу
        for(int j = 0; j < ui->tableWidget->rowCount(); j++)
        {
            _Surname.push_back(str[n]);
            _Name.push_back(str[n+1]);
            _Patronymic.push_back(str[n+2]);
            _Phone.push_back(str[n+3]);
            n += 4;
        }

        //Отчищаем таблицу
        ui->tableWidget->clear();
        //Скрываем окно добавления сотрудников
        ui->countWorker_2->hide();
        //Блокируем кнопку записи сотрудников
        ui->saveWorker->setDisabled(true);
        //Закрываем окно
        close();
    }else
        QMessageBox::warning(this, "Ошибка", "Заполните все ячейки");
}

// добавление сотрудника
void Worker::ChoiceSlot()
{
    show();
    //Окно выбоа как добавлять сотрудника
    ui->Choice->show();
    //Скрываем окно где нужно задавать кол-во добавляемых сотрудников
    ui->countWorker_2->hide();
    //Скрываем окно добавления нового сотрудника
    ui->new_Worker->hide();
    exec();
}

//Окно Выбора каким способ добавлять сотрудников
//Кнопка помогающая выбрать способ добавления сотрудника
void Worker::on_OK_clicked()
{
    //Скрываем окно выбора добавления сотрудника
    ui->Choice->hide();
    //Если выбрали два способа добавления сотрудиков
    if(ui->OneWorker->isChecked() && ui->Workers->isChecked())
    {
        hide();
        QMessageBox::warning(this, "Ошибка", "Выберите что то одно!");
        show();
        ui->Choice->show();
    }else//Если выбрали добавления одного сотрудника
        if(ui->OneWorker->isChecked())
        {
            emit addWorkSlot();
        }else//Если выбрали способ где нужно задавать кол-во добавляемых сотрудников
            if(ui->Workers->isChecked())
            {
                emit WorkerSlot();
            }else{
                hide();
                QMessageBox::warning(this, "Сотрудники", "Сколько вы хотите добавить сотрудников?");
                show();
                ui->Choice->show();
            }
    //Убираем галочки с выбора,каким способ добавить сотрудника
    ui->OneWorker->setChecked(false);
    ui->Workers->setChecked(false);
}

//Окно удаления сотрудника
//Кнопка переходит по выбронному checkBox-су удаления
void Worker::on_delete_phone_Btn_clicked()
{
    //проверка нажатия кнопки
    click_Choice_DeleteWorker = true;
    //Если два способа удаления сотрудников
    if(ui->All_deleteWorker_check->isChecked() && ui->delete_WorkerChoice_check->isChecked())
    {
        QMessageBox::warning(this, "Ошибка!", "Выберите что то одно!");
    }else//Если выбрали удаление всех сотрудников с одинаковыми номерами
        if(ui->All_deleteWorker_check->isChecked())
        {
                //проходимся по всем сотрудникам
                for(i = 0; i < _Phone.size(); i++)
                {
                    if(delete_phone == _Phone[i])//Если номер совпал
                    {
                        _Surname.remove(i);//Удаляем
                        _Name.remove(i);
                        _Patronymic.remove(i);
                        _Phone.remove(i);
                    }
                }
                close();//закрываем окно
                ui->Choice_DeleteWorker->hide();
                QMessageBox::information(this, "Результат", "Уволен!");
        }else//Если выбрали удаление сотрудника по выбору
            if(ui->delete_WorkerChoice_check->isChecked())
            {
                //Показываем окно выбора, кого удалить
                ui->deleteChoice_Box->show();
                //Скрываем око выбора способа удаления
                ui->Choice_DeleteWorker->hide();
                str = "ФИО:\n";
                //Проходимся по всем сотрудникам
                for(i = 0; i < _Phone.size(); i++)
                {
                    //Если номер совпал
                    if(delete_phone == _Phone[i])
                    {
                        str += "("+QString::number(i)+") " + _Surname[i] + "\t"
                             + _Name[i] + "\t"
                             + _Patronymic[i] + "\t" + _Phone[i] +"\n";
                    }
                }

                //Устанавливаем текст
                ui->Worker_textBrowser->setText(str);
                str="";
         }
    //Убираем галочки с выбора способа удаления сотрудников
    ui->All_deleteWorker_check->setChecked(false);
    ui->delete_WorkerChoice_check->setChecked(false);
}

//Окно уволить сотрудника
//Кнопка удаления выбранного сотрудника
void Worker::on_ChoiceDelete_Btn_clicked()
{
    //Если выбор не сделан
    if(!ui->deleteWorker_line->text().isEmpty())
    {
        int k = ui->deleteWorker_line->text().toUInt();

        //Если номер выбран неверно
        if(_Phone.size() < k )
        {
            QMessageBox::warning(this, "Ошибка!", "Такого сотрудника нет!");
            ui->deleteWorker_line->clear();
        }else{

            //Если номер совпал
            if(delete_phone == _Phone[k])
            {
                //Удаляем сотрудника
                _Surname.remove(k);
                _Name.remove(k);
                _Patronymic.remove(k);
                _Phone.remove(k);
                QMessageBox::information(this, "Результат", "Уволен!");
                ui->deleteChoice_Box->hide();
                close();
            }else{
                QMessageBox::warning(this, "Ошибка", "Такого выбора нет!");
            }

            //Отчищаем строку выбора сотрудника для удаления
            ui->deleteWorker_line->clear();
        }
    }else{
        ui->deleteWorker_line->setFocus();
        ui->deleteWorkerChoice_label->setStyleSheet("color: red");
    }
}

//метод вывода всех сотрудников
void Worker::Print()
{
    //Если сотрудников нет
    if(_Surname.empty())
    {
        QMessageBox::warning(this, "Нет сотрудников!", "Дабавьте сотрудника");
    }else
        if(_zp == 0)//Если зарплата сотрудников не установлена
        {
            QMessageBox::warning(this, "Зарплаты", "Чтобы просмотреть список сотрудников установите им зарплаты!");
        }else
            {
                for(int i = 0; i < _Surname.size(); i++)//Вывод данных о сотрудниках
                {

                    str += QString::number(i)+")"+"Фамилия: " + _Surname[i] + "\t"
                    + "Имя: " + _Name[i] + "\t"
                    + "Отчество: " + _Patronymic[i] + "\t"
                    + "Номер телефона: " + _Phone[i] + "\t"
                    + "Зарплата: " + QString::number(_zp) + "\n";
                }
                //Вызываем метод установки данных списка сотрудников
                emit printWorkers->DataWorkers_slot(str);
                str = "";
            }
}

//поиск сотрудника
void Worker::Find_SureNameOches()
{
    find_worker->setModal(true);
    //Подаем сигнал слоту Find_Worker
    emit find_emloyee_Signal(_Name, _Surname, _Patronymic, _Phone);
}

//Поиск и удаление сотрудника по ФИО
void Worker::Delete_Worker(QString d_surname, QString d_name, QString d_ochestvo)
{
    i = 0; //для цикла
    flag = 0; //Для отслеживания кол-ва повторов
    tmp = 0; //Запоминает позицию ячейки

    //проходим всех сотрудников
    for(auto it = _Surname.begin(); it != _Surname.end(); it++)
    {

        // если ФИО совподает
        if(d_surname == _Surname[i] && d_name == _Name[i] && d_ochestvo == _Patronymic[i])
        {
            flag++;//для отслеживания повторов
            tmp = i; //для того чтобы в дальнейшем вернутся к этому индексу
            //Если совпадений больше 1
            if(flag>1)
            {
                QMessageBox::information(this, "Результат", "Сотрудников с такой ФИО > 1\n"
                                                            "Найдите нужного вам сотрудника по номеру телефона");
                flag=0;
                break;
            }
        }
        i++;
    }
    //Если найден только 1 сотрудник с такой ФИО
    if(flag != 0)
    {
        //Удаляем сотрудника
       _Surname.remove(tmp);
       _Name.remove(tmp);
       _Patronymic.remove(tmp);
       _Phone.remove(tmp);
        QMessageBox::information(this, "Результат", "Уволен!");
    }else//Если прошлись по всем сотрудникам и не нашли сотрудника которого искали
        if(i == _Surname.size())
        {
            QMessageBox::warning(this, "Ошибка!", "Такого сотрудника нет!");
            close();
        }
}

/*Окно Выбора каким способом удалить сотрудников если номера совпали у нескольких сотрудников*/
int Worker::Choice_or_All_delete()
{
    show();
    //Показываем окно выбора удаления сотрудников
    ui->Choice_DeleteWorker->show();
    exec();
    if(click_Choice_DeleteWorker == true) //Нажата кнопка ок(Сделан выбор удаления сотрудника)
        return 0;
    else                           //Нажата кнопка назад
        return 1;
}

//Удалить сотрудника по номеру телефона
int Worker::Delete_Worker_PHONE(QString d_phone)
{
    flag = 0;
    delete_phone = d_phone;
    i = 0;//Для цикла и для удаления
    tmp = 0; //для смещения ячейки для удаления
    //del = false;
    //Проходимся по сотрудникам
    for(auto it = _Phone.begin(); it != _Phone.end(); it++)
    {
        if(d_phone == *it)//Если номер совпал
        {
            flag++;//для отслеживания повторов
            tmp = i; //запоминаем позицию ячейки
        }
        i++;
    }
    //Если совпадений нет
    if(flag == 0)
    {
        close();
        QMessageBox::warning(this, "Ошибка", "Сотрудника с таким номерсом НЕ найден!");
    }else//Если нашли номер
        if(flag == 1){
            _Surname.remove(tmp);
            _Name.remove(tmp);
            _Patronymic.remove(tmp);
            _Phone.remove(tmp);
            QMessageBox::information(this, "Результат", "Уволен!");
        }else
            if(flag>1) //Если найденных номеров >1
            {
                QMessageBox::information(this, "Результат", "Сотрудников с таким номером > 1");
                tmp = Choice_or_All_delete();
                if(tmp == 1) //Нажата кнопка назад
                    del = true;
                else          //Нажата кнопка ок(Сделан выбор удаления сотрудника)
                    del = false;
            }

    if(del == false)//Нажата кнопка ок(Сделан выбор удаления сотрудника)
    {
        return 0;
    }else{         //Нажата кнопка назад
        return 1;
    }
}

//ОКкно где мы Задаем кол-во сотрудников
//проверка ввода кол-ва добавляемых сотрудников
void Worker::on_worker_textChanged(const QString &arg1)
{
    int n = arg1.toInt();
    //если строка не пуста и не равна 0
    if(!arg1.isEmpty() && n != 0)
    {
        //Убираем блокоровку с кнопки
        ui->countWorker->setDisabled(false);
    }else{
        ui->countWorker->setDisabled(true);
    }
}

//ОКкно где мы Задаем кол-во сотрудников
//Кнопка закрытия окна
void Worker::on_close_Btn_clicked()
{
    //Отчищаем строку кол-ва сотрудников
    ui->worker->clear();
    //Отчищаем таблицу
    ui->tableWidget->clear();
    //Срываем и закрываем окно
    ui->countWorker_2->hide();
    close();
}

//Окно новый сотрудник
//Проверка ввода фамилии
void Worker::on_surname_textChanged(const QString &arg1)
{
    //Если строка ввода фамилии не пуста
    if(!arg1.isEmpty())
    {
        ui->surname_label->setStyleSheet("color: black");
    }
}

//Окно новый сотрудник
//Проверка ввода имени
void Worker::on_name_textChanged(const QString &arg1)
{
    //Если имя введено
    if(!arg1.isEmpty())
    {
        ui->name_label->setStyleSheet("color: black");
    }
}

//Окно новый сотрудник
//Проверка ввода отчества
void Worker::on_patronymic_textChanged(const QString &arg1)
{
    //Если отчество введено
    if(!arg1.isEmpty())
    {
        ui->patronymic_label->setStyleSheet("color: black");
    }
}

//Окно новый сотрудник
//Проверка ввода номера телефона
void Worker::on_phone_textChanged(const QString &arg1)
{
    //Если номер не начинается с нуля
    if(arg1 != "0")
    {
        //Если номмер введен и не равен 11 цифрам
        if(!arg1.isEmpty() && ui->phone->text().size() != 11)
        {
            ui->countPhone_label->setText("Введите 11 цифр");
            ui->phone_label->setStyleSheet("color: black");
            ui->countPhone_label->setStyleSheet("color: red");
        }else{
            ui->countPhone_label->clear();
        }
    }else{
        ui->phone->clear();
    }
}

//Окно новый сотрудник
//кнопка возвращает к окну выбора добавления сотрудника
void Worker::on_Back_ChoiceAddWorker_Btn_clicked()
{
    ui->surname_label->setStyleSheet("color: black");
    ui->name_label->setStyleSheet("color: black");
    ui->patronymic_label->setStyleSheet("color: black");
    ui->phone_label->setStyleSheet("color: black");
    //Отчищаем строки ФИО и номер телефона
    ui->surname->clear();
    ui->name->clear();
    ui->patronymic->clear();
    ui->phone->clear();
    //Скрываем окно добавления сотрудника
    ui->new_Worker->hide();
    //Показываем окно выбора каким способом добавить сотрудника
    ui->Choice->show();
}

//Окно уволить сотрудника
//Кнопка возвращает к окну выбора каким из способов уволить сотрудника
void Worker::on_back_Choice_DeleteWorker_Btn_clicked()
{
    ui->deleteWorkerChoice_label->setStyleSheet("color: black");
    //Отчищаем текст
    ui->Worker_textBrowser->clear();
    ui->deleteWorker_line->clear();
    //Скрываем окно увольнения сотрудника по выбору
    ui->deleteChoice_Box->hide();
    //Показываем окно выбора каким из способов уволить сотрудника
    ui->Choice_DeleteWorker->show();
}

//Окно Добавить одного сотрудника или несколько
//Кнопка Отмены закрывает окно
void Worker::on_cancel_clicked()
{
    //Убираем галочки с выбора добавления сотрудника(ов)
    ui->OneWorker->setChecked(false);
    ui->Workers->setChecked(false);
    //закрываем окно
    close();
}

/*Окно Увольнение сотрудника(ов) по выбору либо уволить все найденных сотрудников, либо выбрать кого уволить*/
//Кнопка возвращает к окну Поиск сотрудника по номеру телефона для удаления
void Worker::on_back_find_worker_phone_delete_clicked()
{
    /*Отслеживаем нажатие кнопки чтобы вернуться к окну Поиск сотрудника по номеру телефона для удаления*/
    click_Choice_DeleteWorker = false;
    //скрываем окно добавить одного сотрудника или несколько
    ui->Choice_DeleteWorker->hide();
    //Убираем галочки с выбора способа как уволить сотрудника(ов)
    ui->All_deleteWorker_check->setChecked(false);
    ui->delete_WorkerChoice_check->setChecked(false);
    //Скрыть окно
    hide();
}

void Worker::on_deleteWorker_line_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty())
    {
        ui->deleteWorkerChoice_label->setStyleSheet("color: black");
    }
}
