#include "qwdialogsize.h"
#include "ui_qwdialogsize.h"
#include <QMessageBox>
#include <QDebug>

QWDialogSize::QWDialogSize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialogSize)
{
    ui->setupUi(this);
}

QWDialogSize::~QWDialogSize()
{
//    QMessageBox::information(this,"提示","设置表格行数和列数对话框删除");
    qDebug() << "关闭行数和列数设置对话框";
    delete ui;
}

int QWDialogSize::rowCount()
{
    return ui->spinBoxRow->value();
}

int QWDialogSize::columnCount()
{
    return ui->spinBoxColumn->value();
}

void QWDialogSize::setRowColumn(int row, int column)
{
    ui->spinBoxRow->setValue(row);
    ui->spinBoxColumn->setValue(column);
}
