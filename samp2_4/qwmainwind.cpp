#include "qwmainwind.h"
#include "ui_qwmainwind.h"
#include <QDebug>

QWMainWind::QWMainWind(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QWMainWind)
{
    ui->setupUi(this);

    initUI();

    initSignalSlots();
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

    //创建QSpinBox【设置字体大小的】类型组件，设置属性，添加到工具栏
    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->textEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);

    //创建一个QFontComboBox【字体设置的组件】类型组件，添加到工具栏
    comboFont = new QFontComboBox;

    //设置
    ui->toolBar->addWidget(new QLabel("字体大小:"));
    ui->toolBar->addWidget(spinFontSize);
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(new QLabel("字体:"));
    ui->toolBar->addWidget(comboFont);

    setCentralWidget(ui->textEdit);

}


/**
 * 设置粗体
 * 注意：若想使按钮的triggered(bool)的值有true，需要勾选Action的Checkable
 */
void QWMainWind::on_actFontBold_triggered(bool checked)
{
    qDebug() << "Bold_triggered... checked: " << checked;

    //改变选中样式
    QTextCharFormat fmt = ui->textEdit->currentCharFormat();
    if(checked){
        fmt.setFontWeight(QFont::Bold);
    }else{
        fmt.setFontWeight(QFont::Normal);
    }
    ui->textEdit->mergeCurrentCharFormat(fmt);

    //全部一起改变样式
//    QFont font = ui->textEdit->font();
//    font.setBold(checked);
//    ui->textEdit->setFont(font);
}


/**
 * 设置斜体
 * 注意：若想使按钮的triggered(bool)的值有true，需要勾选Action的Checkable
 */
void QWMainWind::on_actFontItalic_triggered(bool checked)
{
    qDebug() << "Italic_triggered... checked: " << checked;
//    QFont font = ui->textEdit->font();
//    font.setItalic(checked);
//    ui->textEdit->setFont(font);
    QTextCharFormat fmt = ui->textEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

/**
 * 设置下划线
 * 注意：若想使按钮的triggered(bool)的值有true，需要勾选Action的Checkable
 */
void QWMainWind::on_actFontUnder_triggered(bool checked)
{
    qDebug() << "Under_triggered... checked: " << checked;
//    QFont font = ui->textEdit->font();
//    font.setUnderline(checked);
//    ui->textEdit->setFont(font);

    QTextCharFormat fmt = ui->textEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}



/**
 * 存在可复制内容
 */
void QWMainWind::on_textEdit_copyAvailable(bool b)
{
    qDebug() << "copyAvailable... flag: " << b;
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->textEdit->canPaste());
}


/**
 * 选择的文字发生变化
 */
void QWMainWind::on_textEdit_selectionChanged()
{
    qDebug() << "selectionChanged...";
    QTextCharFormat fmt = ui->textEdit->currentCharFormat();
    ui->actFontBold->setChecked(fmt.font().bold());
    ui->actFontItalic->setChecked(fmt.fontItalic());
    ui->actFontUnder->setChecked(fmt.fontUnderline());
}


void QWMainWind::initSignalSlots()
{
    connect(spinFontSize,SIGNAL(valueChanged(int)),this,SLOT(on_spinBoxFontSize_valueChanged(int)));
    connect(comboFont,SIGNAL(currentFontChanged(const QString &)),this,SLOT(on_comboFont_currentIndexChanged(const QString &)));
}


void QWMainWind::on_comboFont_currentIndexChanged(const QString &arg1)
{
    qDebug() << "选择字体：：currentIndexChanged...";
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void QWMainWind::on_spinBoxFontSize_valueChanged(int aFontSize)
{
    qDebug() << "改变字体大小：：valueChanged...";
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize);
    ui->textEdit->mergeCurrentCharFormat(fmt);
    progressBar1->setValue(aFontSize);
}

