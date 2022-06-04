#include "widget.h"
#include "ui_widget.h"
#include <QTextBlock>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


/**
 * 初始化列表
 */
void Widget::on_btnInitItems_clicked()
{
    QIcon icon;
    icon.addFile(":/images/icons/aim.ico");
    ui->comboBoxItem->clear();
    for(int i = 0; i< 20; i++){
        ui->comboBoxItem->addItem(icon,QString::asprintf("Item-%d",i));
    }
}

/**
 * 初始化城市
 */
void Widget::on_btnInitCitys_clicked()
{
    ui->comboBoxCity->clear();

    //方式一
//    QStringList strList;
//    strList << "北京市" << "上海市" << "阜阳市" << "合肥市" << "南京市" << "苏州市";
//    ui->comboBoxCity->addItems(strList);
    //方式二
    QMap<QString,int> cityMap;
    cityMap.insert("北京市",10);
    cityMap.insert("上海市",20);
    cityMap.insert("深圳市",30);
    cityMap.insert("合肥市",40);
    cityMap.insert("阜阳市",50);
    cityMap.insert("昆山市",60);
    cityMap.insert("蚌埠市",70);

    foreach(const QString &str,cityMap.keys()){
        ui->comboBoxCity->addItem(str,cityMap.value(str));
    }
}


/**
 * 城市选择
 */
void Widget::on_comboBoxCity_currentIndexChanged(int index)
{
    qDebug() << "选择的城市索引： index = " << index << "关联数据： " << ui->comboBoxCity->currentData().toString();
    ui->plainTextEdit->appendPlainText("选择索引 = "+QString::number(index) + ",城市：" + ui->comboBoxCity->currentText());
}

/**
 * 清除文本框
 */
void Widget::on_btnClearContent_clicked()
{
    ui->plainTextEdit->clear();
}

/**
 * 添加内容到选择框
 */
void Widget::on_btnAddToBox_clicked()
{
    qDebug() << "读取文本框内容：" << ui->plainTextEdit->toPlainText();
    QTextDocument *doc = ui->plainTextEdit->document();
    int cnt = doc->blockCount();
    QIcon icon(":/images/icons/aim.ico");
    ui->comboBoxItem->clear();
    for (int i = 0;i < cnt ; i++) {
        QTextBlock textBlock = doc->findBlockByLineNumber(i);
        ui->comboBoxItem->addItem(icon,textBlock.text());
    }
}

