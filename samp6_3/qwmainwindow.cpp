#include "qwmainwindow.h"
#include "ui_qwmainwindow.h"
#include <QTabWidget>
#include <QPainter>
#include "qformdoc.h"
#include <QtDebug>

QWMainWindow::QWMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QWMainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->setVisible(false);
    ui->tabWidget->clear();
    ui->tabWidget->tabsClosable();

    this->setCentralWidget(ui->tabWidget);
    this->setWindowState(Qt::WindowMaximized);

}

QWMainWindow::~QWMainWindow()
{
    qDebug() << "主程序退出！！！";
    delete ui;
}

void QWMainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter painter(this);
    painter.drawPixmap(0,ui->toolBar->height(),this->width(),this->height() - ui->toolBar->height() - ui->statusbar->height(),QPixmap(":/images/images/back.jpg"));


}


//打开嵌入式widget
void QWMainWindow::on_actWindowInsite_triggered()
{
    QFormDoc *formDoc = new QFormDoc(this);
    formDoc->setAttribute(Qt::WA_DeleteOnClose);
    int cur = ui->tabWidget->addTab(formDoc,QString::asprintf("Doc %d",ui->tabWidget->count()));
    ui->tabWidget->setCurrentIndex(cur);
    ui->tabWidget->setVisible(true);

}

//独立widget窗口
void QWMainWindow::on_actWidet_triggered()
{
    QFormDoc *formDoc = new QFormDoc();
    formDoc->setAttribute(Qt::WA_DeleteOnClose);
    formDoc->setWindowTitle("基于QWidget窗体，无父窗口，关闭时删除");
    formDoc->setWindowFlag(Qt::Window,true);
    formDoc->setWindowOpacity(0.9);
    formDoc->show();
}
