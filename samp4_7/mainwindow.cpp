#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setActionsForButton();

    createSelectionPopMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setActionsForButton()
{
    ui->tBtnListIni->setDefaultAction(ui->actListIni);
    ui->tBtnListClear->setDefaultAction(ui->actListClear);
    ui->tBtnListInsert->setDefaultAction(ui->actListInsert);
    ui->tBtnListAppend->setDefaultAction(ui->actListAppend);
    ui->tBtnListDelete->setDefaultAction(ui->actListDelete);

    ui->tBtnSelAll->setDefaultAction(ui->actSelAll);
    ui->tBtnSelNone->setDefaultAction(ui->actSelNone);
    ui->tBtnSelInvs->setDefaultAction(ui->actSelInvs);
}

void MainWindow::createSelectionPopMenu()
{
    QMenu *menuSelection = new QMenu(this);
    menuSelection->addAction(ui->actSelAll);
    menuSelection->addAction(ui->actSelNone);
    menuSelection->addAction(ui->actSelInvs);

    ui->tBtnSelectItem->setPopupMode(QToolButton::MenuButtonPopup);
    ui->tBtnSelectItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tBtnSelectItem->setDefaultAction(ui->actSelPopMenu);
    ui->tBtnSelectItem->setMenu(menuSelection);

    QToolButton *aBtn = new QToolButton(this);
    aBtn->setPopupMode(QToolButton::InstantPopup);
    aBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    aBtn->setDefaultAction(ui->actSelPopMenu);
    aBtn->setMenu(menuSelection);
    ui->toolBar->addWidget(aBtn);

    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actQuit);

}



void MainWindow::on_actListIni_triggered()
{

    ui->listWidget->clear();
    QListWidgetItem *aItem;
    QIcon aIcon;
    aIcon.addFile(":/images/icons/check2.ico");
    bool chk = ui->checkBox->isChecked();

    for (int i = 0;i < 10 ; i++ ) {
        QString str = QString::asprintf("Item %d",i);
        aItem = new QListWidgetItem();
        aItem->setText(str);
        aItem->setIcon(aIcon);
        aItem->setCheckState(Qt::Checked);
        if(chk){
            aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        }else{
            aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        }
        ui->listWidget->addItem(aItem);
    }

}


void MainWindow::on_actListInsert_triggered()
{
    QIcon aIcon;
    aIcon.addFile(":/images/icons/check2.ico");
    bool chk = ui->checkBox->isChecked();
    QListWidgetItem *aItem = new QListWidgetItem("New Insert Item");
    aItem->setIcon(aIcon);
    aItem->setCheckState(Qt::Checked);
    if(chk){
        aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
    }else{
        aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
    }
    ui->listWidget->addItem(aItem);
}


void MainWindow::on_actListClear_triggered()
{
    ui->listWidget->clear();
}


void MainWindow::on_actListDelete_triggered()
{
    int row = ui->listWidget->currentRow();
    qDebug() << "选中的行： rows = " << row;
    QListWidgetItem *aItem = ui->listWidget->takeItem(row);
    delete aItem;
}


void MainWindow::on_actSelAll_triggered()
{
    int cnt = ui->listWidget->count();
    for (int i=0;i<cnt ;i++ ) {
        QListWidgetItem *aItem = ui->listWidget->item(i);
        aItem->setCheckState(Qt::Checked);
    }
}


void MainWindow::on_actSelNone_triggered()
{
    int cnt = ui->listWidget->count();
    for (int i=0;i<cnt ;i++ ) {
        QListWidgetItem *aItem = ui->listWidget->item(i);
        aItem->setCheckState(Qt::Unchecked);
    }
}


void MainWindow::on_actSelInvs_triggered()
{
    int cnt = ui->listWidget->count();
    for (int i=0;i<cnt ;i++ ) {
        QListWidgetItem *aItem = ui->listWidget->item(i);
//        aItem->setCheckState(Qt::PartiallyChecked);
        Qt::CheckState checkState = aItem->checkState();
        if(checkState == Qt::Checked){
            aItem->setCheckState(Qt::Unchecked);
        }else{
            aItem->setCheckState(Qt::Checked);
        }

    }
}


void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    QString str;
    if(current == NULL){
        qDebug() << "未选中条目";
        return;
    }

    if(previous == NULL){
        str = "当前项： " + current->text();
    }else{
        str = "当前项： "+ current->text() + ",前一项： " + previous->text();
    }
    ui->lineEdit->setText(str);
}



void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
    QMenu *menuList = new QMenu(this);
    menuList->addAction(ui->actListIni);
    menuList->addAction(ui->actListClear);
    menuList->addAction(ui->actListInsert);
    menuList->addSeparator();
    menuList->addAction(ui->actSelAll);
    menuList->addAction(ui->actSelNone);
    menuList->addAction(ui->actSelInvs);
    menuList->exec(QCursor::pos());

    delete menuList;
}

