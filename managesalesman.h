#ifndef MANAGESALESMAN_H
#define MANAGESALESMAN_H

#include <QWidget>
#include "dbcon.h"
#include "erp.h"
#include <QCompleter>
#include "sch.h"

namespace Ui {
class ManageSalesMan;
}

class ManageSalesMan : public QWidget
{
    Q_OBJECT

public:
    QString loginid;
    DbCon conn;
    ERP erp;
    SCH sch;
    explicit ManageSalesMan(QWidget *parent = 0);
    ~ManageSalesMan();

private slots:
    void on_save_btn_clicked();

    void on_edit_btn_clicked();

    void on_clear_btn_clicked();

    void on_delete_btn_clicked();

private:
    Ui::ManageSalesMan *ui;
    enum columns{
        ID,NAME, ADDRESS, CITY
    };
    void loadtable();
    QString salesmanid = "";
};

#endif // MANAGESALESMAN_H
