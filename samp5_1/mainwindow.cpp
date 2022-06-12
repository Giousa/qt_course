#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QFileSystemModel(this);

    //设置根目录
    model->setRootPath(QDir::currentPath());

    ui->treeView->setModel(model);
    ui->listView->setModel(model);
    ui->tableView->setModel(model);

    connect(ui->treeView,SIGNAL(cliecked(QModelIndex)),ui->listView,SLOT(setRootIndex(QModelIndex)));
    connect(ui->treeView,SIGNAL(cliecked(QModelIndex)),ui->tableView,SLOT(setRootIndex(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    qDebug() << "点击传递索引： index = " << index;
    ui->checkBox->setChecked(model->isDir(index));
    ui->labelPath->setText(model->filePath(index));
    ui->labelType->setText(model->type(index));
    ui->labelFileName->setText(model->fileName(index));
    int size = model->size(index)/1024;
    if(size < 1024){
        ui->labelSize->setText(QString::asprintf("%d KB",size));
    }else{
        ui->labelSize->setText(QString::asprintf("%.1f MB",size/1024.0));
    }
}

