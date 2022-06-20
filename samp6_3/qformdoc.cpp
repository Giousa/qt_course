#include "qformdoc.h"
#include "ui_qformdoc.h"
#include <QToolBar>
#include <QVBoxLayout>
#include <QtDebug>


QFormDoc::QFormDoc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QFormDoc)
{
    ui->setupUi(this);

    QToolBar *toolBar = new QToolBar("文档",this);
    toolBar->addAction(ui->actOpen);
    toolBar->addAction(ui->actFont);
    toolBar->addSeparator();
    toolBar->addAction(ui->actCut);
    toolBar->addAction(ui->actCopy);
    toolBar->addAction(ui->actPaste);
    toolBar->addAction(ui->actUndo);
    toolBar->addAction(ui->actRedo);
    toolBar->addSeparator();
    toolBar->addAction(ui->actClose);
    toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(toolBar);
    layout->addWidget(ui->plainTextEdit);
    layout->setContentsMargins(2,2,2,2);
    layout->setSpacing(2);
    this->setLayout(layout);

}

QFormDoc::~QFormDoc()
{
    qDebug() << "QFormDoc框删除";
    delete ui;
}
