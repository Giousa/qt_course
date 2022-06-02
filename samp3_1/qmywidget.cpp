#include "qmywidget.h"
#include "ui_qmywidget.h"
#include <QDebug>
#include <QMetaProperty>

QmyWidget::QmyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QmyWidget)
{
    ui->setupUi(this);

    boy = new QPerson("不笑猫");
    boy->setProperty("score",97);
    boy->setProperty("age",19);
    boy->setProperty("sex","Body");

    connect(boy,&QPerson::ageChanged,this,&QmyWidget::on_ageChanged);

     girl = new QPerson("博丽灵梦");
     girl->setProperty("score",59);
     girl->setProperty("age",13);
     girl->setProperty("sex","Girl");
     connect(girl,&QPerson::ageChanged,this,&QmyWidget::on_ageChanged);

     ui->spinBoxBody->setProperty("isBoy",true);
     ui->spinBoxGirl->setProperty("isBoy",false);

     connect(ui->spinBoxBody,SIGNAL(valueChanged(int)),this,SLOT(on_spin_valueChanged(int)));
     connect(ui->spinBoxGirl,SIGNAL(valueChanged(int)),this,SLOT(on_spin_valueChanged(int)));
}

QmyWidget::~QmyWidget()
{
    delete ui;
}

void QmyWidget::on_ageChanged(int value)
{
//    Q_UNUSED(value);
    qDebug() << "on_ageChanged";
    QPerson *person = qobject_cast<QPerson *>(sender());

    QString name = person->property("name").toString();
    QString sex = person->property("sex").toString();
//    int age = person->property("age").toInt();
    int age = person->age();
    qDebug() << "姓名：" << name << " 性别： " << sex << " 年龄： " << age;

    ui->textEdit->appendPlainText(name + "," + sex + QString::asprintf(",年龄=%d",age));

}

void QmyWidget::on_spin_valueChanged(int arg1)
{
    qDebug() << "on_spin_valueChanged";
    QSpinBox *spinbox = qobject_cast<QSpinBox *>(sender());
    bool isBoy = spinbox->property("isBoy").toBool();
    qDebug() << "是否男孩： " << isBoy;
    if(isBoy){
        boy->setAge(spinbox->value());
    }else{
        girl->setAge(spinbox->value());
    }
}


void QmyWidget::on_btnClassInfo_clicked()
{
    const QMetaObject *meta = boy->metaObject();
    ui->textEdit->clear();
    ui->textEdit->appendPlainText("===元对象信息===\n");
    ui->textEdit->appendPlainText(QString("类名称: %1\n").arg(meta->className()));

    ui->textEdit->appendPlainText("property");

    for(int i = meta->propertyOffset();i < meta->propertyCount(); i++){
         QMetaProperty prop =  meta->property(i);
         const char *propName = prop.name();
         QString propValue = boy->property(propName).toString();
         ui->textEdit->appendPlainText(QString("属性名称：%1，属性值：%2").arg(propName).arg(propValue));
    }

    ui->textEdit->appendPlainText("");
    ui->textEdit->appendPlainText("classInfo");

    for(int i = meta->classInfoOffset();i < meta->classInfoCount();i++){
        QMetaClassInfo classInfo = meta->classInfo(i);
        ui->textEdit->appendPlainText(QString("ClassInfo Name = %1,Value = %2").arg(classInfo.name()).arg(classInfo.value()));
    }

}

