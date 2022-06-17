#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qwdialogsize.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    theModel = new QStandardItemModel(2,4,this); //创建数据模型
    theSelection = new QItemSelectionModel(theModel);//Item选择模型
    connect(theSelection,SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this,SLOT(on_currentChanged(QModelIndex,QModelIndex)));

    //为tableView设置数据模型
    ui->tableView->setModel(theModel); //设置数据模型
    ui->tableView->setSelectionModel(theSelection);//设置选择模型

}

MainWindow::~MainWindow()
{
    delete ui;
}

//设置行数和列数
void MainWindow::on_actSetRowAndColumn_triggered()
{
    QWDialogSize *dialog = new QWDialogSize(this);

    Qt::WindowFlags flags = dialog->windowFlags();

    dialog->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);
    dialog->setRowColumn(theModel->rowCount(),theModel->columnCount());

    //模态方式，需要等待返回结果
    int ret = dialog->exec();
    if(ret == dialog->Accepted){
        qDebug() << "列数和行数按钮： 确认!";
        theModel->setColumnCount(dialog->columnCount());
        theModel->setRowCount(dialog->rowCount());
    }else if(ret == dialog->Rejected){
        qDebug() << "列数和行数按钮： 取消!";
    }else{
        qDebug() << "列数和行数按钮：点击错误!";
    }

    delete dialog;
}


//设置头部和标题
void MainWindow::on_actSetHeadAndTitle_triggered()
{
    if(headerDialog == NULL){
        headerDialog = new QWDialogHeaders(this);
    }

    if(headerDialog->getHeaderList().count() != theModel->columnCount()){
        QStringList strList;
        for (int i = 0;i < theModel->columnCount() ;i++ ) {
            strList.append(theModel->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString());
        }
        headerDialog->setHeaderList(strList);
    }

    int ret = headerDialog->exec();
    if(ret == QDialog::Accepted){
        QStringList headerList = headerDialog->getHeaderList();
        theModel->setHorizontalHeaderLabels(headerList);
    }else{
        qDebug() << "取消了";
    }
}


//定位单元格
void MainWindow::on_actCellLocation_triggered()
{

}

