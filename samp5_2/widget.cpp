#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    on_btnRecoverList_clicked();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnRecoverList_clicked()
{
    QStringList theStrList;
    theStrList << "北京" << "上海" << "苏州" << "昆山" << "南京" << "合肥" << "阜阳" << "汽车站" << "北上广";
    theModel = new QStringListModel(this);
    theModel->setStringList(theStrList);

    ui->listView->setModel(theModel);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
}


void Widget::on_btnAddItem_clicked()
{
    qDebug() << "theModel->rowCount() = " << theModel->rowCount();
    theModel->insertRow(theModel->rowCount());
    QModelIndex localIndex = theModel->index(theModel->rowCount() - 1,0);
    theModel->setData(localIndex,"new item",Qt::DisplayRole);
    ui->listView->setCurrentIndex(localIndex);
}


void Widget::on_btnInsertItem_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    qDebug() << "index.row() = " << index.row();
    theModel->insertRow(index.row());
    theModel->setData(index,"insert item",Qt::DisplayRole);
    ui->listView->setCurrentIndex(index);
}


void Widget::on_btnDeleteCurItem_clicked()
{
    QModelIndex localCurrentIndex = ui->listView->currentIndex();
    theModel->removeRow(localCurrentIndex.row());
}


void Widget::on_btnCLearList_clicked()
{
    theModel->removeRows(0,theModel->rowCount());
}


void Widget::on_btnShowModel_clicked()
{
    ui->plainTextEdit->clear();
    QStringList strList = theModel->stringList();
    for (int i =0 ;i < strList.count() ;i++ ) {
        ui->plainTextEdit->appendPlainText(strList.at(i));
    }
}


void Widget::on_btnClearText_clicked()
{
    ui->plainTextEdit->clear();
}



void Widget::on_listView_clicked(const QModelIndex &index)
{
    ui->label->setText(QString::asprintf("当前条目： row = %d,column = %d",index.row(),index.column()));
}

