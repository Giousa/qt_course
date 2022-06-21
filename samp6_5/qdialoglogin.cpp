#include "qdialoglogin.h"
#include "ui_qdialoglogin.h"
#include <QSettings>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QInputEvent>
#include <QPixmap>
#include <QIcon>
#include <QtDebug>


QDialogLogin::QDialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDialogLogin)
{
    ui->setupUi(this);

//    QIcon icon(":/images/images/back.jpg");

    QPixmap pixmap;
    pixmap.load(":/images/images/back.jpg");
//    ui->label->setPixmap(pixmap);
//    ui->lineEditPasswrod->setEchoMode(QLineEdit::Password);
    this->setAttribute(Qt::WA_DeleteOnClose);
//    this->setWindowFlags(Qt::SplashScreen);
//    this->setWindowFlags(Qt::FramelessWindowHint);
    readSettings();
}

QDialogLogin::~QDialogLogin()
{
    qDebug() << "登录框，删除";
    delete ui;
}

void QDialogLogin::readSettings()
{
    QString organization = "WWB-QT";
    QString appName = "samp6_5";
    QSettings settings(organization,appName);

    bool saved = settings.value("saved",false).toBool();
    m_user = settings.value("username","root").toString();
    QString defaultPassword = encrypt("123456");
    m_pswd = settings.value("password",defaultPassword).toString();
    if(saved){
        ui->lineEditUsername->setText(m_user);
    }
    ui->checkBoxUsername->setChecked(saved);

    qDebug() << "saved = " << saved << ",username = " << m_user;

}

void QDialogLogin::writeSettings()
{
      QSettings settings("WWB-QT","samp6_5");
      settings.setValue("username",m_user);
      settings.setValue("password",m_pswd);
      settings.setValue("saved",ui->checkBoxUsername->isChecked());

}

QString QDialogLogin::encrypt(const QString &str)
{
    QByteArray btArry;
    btArry.append(str);
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(btArry);
    QByteArray resultArray = hash.result();
    return resultArray.toHex();
}

void QDialogLogin::on_btnConfirm_clicked()
{
    QString username = ui->lineEditUsername->text().trimmed();
    QString password = ui->lineEditPasswrod->text().trimmed();
    QString encryptPswd = encrypt(password);
    if(username == m_user && encryptPswd == m_pswd){
        writeSettings();
        this->accept();
    }else{
        m_tryCount++;
        if(m_tryCount > 3){
            QMessageBox::critical(this,"错误","输入次数过多，强行退出");
            this->reject();
        }else{
            QMessageBox::warning(this,"错误提示","用户名或密码错误");
        }

    }
}



void QDialogLogin::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_moving = true;
        m_lastPos = event->globalPos() - pos();
    }
    return QDialog::mousePressEvent(event);
}

void QDialogLogin::mouseMoveEvent(QMouseEvent *event)
{
    if(m_moving && (event->button() == Qt::LeftButton) &&(event->globalPos() - m_lastPos).manhattanLength() > QApplication::startDragDistance()){
        move(event->globalPos() - m_lastPos);
        m_lastPos = event->globalPos() - pos();
    }
    return QDialog::mouseMoveEvent(event);
}

void QDialogLogin::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_moving = false;
}


