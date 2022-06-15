#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QItemSelectionModel>

#define FixedColumnCount 6


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

    QStandardItemModel *theModel;
    QItemSelectionModel *theSelection;

    void initModelFromStringList(QStringList &strList);


private slots:
    void on_currentChanged(const QModelIndex &current,const QModelIndex &previous);


    void on_actOpen_triggered();
    void on_actAppend_triggered();
    void on_actInsert_triggered();
    void on_actDelete_triggered();
    void on_actAlignLeft_triggered();
};
#endif // MAINWINDOW_H
