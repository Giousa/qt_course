#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_btnOpenSingleFile_clicked();

    void on_btnOpenMultyFile_clicked();

    void on_btnSelectExistDir_clicked();

    void on_btnSaveFile_clicked();

    void on_btnSelectColor_clicked();

    void on_btnSelectFont_clicked();

    void on_btnInputStr_clicked();

    void on_btnInputNum_clicked();

    void on_btnInputFloat_clicked();

    void on_btnInputItem_clicked();

    void on_btnMsgInfo_clicked();

    void on_btnMsgWarn_clicked();

    void on_btnMsgCirtical_clicked();

    void on_btnMsgAbout_clicked();

    void on_btnMsgQues_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
