#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    theModel = new QStandardItemModel(2,FixedColumnCount,this);
    theSelection = new QItemSelectionModel(theModel);

    connect(theSelection,SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(on_currentChanged(QModelIndex,QModelIndex)));

    ui->tableView->setModel(theModel);
    ui->tableView->setSelectionModel(theSelection);
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);

}

MainWindow::~MainWindow()
{
    delete ui;
}



/**
 * 当前单元格内容变化
 */
void MainWindow::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    if(!current.isValid()){
        qDebug() << "单元格没有任何变化！";
        return;
    }

    ui->labelCurCell->setText(QString::asprintf("当前单元格：%d行，%d列",current.row(),current.column()));

    QStandardItem *aItem = theModel->itemFromIndex(current);
    ui->labelCellText->setText("单元格内容："+aItem->text());
    ui->actFontBold->setChecked(aItem->font().bold());
}

/**
 * 打开文件
 * @brief MainWindow::on_actOpen_triggered
 */
void MainWindow::on_actOpen_triggered()
{
    QString curPath = QCoreApplication::applicationDirPath();
    QString fileName = QFileDialog::getOpenFileName(this,"打开一个文件",curPath,"并数据文件(*.txt);;所有文件(*.*)");
    if(fileName.isEmpty()){
        qDebug() << "文件为空！";
        return;
    }

    QStringList fileContent;
    QFile file(fileName);

    //打开文件
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        ui->plainTextEdit->clear();
        while(!stream.atEnd()){
            QString str = stream.readLine();
            ui->plainTextEdit->appendPlainText(str);
            fileContent.append(str);
        }

        file.close();
        ui->labelPath->setText("当前文件："+fileName);
        initModelFromStringList(fileContent);
    }

}

/**
 * 初始化数据
 */
void MainWindow::initModelFromStringList(QStringList &fileContent)
{
    int rowCnt = fileContent.count();
    theModel->setRowCount(rowCnt -1);//文本行数，第一行是标题
    QString header = fileContent.at(0);
    QStringList headerList = header.split(QRegularExpression("\\s+"),Qt::SkipEmptyParts);
    theModel->setHorizontalHeaderLabels(headerList);

    //设置表格数据
    QStandardItem *aItem;
    QStringList tmpList;
    int j ;
    for (int i= 1;i< rowCnt ;i++ ) {
        QString aLineText = fileContent.at(i);
        tmpList = aLineText.split(QRegularExpression("\\s+"),Qt::SkipEmptyParts);
        for (j = 0;j < FixedColumnCount-1;j++ ) {
            aItem = new QStandardItem(tmpList.at(j));
            theModel->setItem(i-1,j,aItem);
        }
        aItem = new QStandardItem(headerList.at(j));
        aItem->setCheckable(true);
        if(tmpList.at(j) =='0'){
            aItem->setCheckState(Qt::Unchecked);
        }else{
            aItem->setCheckState(Qt::Checked);
        }
        theModel->setItem(i-1,j,aItem);
    }

}


void MainWindow::on_actAppend_triggered()
{
    //在表格的最后添加行
    QList<QStandardItem*> aItemList;
    QStandardItem *aItem;
    //不包含最后一列
    for (int i = 0;i < FixedColumnCount -1;i++ ) {
        aItem = new QStandardItem("0");
        aItemList << aItem;
    }

    //获取最后一列的表头文字
    QString str = theModel->headerData(theModel->columnCount()-1,Qt::Horizontal,Qt::DisplayRole).toString();
    aItem = new QStandardItem(str);
    aItem->setCheckable(true);
    aItemList << aItem;

    theModel->insertRow(theModel->rowCount(),aItemList);
    QModelIndex curIndex = theModel->index(theModel->rowCount() - 1,0);
    theSelection->clearSelection();
    theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
}


void MainWindow::on_actInsert_triggered()
{

}


void MainWindow::on_actDelete_triggered()
{
    QModelIndex curIndex = theSelection->currentIndex();
    if(curIndex.row() == theModel->rowCount() -1){
        theModel->removeRow(curIndex.row());
    }else{
        theModel->removeRow(curIndex.row());
        theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
    }

}


void MainWindow::on_actAlignLeft_triggered()
{
    if(!theSelection->hasSelection()){
        return;
    }

    QModelIndexList selectIndexList = theSelection->selectedIndexes();
    for (int i = 0;i < selectIndexList.count() ;i++ ) {
        QModelIndex aIndex = selectIndexList.at(i);
        QStandardItem *aItem = theModel->itemFromIndex(aIndex);
        aItem->setTextAlignment(Qt::AlignLeft);
    }
}

