#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    LabFileName = new QLabel("");
//    ui->statusbar->addWidget(LabFileName);
//    this->setCentralWidget(ui->scrollArea);
//    iniTree();

    LabFileName=new QLabel("");
    ui->statusbar->addWidget(LabFileName);

    this->setCentralWidget(ui->scrollArea); //设置中心布局组件
    iniTree();//初始化目录树
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniTree()
{
    qDebug() << "初始化tree";
//    QString dataStr = "";
//    ui->treeWidget->clear();
//    QIcon icon;
//    icon.addFile(":/images/icons/15.ico");

//    /**
//     * 添加节点-根
//     */
//    QTreeWidgetItem *item = new QTreeWidgetItem(MainWindow::itTopItem);
//    item->setIcon(MainWindow::colItem,icon);
//    item->setText(MainWindow::colItem,"图片文件");
//    item->setText(MainWindow::colItemType,"type=itTopItem");
//    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
//    item->setCheckState(colItem,Qt::Checked);
//    item->setData(MainWindow::colItem,Qt::UserRole,QVariant(dataStr));
//    ui->treeWidget->addTopLevelItem(item);

    QString    dataStr=""; // Item的Data 存储的string

    ui->treeWidget->clear();//清除目录树所有节点
    QIcon   icon;
    icon.addFile(":/images/icons/15.ico"); //设置ICON的图标

    QTreeWidgetItem*  item=new QTreeWidgetItem(MainWindow::itTopItem); //新建节点时设定类型为 itTopItem
    item->setIcon(MainWindow::colItem,icon); //设置第1列的图标
    item->setText(MainWindow::colItem,"图片文件"); //设置第1列的文字
    item->setText(MainWindow::colItemType,"type=itTopItem");  //设置第2列的文字
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    item->setCheckState(colItem,Qt::Checked);//设置为选中

    item->setData(MainWindow::colItem,Qt::UserRole,QVariant(dataStr)); //设置节点第1列的Qt::UserRole的Data
    ui->treeWidget->addTopLevelItem(item);//添加顶层节点
}

/**
 * 添加节点-组
 */
void MainWindow::addFolderItem(QTreeWidgetItem *parItem, QString dirName)
{
//    QIcon icon(":/images/icons/open3.bmp");
//    QString NodeText = getFinalFolderName(dirName);

//    QTreeWidgetItem *item;
//    item = new QTreeWidgetItem(MainWindow::itGroupItem);
//    item->setIcon(colItem,icon);
//    item->setText(colItem,NodeText);
//    item->setText(colItemType,"type=itGroupItem");
//    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
//    item->setCheckState(colItem,Qt::Checked);
//    item->setData(MainWindow::colItem,Qt::UserRole,QVariant(dirName));
//    parItem->addChild(item);

    QIcon   icon(":/images/icons/open3.bmp");
    QString NodeText=getFinalFolderName(dirName); //从一个完整目录名称里，获得最后的文件夹名称

    QTreeWidgetItem *item; //节点
    item=new QTreeWidgetItem(MainWindow::itGroupItem); //新建节点, 设定type为 itGroupItem
    item->setIcon(colItem,icon); //设置图标
    item->setText(colItem,NodeText); //最后的文件夹名称，第1列
    item->setText(colItemType,"type=itGroupItem"); //完整目录名称，第2列
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate); //设置节点选项
    item->setCheckState(colItem,Qt::Checked); //节点选中
    item->setData(colItem,Qt::UserRole,QVariant(dirName)); //设置角色为Qt::UserRole的Data,存储完整目录名称

    parItem->addChild(item); //在父节点下面添加子节点
}

QString MainWindow::getFinalFolderName(const QString &fullPathName)
{
    qDebug() << "获取最终文件夹名称 fullPathName :  " << fullPathName;
//    int cnt = fullPathName.length();
//    int i = fullPathName.lastIndexOf("/");
//    QString str = fullPathName.right(cnt-i-1);

    int cnt=fullPathName.length(); //字符串长度
    int i=fullPathName.lastIndexOf("/");//  最后一次出现的位置
    QString str=fullPathName.right(cnt-i-1); //获得最后的文件夹的名称

    qDebug() << "获取最终文件夹名称 getFinalFolderName：" << str;
    return str;
}

/**
 * 添加节点-图片
 */
void MainWindow::addImageItem(QTreeWidgetItem *parItem, QString aFilename)
{
//    QIcon icon(":/images/icons/31.ico");
//    QString NodeText = getFinalFolderName(aFilename);

//    QTreeWidgetItem *item;
//    item = new QTreeWidgetItem(MainWindow::itImageItem);
//    item->setIcon(colItem,icon);
//    item->setText(colItem,NodeText);
//    item->setText(colItemType,"type=itImageItem");
//    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
//    item->setCheckState(colItem,Qt::Checked);
//    item->setData(MainWindow::colItem,Qt::UserRole,QVariant(aFilename));
//    parItem->addChild(item);

    QIcon   icon(":/images/icons/31.ico");//ICON的图标
    QString NodeText=getFinalFolderName(aFilename); //获得最后的文件名称

    QTreeWidgetItem *item; //节点
    item=new QTreeWidgetItem(MainWindow::itImageItem); //新建节点时设定类型为 itImageItem
    item->setIcon(colItem,icon); //设置图标
    item->setText(colItem,NodeText); //最后的文件夹名称
    item->setText(colItemType,"type=itImageItem"); //完整目录名称
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate); //设置节点选项
    item->setCheckState(colItem,Qt::Checked); //节点选中

    item->setData(colItem,Qt::UserRole,QVariant(aFilename)); //设置节点Qt::UserRole的Data,存储完整文件名称

    parItem->addChild(item); //在父节点下面添加子节点
}

/**
 * 展示图片
 */
void MainWindow::displayImage(QTreeWidgetItem *item)
{
    QString fileName = item->data(colItem,Qt::UserRole).toString();
    qDebug() << "展示图片文件名称： " << fileName;
    LabFileName->setText(fileName);
    curPixmap.load(fileName);
    //自动适应高度
    on_actZoomFitH_triggered();
}

/**
 * 更改节点
 */
void MainWindow::changeItemCaption(QTreeWidgetItem *item)
{
    //节点标题前，加上"*"
    QString str = "*" + item->text(colItem);
    item->setText(colItem,str);
    if(item->childCount() <= 0){
        return;
    }
    for (int i = 0;i < item->childCount() ;i++ ) {
        changeItemCaption(item->child(i));
    }
}


void MainWindow::on_actAddFolder_triggered()
{
    //选择目录
    QString dir = QFileDialog::getExistingDirectory();
    if(dir.isEmpty()){
        qDebug() << "选择目录为空！";
        return;
    }
    QTreeWidgetItem *parItem = ui->treeWidget->currentItem();
    addFolderItem(parItem,dir);

}


void MainWindow::on_actAddFiles_triggered()
{
    QStringList files = QFileDialog::getOpenFileNames(this,"选择一个或多个文件~~~","","Images(*.jpg)");

    if(files.isEmpty()){
        qDebug() << "选择文件为空！";
        return;
    }

    QTreeWidgetItem *parItem,*item;
    item = ui->treeWidget->currentItem();
    if(item->type() == itImageItem){
        //图片节点
        parItem = item->parent();
    }else{
        parItem = item;
    }

    for (int i = 0;i < files.size() ;++i ) {
        QString aFilename = files.at(i);
        addImageItem(parItem,aFilename);
    }

}


void MainWindow::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    Q_UNUSED(previous);

    if(current == NULL){
        return;
    }
    int var = current->type();
    switch (var) {
        case itTopItem:
            ui->actAddFolder->setEnabled(true);
            ui->actAddFiles->setEnabled(true);
            ui->actDeleteItem->setEnabled(false);
            break;

        case itGroupItem:
            ui->actAddFolder->setEnabled(true);
            ui->actAddFiles->setEnabled(true);
            ui->actDeleteItem->setEnabled(true);
            break;

        case itImageItem:
            ui->actAddFolder->setEnabled(false);
            ui->actAddFiles->setEnabled(true);
            ui->actDeleteItem->setEnabled(false);
            displayImage(current);
            break;
    }
}


void MainWindow::on_actDeleteItem_triggered()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();
    QTreeWidgetItem *parItem = item->parent();
    parItem->removeChild(item);
    delete item;
}


void MainWindow::on_actScanItems_triggered()
{
    for (int i = 0; i < ui->treeWidget->topLevelItemCount() ;i++ ) {
        QTreeWidgetItem *item = ui->treeWidget->topLevelItem(i);
        changeItemCaption(item);
    }
}


void MainWindow::on_actZoomFitH_triggered()
{
    int H = ui->scrollArea->height();
    int realH = curPixmap.height();
    pixRatio = float(H)/realH;
    QPixmap pix = curPixmap.scaledToHeight(H-30);
    ui->labPicture->setPixmap(pix);
}


void MainWindow::on_actZoomIn_triggered()
{
    pixRatio = pixRatio * 1.2;
    int w = pixRatio*curPixmap.width();
    int h = pixRatio*curPixmap.height();
    QPixmap pix = curPixmap.scaled(w,h);
    ui->labPicture->setPixmap(pix);
}


void MainWindow::on_actZoomRealSize_triggered()
{
    pixRatio = 1;
    ui->labPicture->setPixmap(curPixmap);
}


void MainWindow::on_actDockVisible_toggled(bool arg1)
{
    ui->dockWidget_2->setVisible(arg1);
}



void MainWindow::on_actDockFloat_triggered(bool checked)
{
    ui->dockWidget_2->setFloating(checked);
}



void MainWindow::on_dockWidget_2_visibilityChanged(bool visible)
{
    ui->actDockVisible->setChecked(visible);
}


void MainWindow::on_dockWidget_2_topLevelChanged(bool topLevel)
{
    ui->actDockFloat->setChecked(topLevel);
}

