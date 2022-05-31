#include "qwmainwind.h"
#include "ui_qwmainwind.h"

QWMainWind::QWMainWind(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QWMainWind)
{
    ui->setupUi(this);

    initUI();
}

QWMainWind::~QWMainWind()
{
    delete ui;
}

void QWMainWind::initUI()
{
    //创建一个QLabel类型的组件，并将其添加到状态栏toolBar里面
    fLabCurFile = new QLabel;
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText("当前文件");
    ui->statusbar->addWidget(fLabCurFile);

    //创建一个QProgressBar类型的组件，并添加到状态栏
    progressBar1 = new QProgressBar;
    progressBar1->setMaximumWidth(200);
    progressBar1->setMinimum(5);
    progressBar1->setMaximum(50);
    progressBar1->setValue(ui->textEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar1);

    //创建QSpinBox类型组件，设置属性，添加到工具栏
    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->textEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);

    //创建一个QFontComboBox类型组件，添加到工具栏
    comboFont = new QFontComboBox;

    //设置
    ui->toolBar->addWidget(new QLabel("字体大小:"));
    ui->toolBar->addWidget(spinFontSize);
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(new QLabel("字体:"));
    ui->toolBar->addWidget(comboFont);

    setCentralWidget(ui->textEdit);

}

