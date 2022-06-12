#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnSetHeader_clicked();

    void on_btnInitData_clicked();

    void on_btnSetRow_clicked();

    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_btnInsertRow_clicked();

    void on_btnAddRow_clicked();

    void on_btnDeleteCurrentRow_clicked();

    void on_checkBoxEdit_clicked(bool checked);

    void on_checkBoxRowHeader_clicked(bool checked);

    void on_checkBoxColumnHeader_clicked(bool checked);

    void on_checkBoxRowColor_clicked(bool checked);

    void on_radioButtonRowSelect_clicked();

    void on_radioButtonCellSelect_clicked();

    void on_btnReadRowToText_clicked();

private:
    Ui::MainWindow *ui;

    //自定义单元格type的类型，创建单元格item时使用
    enum CellType{ctName=1000,ctSex,ctBirth,ctNation,ctPartyM,ctScore};

    //各字段在表格中的序号
    enum FiledColNum{colName=0,colSex,colBirthdy,colNation,colParyM,colScore};

    //状态栏，显示单元格的行号，列号
    QLabel *labCellIndex;

    //状态栏，显示单元格的type
    QLabel *labCellType;

    //状态栏，显示学号
    QLabel *labStudID;

    void initStatusBar();

    //为某一行创建items
    void createItemARow(int rowNo,QString name,QString sex,QDate birth,QString nation,bool isPM,int score);

};
#endif // MAINWINDOW_H
