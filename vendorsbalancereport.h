#ifndef VENDORSBALANCEREPORT_H
#define VENDORSBALANCEREPORT_H

#include <QWidget>
#include "dbcon.h"
#include "erp.h"
#include <QCompleter>
#include "sch.h"
#include <QtCore>
#include <QtGui>
#include <QtPrintSupport/qprinter.h>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QTextDocument>
#include <QPrintPreviewWidget>
#include <QPrintDialog>
#include <QPageSetupDialog>
#include <QPainter>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include "comboboxes.h"

namespace Ui {
class VendorsBalanceReport;
}

class VendorsBalanceReport : public QWidget
{
    Q_OBJECT

public:
    QString loginid;
    DbCon conn;
    ERP erp;
    SCH sch;
    ComboBoxes cb;
    explicit VendorsBalanceReport(QWidget *parent = 0);
    ~VendorsBalanceReport();

private slots:
    void autocompleter(QString sql, QLineEdit *txt1, QLineEdit *txt2);
    void onItemHighlighted(const QModelIndex &index);
    void editingFinished();
    void loadParams();
    void printPreview(QPrinter *p);

    void on_groupname_textEdited(const QString &arg1);

    void on_btn_next_clicked();

private:
    Ui::VendorsBalanceReport *ui;
    QString html;
    QTimer *timer;
    void loadReport();
    QPrinter *printer;
    QPrintDialog *printDlg;
    QPageSetupDialog *pageDlg;
    QPrintPreviewDialog *pd;
    int pagenum=0;
};

#endif // VENDORSBALANCEREPORT_H
