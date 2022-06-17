#include "widget.h"
#include "ui_widget.h"
#include <QCoreApplication>
#include <QDir>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>

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

//选择打开一个文件
void Widget::on_btnOpenSingleFile_clicked()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "选择一个文件";
    QString filter = "文本文件(*.txt);;图片文件(*.jpg *.gif *.jpeg);;所有文件(*.*)";
    QString aFileName = QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
    if(aFileName.isEmpty()){
       qDebug() << "选择一个文件: 选择为空！";
       return;
    }

    ui->plainTextEdit->appendPlainText(aFileName);
}

//选择打开多个文件
void Widget::on_btnOpenMultyFile_clicked()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "选择多个文件";
    QString filter = "文本文件(*.txt);;图片文件(*.jpg *.gif *.jpeg);;所有文件(*.*)";
    QStringList fileList = QFileDialog::getOpenFileNames(this,dlgTitle,curPath,filter);
    if(fileList.count() == 0){
        qDebug() << "选择多个文件：选择为空！";
        return;
    }
    for (int i = 0; i< fileList.count() ;i++ ) {
        ui->plainTextEdit->appendPlainText(fileList.at(i));
    }
}


//选择已有目录
void Widget::on_btnSelectExistDir_clicked()
{
    QString curPath = QCoreApplication::applicationDirPath();
    QString dlgTitle = "选择一个目录";
    QString existingDirectory = QFileDialog::getExistingDirectory(this,dlgTitle,curPath,QFileDialog::ShowDirsOnly);
    if(existingDirectory.isEmpty()){
        qDebug() << "选择一个目录：选择为空！";
        return;
    }
    ui->plainTextEdit->appendPlainText(existingDirectory);
}

//保存文件
void Widget::on_btnSaveFile_clicked()
{
    QString curPath = QCoreApplication::applicationDirPath();
    QString dlgTitle = "保存文件";
    QString filter = "文本文件(*.txt);;图片文件(*.jpg *.gif *.jpeg);;所有文件(*.*)";
    QString fileName = QFileDialog::getSaveFileName(this,dlgTitle,curPath,filter);
    if(fileName.isEmpty()){
        qDebug() << "保存文件失败！";
        return;
    }

    ui->plainTextEdit->appendPlainText(fileName);
}


void Widget::on_btnSelectColor_clicked()
{
    QPalette pal = ui->plainTextEdit->palette();
    QColor iniColor = pal.color(QPalette::Text);
    QColor color = QColorDialog::getColor(iniColor,this,"选择你喜欢的颜色");
    if(!color.isValid()){
        qDebug() << "取消选择颜色";
        return;
    }

    pal.setColor(QPalette::Text,color);
    ui->plainTextEdit->setPalette(pal);
}


void Widget::on_btnSelectFont_clicked()
{
    QFont iniFont = ui->plainTextEdit->font();
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok,iniFont);
    if(!ok){
        qDebug() << "选择字体大小失败";
        return;
    }

    ui->plainTextEdit->setFont(font);
}


void Widget::on_btnInputStr_clicked()
{
    QString title = "输入字符串对话框";
    QString textHide = "请输入文件名";
    QString defaultInput = "新建文件.txt";
    QLineEdit::EchoMode echoMode =  QLineEdit::Normal;
    bool ok = false;
    QString text = QInputDialog::getText(this,title,textHide,echoMode,defaultInput,&ok);
    if(!ok || text.isEmpty()){
        qDebug() << "输入失败";
        return;
    }

    ui->plainTextEdit->appendPlainText(text);
}


void Widget::on_btnInputNum_clicked()
{
    int defaultValue = ui->plainTextEdit->font().pointSize();
    int minValue = 6,maxValue = 50,stepValue = 2;
    bool ok = false;
    int realValue = QInputDialog::getInt(this,"这个是标题","这个是文本描述",defaultValue,minValue,maxValue,stepValue,&ok);
    if(!ok){
        qDebug() << "输入数字失败";
        return;
    }

    QFont font = ui->plainTextEdit->font();
    font.setPointSize(realValue);
    ui->plainTextEdit->setFont(font);
}


void Widget::on_btnInputFloat_clicked()
{
    float defaultValue = 3.13,minValue = 1.01,maxValue = 10.00;
    int decimals = 2;
    bool ok = false;
    float num = QInputDialog::getDouble(this,"这个是标题","描述内容",defaultValue,minValue,maxValue,decimals,&ok);
    if(!ok){
        qDebug() << "输入数字失败";
        return;
    }

    ui->plainTextEdit->appendPlainText(QString::asprintf("选择了一个浮点数：%.2f",num));

}


void Widget::on_btnInputItem_clicked()
{
    QStringList items = {"a","b","c","d","e","f"};

    int curIndex = 2;
    bool editable = true;
    bool ok = false;

    QString item = QInputDialog::getItem(this,"这个是标题","这个是描述",items,curIndex,editable,&ok);
    if(!ok || item.isEmpty()){
        qDebug() << "未做选择";
        return;
    }

    ui->plainTextEdit->appendPlainText(item);
}


void Widget::on_btnMsgInfo_clicked()
{
    QMessageBox::information(this,"这个是标题","这个是描述",QMessageBox::Ok,QMessageBox::NoButton);
}


void Widget::on_btnMsgWarn_clicked()
{
    QMessageBox::warning(this,"这个是标题","这个是描述",QMessageBox::Ok,QMessageBox::NoButton);
}


void Widget::on_btnMsgCirtical_clicked()
{
//    QMessageBox::critical(this,"这个是标题","这个是描述",QMessageBox::Ok,QMessageBox::NoButton);
//    ==
    QMessageBox::critical(this,"这个是标题","这个是描述");
}


void Widget::on_btnMsgAbout_clicked()
{
    QMessageBox::about(this,"这个是标题","这个是描述");
}


void Widget::on_btnMsgQues_clicked()
{
    int result = QMessageBox::question(this,"这是标题","这个是描述",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,QMessageBox::NoButton);
    switch (result) {
        case QMessageBox::Yes:
        ui->plainTextEdit->appendPlainText("选择了：Yes");
        break;

        case QMessageBox::No:
        ui->plainTextEdit->appendPlainText("选择了：No");
        break;

        case QMessageBox::Cancel:
        ui->plainTextEdit->appendPlainText("选择了：Cancel");
        break;

        default:
        ui->plainTextEdit->appendPlainText("选择了：Default");
        break;
    }
}

