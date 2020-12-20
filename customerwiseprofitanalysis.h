#ifndef CUSTOMERWISEPROFITANALYSIS_H
#define CUSTOMERWISEPROFITANALYSIS_H

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

namespace Ui {
class CustomerWiseProfitAnalysis;
}

class CustomerWiseProfitAnalysis : public QWidget
{
    Q_OBJECT

public:
    QString loginid;
    DbCon conn;
    ERP erp;
    SCH sch;
    explicit CustomerWiseProfitAnalysis(QWidget *parent = 0);
    ~CustomerWiseProfitAnalysis();

private slots:
    void autocompleter(QString sql, QLineEdit *txt1, QLineEdit *txt2);
    void onItemHighlighted(const QModelIndex &index);
    void editingFinished();
    void loadParams();
    void printPreview(QPrinter *p);

    void on_customername_textEdited(const QString &arg1);

    void on_btn_next_clicked();

private:
    Ui::CustomerWiseProfitAnalysis *ui;
    QString html;
    QTimer *timer;
    void loadReport();
    QPrinter *printer;
    QPrintDialog *printDlg;
    QPageSetupDialog *pageDlg;
    QPrintPreviewDialog *pd;
    int pagenum=0;
};

#endif // CUSTOMERWISEPROFITANALYSIS_H
