#include "qwdialoglocate.h"
#include "ui_qwdialoglocate.h"

QWDialogLocate::QWDialogLocate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialogLocate)
{
    ui->setupUi(this);
}

QWDialogLocate::~QWDialogLocate()
{
    delete ui;
}

void QWDialogLocate::setSpinRange(int rowCount, int colCount)
{

}

void QWDialogLocate::setSpinValue(int rowNo, int colNo)
{

}


void QWDialogLocate::closeEvent(QCloseEvent *event)
{

}


void QWDialogLocate::on_btnSelFont_clicked()
{

}

