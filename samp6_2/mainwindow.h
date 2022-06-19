#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "qwdialogheaders.h"
#include "qwdialoglocate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setACellText(int row,int col,QString text);

    void setActLocateEnable(bool flag);

    void setDlgLocateNull();

private slots:
    void on_actSetRowAndColumn_triggered();

    void on_actSetHeadAndTitle_triggered();

    void on_actCellLocation_triggered();

    void on_currentChanged(const QModelIndex &current,const QModelIndex &previous);

    void on_tableView_clicked(const QModelIndex &index);

    void setACellTextSlot(int row,int col,QString &text);

    void setActLocateEnableSlot(bool flag);

private:
    Ui::MainWindow *ui;

    QStandardItemModel  *theModel;//数据模型
    QItemSelectionModel *theSelection;//Item选择模型

    QWDialogHeaders *headerDialog = NULL;

    QWDialogLocate *locateDialog = NULL;

    void closeEvent(QCloseEvent *event);

    void cellIndexChangedSignals(int rowNo,int colNo);


};
#endif // MAINWINDOW_H
