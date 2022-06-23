#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    connect(&threadA,SIGNAL(started()),this,SLOT(onthreadA_started()));
    connect(&threadA,&QDiceThread::started,this,&MainWindow::onthreadA_started);
    connect(&threadA,&QDiceThread::finished,this,&MainWindow::onthreadA_finished);
    connect(&threadA,&QDiceThread::newValue,this,&MainWindow::onthreadA_newValue);

    qDebug() << "MainWindow 线程ID： " << QThread::currentThreadId();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "closeEvent: 关闭 退出应用";
    if(threadA.isRunning()){
        qDebug() << "线程进行中，关闭线程！";
        threadA.stopThread();
        threadA.wait();
    }else{
        qDebug() << "线程未执行！";
    }

    event->accept();
}

void MainWindow::onthreadA_started()
{
    qDebug() << "线程开启！";
    ui->labelThreadStatus->setText("Thread状态：thread started");
}

void MainWindow::onthreadA_finished()
{
    qDebug() << "线程结束！";
    ui->labelThreadStatus->setText("Thread状态：thread finished");
}

void MainWindow::onthreadA_newValue(int seq, int diceValue)
{
    QString str = QString::asprintf("第 %d 次投骰子，点数为：%d",seq,diceValue);
    ui->plainTextEdit->appendPlainText(str);
    QPixmap pic;
    QString fileName = QString::asprintf(":/images/images/d%d.jpg",diceValue);
    pic.load(fileName);
    ui->labelPic->setPixmap(pic);

//    qDebug() << "onthreadA_newValue 线程ID： " << QThread::currentThreadId();
}


//启动线程
void MainWindow::on_btnRun_clicked()
{
    threadA.start();
    ui->btnRun->setEnabled(false);
    ui->btnStart->setEnabled(true);
    ui->btnPause->setEnabled(false);
    ui->btnEnd->setEnabled(true);
}

//开始线程
void MainWindow::on_btnStart_clicked()
{
    threadA.diceBeagin();
    ui->btnStart->setEnabled(false);
    ui->btnPause->setEnabled(true);
}

//暂停线程
void MainWindow::on_btnPause_clicked()
{
    threadA.dicePause();
    ui->btnStart->setEnabled(true);
    ui->btnPause->setEnabled(false);
}

//结束线程
void MainWindow::on_btnEnd_clicked()
{
    threadA.stopThread();
    threadA.wait();
    ui->btnRun->setEnabled(true);
    ui->btnStart->setEnabled(false);
    ui->btnPause->setEnabled(false);
    ui->btnEnd->setEnabled(false);
}

//清空文本
void MainWindow::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText(QString::asprintf("当前骰子数字：%d",threadA.diceValue()));
}
