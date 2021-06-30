#ifndef ADDWORKER_H
#define ADDWORKER_H

#include <QDialog>
#include <worker.h>

namespace Ui {
class addWorker;
}

class addWorker : public QDialog, public Worker
{
    Q_OBJECT

public:
    explicit addWorker(QWidget *parent = nullptr);
    ~addWorker();

private:
    Ui::addWorker *ui;

};

#endif // ADDWORKER_H
