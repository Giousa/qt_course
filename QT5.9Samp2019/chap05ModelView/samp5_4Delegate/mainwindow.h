#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include    <QLabel>
#include    <QStandardItemModel>
#include    <QItemSelectionModel>

#include    "qwintspindelegate.h"
#include    "qwfloatspindelegate.h"

#include    "qwcomboboxdelegate.h"


#define     FixedColumnCount    6       //文件固定6行

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

//用于状态栏的信息显示
    QLabel  *LabCurFile;  //当前文件
    QLabel  *LabCellPos;    //当前单元格行列号
    QLabel  *LabCellText;   //当前单元格内容

    QWIntSpinDelegate    intSpinDelegate; //整型数
    QWFloatSpinDelegate  floatSpinDelegate; //浮点数
    QWComboBoxDelegate   comboBoxDelegate; //列表选择

    QString fCurFile;//当前文件名

    QStandardItemModel  *theModel;//数据模型
    QItemSelectionModel *theSelection;//Item选择模型

    void    iniModelFromStringList(QStringList&);//从StringList初始化数据模型

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);

    void on_actOpen_triggered(); //打开文件

    void on_actAppend_triggered(); //添加行

    void on_actInsert_triggered();//插入行

    void on_actDelete_triggered();//删除行

    void on_actModelData_triggered();  //到处模型数据

    void on_actSave_triggered();//保存文件

    void on_actAlignCenter_triggered();

    void on_actFontBold_triggered(bool checked);

    void on_actAlignLeft_triggered();

    void on_actAlignRight_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
