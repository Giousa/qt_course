#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDataWidgetMapper>
#include "qwcomboboxdelegate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QSqlDatabase DB;
    QSqlTableModel *tabModel;
    QItemSelectionModel *theSelection;
    QDataWidgetMapper *dataMapper;

    QWComboBoxDelegate delegateSex;
    QWComboBoxDelegate delegateDepart;
    void openTable();
    void getFieldNames();

private slots:
    void on_currentChanged(const QModelIndex &current,const QModelIndex &previous);
    void on_currentRowChanged(const QModelIndex &current,const QModelIndex &previous);

    void on_actOpenDB_triggered();
};
#endif // MAINWINDOW_H
