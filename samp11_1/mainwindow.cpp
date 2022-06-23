#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
//    ui->tableView->setSelectionModel(QAbstractItemView::SingleSelection);
//    ui->tableView->setAlternatingRowColors(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::getFieldNames()
{

}

void MainWindow::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{

}

void MainWindow::on_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{

}

//打开数据库
void MainWindow::on_actOpenDB_triggered()
{
//    QString aFile = QFileDialog::getOpenFileName(this,"选择数据库文件","","SQLite数据库(*.db *.db3)");
//    if(aFile.isEmpty()){
//        qDebug() << "数据库文件为空！";
//        return;
//    }

    QString aFile = "/Users/zhangmengmeng/Workspace/qt/demodb.db3";
    qDebug() << "数据库文件： " << aFile;

    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName(aFile);

    if(!DB.open()){
        qDebug() << "打开数据库失败！";
        return;
    }

    openTable();
}

void MainWindow::openTable()
{
    tabModel = new QSqlTableModel(this,DB);
    tabModel->setTable("employee");
    tabModel->setSort(tabModel->fieldIndex("empNo"),Qt::AscendingOrder);
    tabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    if(!tabModel->select()){
        qDebug() << "数据库，表打开失败！";
        return;
    }

    qDebug() << "数据库，表打开成功！";
    qDebug() << "字段角标位置: empNo_index = " << tabModel->fieldIndex("empNo") << ",Mobile_index = " << tabModel->fieldIndex("Mobile");
    qDebug() << "字段数据： empNo_value = " << tabModel->record(2).value("empNo").toInt() << ",Name_value = " << tabModel->record(2).value("Name").toString();
    //字段显示名
    tabModel->setHeaderData(tabModel->fieldIndex("empNo"),Qt::Horizontal,"工号");
    tabModel->setHeaderData(tabModel->fieldIndex("Name"),Qt::Horizontal,"姓名");
    tabModel->setHeaderData(tabModel->fieldIndex("Gender"),Qt::Horizontal,"性别");
    tabModel->setHeaderData(tabModel->fieldIndex("Height"),Qt::Horizontal,"身高");
    tabModel->setHeaderData(tabModel->fieldIndex("Birthday"),Qt::Horizontal,"出生日期");
    tabModel->setHeaderData(tabModel->fieldIndex("Mobile"),Qt::Horizontal,"手机");
    tabModel->setHeaderData(tabModel->fieldIndex("Province"),Qt::Horizontal,"省份");
    tabModel->setHeaderData(tabModel->fieldIndex("City"),Qt::Horizontal,"城市");
    tabModel->setHeaderData(tabModel->fieldIndex("Department"),Qt::Horizontal,"部门");
    tabModel->setHeaderData(tabModel->fieldIndex("Education"),Qt::Horizontal,"学历");
    tabModel->setHeaderData(tabModel->fieldIndex("Salary"),Qt::Horizontal,"工资");
    tabModel->setHeaderData(tabModel->fieldIndex("Memo"),Qt::Horizontal,"备注"); //这两个字段不再tableView中显示
    tabModel->setHeaderData(tabModel->fieldIndex("Photo"),Qt::Horizontal,"照片");


    theSelection = new QItemSelectionModel(tabModel);

    //theSelection当前项变化时触发currentChanged信号
    connect(theSelection,SIGNAL(currentChanged(QModelIndex,QModelIndex)),
                this,SLOT(on_currentChanged(QModelIndex,QModelIndex)));
    //选择行变化时
    connect(theSelection,SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
                this,SLOT(on_currentRowChanged(QModelIndex,QModelIndex)));

    ui->tableView->setModel(tabModel);
    ui->tableView->setSelectionModel(theSelection);
    ui->tableView->setColumnHidden(tabModel->fieldIndex("Memo"),true);
    ui->tableView->setColumnHidden(tabModel->fieldIndex("Photo"),true);

    //tableView上为“性别”和“部门”两个字段设置自定义代理组件
    QStringList strList;
    strList<<"男"<<"女";
    bool isEditable=false;
    delegateSex.setItems(strList,isEditable);
    ui->tableView->setItemDelegateForColumn(tabModel->fieldIndex("Gender"),&delegateSex); //Combbox选择型

    strList.clear();
    strList<<"销售部"<<"技术部"<<"生产部"<<"行政部";
    isEditable=true;
    delegateDepart.setItems(strList,isEditable);
    ui->tableView->setItemDelegateForColumn(tabModel->fieldIndex("Department"),&delegateDepart); //Combbox选择型


}
