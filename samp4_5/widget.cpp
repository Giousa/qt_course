#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    initCurrentTime();

    //定时器
    fTimer = new QTimer(this);
    fTimer->stop();
//    fTimer->setInterval(1000);

    connect(fTimer,&QTimer::timeout,this,&Widget::on_timer_timeout);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnGet_clicked()
{
    initCurrentTime();

}

/**
 * 初始化时间
 */
void Widget::initCurrentTime()
{
    QDateTime curDateTime = QDateTime::currentDateTime();
    ui->lineEditTime->setText(curDateTime.toString("HH:mm:ss:zzz"));
    ui->lineEditDate->setText(curDateTime.toString("yyyy-MM-dd"));
    ui->lineEditDateTime->setText(curDateTime.toString("yyyy-MM-dd HH:mm:ss:zzz"));

    ui->timeEdit->setTime(curDateTime.time());
    ui->dateEdit->setDate(curDateTime.date());
    ui->dateTimeEdit->setDateTime(curDateTime);
}

/**
 * 日期时间
 */
void Widget::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    ui->lineEditDateTime->setText(dateTime.toString("yyyy-MM-dd HH:mm:ss:zzz"));
}


/**
 * 选择的日期
 */
void Widget::on_calendarWidget_selectionChanged()
{
    QDate localSelectedDate = ui->calendarWidget->selectedDate();
    ui->lineEditSelect->setText(localSelectedDate.toString("yyyy-MM-dd"));
}

/**
 * 定时器超时监听
 */
void Widget::on_timer_timeout()
{
    QTime curTime = QTime::currentTime();
    ui->lcdNumberHour->display(curTime.hour());
    ui->lcdNumberMin->display(curTime.minute());
    ui->lcdNumberSecond->display(curTime.second());

    int val = ui->progressBar->value();
    val++;
    if(val > 100){
        val = 0;
    }
    ui->progressBar->setValue(val);
    ui->labelProgress->setText(QString::number(val,10)+"%");

    qDebug() << "定时器： " << QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss:zzz");
}


void Widget::on_btnStart_clicked()
{

    int selectInterval = ui->spinBox->value();
    qDebug() << "选择的间隔时间： " << selectInterval;
    if(selectInterval < 0){
        selectInterval = 0;
        ui->spinBox->setValue(selectInterval);
    }else if (selectInterval > 100000){
        selectInterval = 100000;
        ui->spinBox->setValue(selectInterval);
    }
    fTimer->setInterval(selectInterval);
    fTimer->start();

    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
    ui->btnSetDate->setEnabled(false);
}


void Widget::on_btnStop_clicked()
{
    fTimer->stop();


    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);
    ui->btnSetDate->setEnabled(true);
}

