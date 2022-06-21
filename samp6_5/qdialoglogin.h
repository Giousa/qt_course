#ifndef QDIALOGLOGIN_H
#define QDIALOGLOGIN_H

#include <QDialog>

namespace Ui {
class QDialogLogin;
}

class QDialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit QDialogLogin(QWidget *parent = nullptr);
    ~QDialogLogin();

private:
    Ui::QDialogLogin *ui;

    bool m_moving = false;
    QPoint m_lastPos;
    QString m_user = "root";
    QString m_pswd = "123456";
    int m_tryCount = 0;
    void readSettings();
    void writeSettings();
    QString encrypt(const QString& str);

protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private slots:
    void on_btnConfirm_clicked();
};

#endif // QDIALOGLOGIN_H
