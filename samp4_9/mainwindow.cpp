#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initStatusBar();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//初始化底部
void MainWindow::initStatusBar()
{
    labCellIndex = new QLabel("当前单元格坐标：",this);
    labCellIndex->setMinimumWidth(250);
    labCellType = new QLabel("当前单元格类型：",this);
    labCellType->setMinimumWidth(200);
    labStudID = new QLabel("学生ID：",this);
    labStudID->setMinimumWidth(200);

    ui->statusbar->addWidget(labCellIndex);
    ui->statusbar->addWidget(labCellType);
    ui->statusbar->addWidget(labStudID);

    //初始化表格行数
    ui->tableWidget->setRowCount(ui->spinBoxRow->text().toInt());

}

//创建数据
void MainWindow::createItemARow(int rowNo, QString name, QString sex, QDate birth, QString nation, bool isPM, int score)
{
    qDebug() << "start:: 创建table 条目！！ rowNo = " << rowNo << ",name = " << name << ",score = " << score;

    QTableWidgetItem *item;
    QString str;
    uint studId = 20163900;

    //姓名
    item = new QTableWidgetItem(name,MainWindow::ctName);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    studId += rowNo;
    item->setData(Qt::UserRole,QVariant(studId));
    ui->tableWidget->setItem(rowNo,MainWindow::colName,item);

    //性别
    QIcon icon;
    if(sex == "男"){
        icon.addFile(":/images/icons/boy.icon");
    }else{
        icon.addFile(":/images/icons/girl.icon");
    }
     item = new QTableWidgetItem(sex,MainWindow::ctSex);
     item->setIcon(icon);
     item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
     ui->tableWidget->setItem(rowNo,MainWindow::colSex,item);

     //出生日期
     str = birth.toString("yyyy-MM-dd");
     item = new QTableWidgetItem(str,MainWindow::ctBirth);
     item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
     ui->tableWidget->setItem(rowNo,MainWindow::colBirthdy,item);

     //民族
     item = new QTableWidgetItem(nation,MainWindow::ctNation);
     item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
     ui->tableWidget->setItem(rowNo,MainWindow::colNation,item);

     //是否党员
     item = new QTableWidgetItem("党员",MainWindow::ctPartyM);
     item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
     if(isPM){
         item->setCheckState(Qt::Checked);
     }else{
         item->setCheckState(Qt::Unchecked);
     }
     item->setBackground(QBrush(Qt::yellow));
     ui->tableWidget->setItem(rowNo,MainWindow::colParyM,item);

     //分数
     str.setNum(score);
     item = new QTableWidgetItem(str,MainWindow::ctScore);
     item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
     ui->tableWidget->setItem(rowNo,MainWindow::colScore,item);
}


//设置头部
void MainWindow::on_btnSetHeader_clicked()
{
    QTableWidgetItem *headerItem;
    QStringList headerText;
    headerText << "姓 名" << "性 别" << "出生日期" << "民 族" << "是否党员" << "分 数";
    qDebug() << "headerText : " << headerText;
    ui->tableWidget->setColumnCount(headerText.count());
    for (int i = 0;i<ui->tableWidget->columnCount() ;i++ ) {
        headerItem = new QTableWidgetItem(headerText.at(i));
        QFont font = headerItem->font();
        font.setBold(true);
        font.setPointSize(16);
        headerItem->setFont(font);
        headerItem->setForeground(QBrush(Qt::red));
        ui->tableWidget->setHorizontalHeaderItem(i,headerItem);
    }


    //倘若不需要设置行表头样式的话，可以直接采用下面的方法
//    ui->tableWidget->setHorizontalHeaderLabels(headerText);
}


//初始化数据
void MainWindow::on_btnInitData_clicked()
{
    QString strName,strSex;
    bool isParty = false;
    QDate birth;
    birth.setDate(2001,4,7);
    //清除工作区，不清除表头
    ui->tableWidget->clearContents();
    //获取行数 注意：倘若默认设置是0的话，是不会显示的。
//    int rows = ui->spinBoxRow->text().toInt();
    int rows = ui->tableWidget->rowCount();
    qDebug() << "初始化表，rows = " << rows;
    for (int i = 0;i < rows ;i++ ) {
        strName = QString::asprintf("学生_%d",i);
        if(i %2 == 0){
            strSex = "男";
        }else{
            strSex = "女";
        }

        birth = birth.addDays(20);
        isParty = !isParty;

        createItemARow(i,strName,strSex,birth,"汉族",isParty,(i+58));
    }
}


//设置行数
void MainWindow::on_btnSetRow_clicked()
{
    ui->tableWidget->setRowCount(ui->spinBoxRow->text().toInt());
}

//表格数据变动监听
void MainWindow::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    QTableWidgetItem *item = ui->tableWidget->item(currentRow,currentColumn);
    if(item == NULL){
        return;
    }

    labCellIndex->setText(QString::asprintf("当前单元格坐标: %d 行, %d 列",currentRow,currentColumn));
    labCellType->setText(QString::asprintf("当前单元格类型: %d",item->type()));

    //第一列的item
    item = ui->tableWidget->item(currentRow,MainWindow::colName);
    int id = item->data(Qt::UserRole).toInt();
    labStudID->setText(QString::asprintf("学生ID: %d",id));
}

//选中当前添加
void MainWindow::on_btnInsertRow_clicked()
{
    int curRow = ui->tableWidget->currentRow();
    qDebug() << "当前行： " << curRow;
    ui->tableWidget->insertRow(curRow);
    createItemARow(curRow,"选中-新生","男",QDate::fromString("1990-01-12","yyyy-MM-dd"),"回族",true,45);
}


//尾部添加
void MainWindow::on_btnAddRow_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
    createItemARow(rowCount,"尾部-新生","女",QDate::fromString("2020-04-25","yyyy-MM-dd"),"维吾尔族",false,12);
}


//删除
void MainWindow::on_btnDeleteCurrentRow_clicked()
{
    int curRow = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(curRow);
}


//是否可编辑
void MainWindow::on_checkBoxEdit_clicked(bool checked)
{
    if(checked){
        ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
    }else{
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}

/**
 * 行表头是否可以显示
 *
 * 就是每一行的前面id
 */
void MainWindow::on_checkBoxRowHeader_clicked(bool checked)
{
    ui->tableWidget->horizontalHeader()->setVisible(checked);
}

/**
 * 列表头是否可以显示
 *
 * 就是表格上面的头部
 */
void MainWindow::on_checkBoxColumnHeader_clicked(bool checked)
{
    ui->tableWidget->verticalHeader()->setVisible(checked);
}

//间隔行底色
void MainWindow::on_checkBoxRowColor_clicked(bool checked)
{
    ui->tableWidget->setAlternatingRowColors(checked);
}

//行选择
void MainWindow::on_radioButtonRowSelect_clicked()
{
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}


//单元格选择
void MainWindow::on_radioButtonCellSelect_clicked()
{
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
}

//读取内容到文本
void MainWindow::on_btnReadRowToText_clicked()
{
    QString str;
    QTableWidgetItem *cellItem;

    ui->plainTextEdit->clear();
    for (int i = 0;i < ui->tableWidget->rowCount() ;i++ ) {
        str = QString::asprintf("第 %d 行： ",i+1);
        for (int j = 0;j < ui->tableWidget->columnCount() ;j++ ) {

            if(j == ui->tableWidget->columnCount() -2){
                cellItem = ui->tableWidget->item(i,colParyM);
                if(cellItem->checkState() == Qt::Checked){
                    str = str + "党员  ";
                }else{
                    str = str + "群众  ";
                }
            }else{
                cellItem = ui->tableWidget->item(i,j);
                str = str + cellItem->text() + "    ";
            }
        }

        ui->plainTextEdit->appendPlainText(str);
    }
}

