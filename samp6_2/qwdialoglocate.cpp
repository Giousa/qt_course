#include "qwdialoglocate.h"
#include "ui_qwdialoglocate.h"
#include <QDebug>
#include "mainwindow.h"

QWDialogLocate::QWDialogLocate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialogLocate)
{
    ui->setupUi(this);
}

QWDialogLocate::~QWDialogLocate()
{
    qDebug() << "定位单元格，弹框移除！";

    delete ui;
}

void QWDialogLocate::setSpinRange(int rowCount, int colCount)
{

}

void QWDialogLocate::setSpinValue(int rowNo, int colNo)
{
    ui->spinBoxRowNo->setValue(rowNo);
    ui->spinBoxColNo->setValue(colNo);
}


void QWDialogLocate::closeEvent(QCloseEvent *event)
{
    MainWindow *parWind = (MainWindow*)parentWidget();
    parWind->setActLocateEnable(true);
    parWind->setDlgLocateNull();
}



void QWDialogLocate::on_btnSetText_clicked()
{
    int row = ui->spinBoxRowNo->value();
    int column = ui->spinBoxColNo->value();

    MainWindow *parWind = (MainWindow*)parentWidget();
    parWind->setACellText(row,column,ui->lineEdit->text());
    if(ui->checkBoxColAdd->isChecked()){
        ui->spinBoxColNo->setValue(1+ui->spinBoxColNo->value());
    }

    if(ui->checkBoxRowAdd->isChecked()){
        ui->spinBoxRowNo->setValue(1+ui->spinBoxRowNo->value());
    }
}
