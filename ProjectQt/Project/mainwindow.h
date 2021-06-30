#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "second_window.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    //Опции выбор действия
    void toChange_supplierSlot();

private slots:
    //Меню
    void on_option_clicked();

    //Проверка на ввод выбора в меню
    void on_state_menu_textChanged(const QString &arg1);

    void on_actionQuit_triggered();

signals:
    void addWorkSignal();

    void WorkerSignal();

    void ChangeSupp_Signal(Supplier &sup);

    void ChoiceSignal();

    void SupplierSignal();

    void SkladSignal(Supplier &sup);

    void Find_SureNameOches_Signal();

    void condition_sklad_Signal();

    void Install_costKit_Signal(Supplier &sup);

    void Sell();

    void Save_toFile(Worker &work, Supplier &sup, Storage &sklad);

    void supplierDataChange_Signal(Supplier &sup);

    void second_window_Signal(Worker &worl, Storage &sklad);

private:
    Ui::MainWindow *ui;
    Supplier *sup;
    Worker *work;
    Storage *sklad;
    Save_Data *save;
    Second_Window *second_window;
};
#endif // MAINWINDOW_H
