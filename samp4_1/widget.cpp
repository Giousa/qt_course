#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->btnDec->setProperty("type","DEC");
    ui->btnBin->setProperty("type","BIN");
    ui->btnHex->setProperty("type","HEX");

    connect(ui->btnDec,&QPushButton::clicked,this,&Widget::on_btnJinzhi_clicked);
    connect(ui->btnBin,&QPushButton::clicked,this,&Widget::on_btnJinzhi_clicked);
    connect(ui->btnHex,&QPushButton::clicked,this,&Widget::on_btnJinzhi_clicked);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnCal_clicked()
{
    int num = ui->editNum->text().toInt();
    float price = ui->editPrice->text().toFloat();
    float total = num * price;
    ui->editTotal->setText(QString::number(total));
}

void Widget::on_btnJinzhi_clicked()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());

    if(QString::compare(btn->property("type").toString(),"DEC") == 0){
        qDebug() << "点击了：十进制";
//        QString decStr = ui->editDec->text();
//        ui->editHex->setText(decStr.setNum(decStr.toInt(),16).toUpper());
//        ui->editBin->setText(decStr.setNum(decStr.toInt(),2));

        int val = ui->editDec->text().toInt();
        ui->editBin->setText(QString::number(val,2));
//        ui->editHex->setText(QString::number(val,16).toUpper());
        QString hex = QString("%1").arg(val, 4, 16, QLatin1Char('0'));  // 保留四位，不足补零
        ui->editHex->setText(hex);
    }else if(QString::compare(btn->property("type").toString(),"BIN") == 0){
        qDebug() << "点击了：二进制";

        QString binStr = ui->editBin->text();
        bool ok;
        int val = binStr.toInt(&ok,2);
        ui->editDec->setText(QString::number(val,10));
//        ui->editHex->setText(QString::number(val,16).toUpper());
        QString hex = QString("%1").arg(val, 4, 16, QLatin1Char('0'));  // 保留四位，不足补零
        ui->editHex->setText(hex);
    }else if(QString::compare(btn->property("type").toString(),"HEX") == 0){
        qDebug() << "点击了：十六进制";
        QString hexStr = ui->editHex->text();
        bool ok;
        int val = hexStr.toInt(&ok,16);
        ui->editDec->setText(QString::number(val,10));
        ui->editBin->setText(QString::number(val,2));
    }else{
        qDebug() << "按钮点击有误!";
    }

}

