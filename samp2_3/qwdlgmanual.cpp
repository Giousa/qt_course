#include "qwdlgmanual.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QRadioButton>
#include <QPlainTextEdit>

QWDlgManual::QWDlgManual(QWidget *parent)
    : QDialog(parent)
{
    initUI();
    initSignalSlote();
    setWindowTitle("set window title!");
}

QWDlgManual::~QWDlgManual()
{
    qDebug() << "退出！";

}

void QWDlgManual::initUI()
{
    qDebug() << "开始初始化UI";

    //创建CheckBox
    chkBoxUnder = new QCheckBox(tr("下划线"));
    chkBoxItalic = new QCheckBox(tr("斜体"));
    chkBoxBold = new QCheckBox(tr("粗体"));

    //水平布局
    QHBoxLayout *Hlay1 = new QHBoxLayout();
    Hlay1->addWidget(chkBoxUnder);
    Hlay1->addWidget(chkBoxItalic);
    Hlay1->addWidget(chkBoxBold);


    //创建RadioButton
    rbBlack = new QRadioButton(tr("Black"));
    rbRed = new QRadioButton(tr("Red"));
    rbBlue = new QRadioButton(tr("Blue"));

    //水平布局
    QHBoxLayout *Hlay2 = new QHBoxLayout();
    Hlay2->addWidget(rbBlack);
    Hlay2->addWidget(rbRed);
    Hlay2->addWidget(rbBlue);

    //创建PushButton
    btnConfrim = new QPushButton(tr("确认"));
    btnCancel = new QPushButton(tr("取消"));
    btnClose = new QPushButton(tr("关闭"));

    //水平布局
    QHBoxLayout *Hlay3 = new QHBoxLayout();
    Hlay3->addWidget(btnConfrim);
    Hlay3->addWidget(btnCancel);
    Hlay3->addWidget(btnClose);

    //创建Plain Text Edit
    textEdit = new QPlainTextEdit();
    textEdit->setPlainText("Hello This is My Demo\n手写UI模式！\n");
    QFont editFont = textEdit->font();
    editFont.setPointSize(20);
    textEdit->setFont(editFont);

    //创建垂直布局
    QVBoxLayout *VLay = new QVBoxLayout();
    VLay->addLayout(Hlay1);
    VLay->addLayout(Hlay2);
    VLay->addLayout(Hlay3);
    VLay->addWidget(textEdit);

    //设置为主布局
    setLayout(VLay);

}

void QWDlgManual::initSignalSlote()
{
    //CheckBox 信号与槽
    connect(rbBlack,&QRadioButton::clicked,this,&QWDlgManual::setTextFontColor);
    connect(rbBlue,&QRadioButton::clicked,this,&QWDlgManual::setTextFontColor);
    connect(rbRed,&QRadioButton::clicked,this,&QWDlgManual::setTextFontColor);

    //RadioButton 信号与槽
    connect(chkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(onCheckBoxUnder(bool)));
    connect(chkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(onCheckBoxItalic(bool)));
    connect(chkBoxBold,SIGNAL(clicked(bool)),this,SLOT(onCheckBoxBold(bool)));


    //PushButton 信号与槽
    connect(btnConfrim,SIGNAL(clicked()),this,SLOT(accept()));
    connect(btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));

}

void QWDlgManual::onCheckBoxUnder(bool checked)
{
    QFont font = textEdit->font();
    font.setUnderline(checked);
    textEdit->setFont(font);
}

void QWDlgManual::onCheckBoxItalic(bool checked)
{
    QFont font = textEdit->font();
    font.setItalic(checked);
    textEdit->setFont(font);
}

void QWDlgManual::onCheckBoxBold(bool checked)
{
    QFont font = textEdit->font();
    font.setBold(checked);
    textEdit->setFont(font);
}

void QWDlgManual::setTextFontColor()
{
    QPalette plet = textEdit->palette();

    if(rbBlack->isChecked()){
        plet.setColor(QPalette::Text,Qt::black);
    }else if(rbBlue->isChecked()){
        plet.setColor(QPalette::Text,Qt::blue);
    }else if(rbRed->isChecked()){
        plet.setColor(QPalette::Text,Qt::red);
    }else{
        plet.setColor(QPalette::Text,Qt::black);
    }

    textEdit->setPalette(plet);
}

