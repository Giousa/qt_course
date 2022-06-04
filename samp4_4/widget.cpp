#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->sliderRed,&QAbstractSlider::valueChanged,this,&Widget::on_sliderColor_changed);
    connect(ui->sliderGreen,&QAbstractSlider::valueChanged,this,&Widget::on_sliderColor_changed);
    connect(ui->sliderBlue,&QAbstractSlider::valueChanged,this,&Widget::on_sliderColor_changed);
    connect(ui->sliderAlpha,&QAbstractSlider::valueChanged,this,&Widget::on_sliderColor_changed);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_sliderColor_changed(int value)
{
    Q_UNUSED(value);
    QColor color;
    int r = ui->sliderRed->value();
    int g = ui->sliderGreen->value();
    int b = ui->sliderBlue->value();
    int a = ui->sliderAlpha->value();

    color.setRgb(r,g,b,a);
    QPalette pal = ui->colorTextEdit->palette();
    pal.setColor(QPalette::Base,color);
    ui->colorTextEdit->setPalette(pal);
}


void Widget::on_dial_valueChanged(int value)
{
    ui->lcdNumber->display(value);
}

