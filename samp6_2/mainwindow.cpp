#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qwdialogsize.h"
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>

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

//设置单元格内容
void MainWindow::setACellText(int row, int col, QString text)
{
    QModelIndex localIndex = theModel->index(row,col);
    theSelection->clearSelection();
    theSelection->setCurrentIndex(localIndex,QItemSelectionModel::Select);
    theModel->setData(localIndex,text,Qt::DisplayRole);
}

void MainWindow::setActLocateEnable(bool flag)
{
    ui->actCellLocation->setEnabled(flag);
}

void MainWindow::setDlgLocateNull()
{
    locateDialog = NULL;
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
    ui->actCellLocation->setEnabled(false);
    locateDialog = new QWDialogLocate(this);
    locateDialog->setAttribute(Qt::WA_DeleteOnClose);
    Qt::WindowFlags flags = locateDialog->windowFlags();
    //StayOnTop
    locateDialog->setWindowFlags(flags | Qt::WindowStaysOnTopHint);

    locateDialog->setSpinRange(theModel->rowCount(),theModel->columnCount());
    QModelIndex curIndex = theSelection->currentIndex();
    if(curIndex.isValid()){
        locateDialog->setSpinValue(curIndex.row(),curIndex.column());
    }
    locateDialog->show();
}

//初始化数据模型
void MainWindow::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
    ui->labelCellCurrent->setText(QString::asprintf("当前单元格：%d行，%d列。",current.row(),current.column()));
    ui->labelCellText->setText("单元格内容: "+theModel->itemFromIndex(current)->text());
}

//表格点击
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    if(locateDialog != NULL){
        locateDialog->setSpinValue(index.row(),index.column());
    }

    emit cellIndexChangedSignals(index.row(),index.column());
}


//窗口关闭触发事件
void MainWindow::closeEvent(QCloseEvent *event)
{
    int localQuestion = QMessageBox::question(this,"确定","是否退出本程序？",QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(localQuestion == QMessageBox::Yes){
        event->accept();
    }else{
        event->ignore();
    }
}


void MainWindow::setACellTextSlot(int row, int col, QString &text)
{
    qDebug() << "setACellTextSlot槽函数：row = " << row << ",col = " << col << ",text = " << text;
}

void MainWindow::setActLocateEnableSlot(bool flag)
{
    qDebug() << "setActLocateEnableSlot槽函数：flag = " << flag;
}

void MainWindow::cellIndexChangedSignals(int rowNo, int colNo)
{
    qDebug() << "cellIndexChangedSignals 信号：rowNo = " << rowNo << ",colNo = " << colNo;
}
