#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qdicethread.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QDiceThread threadA;

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void onthreadA_started();
    void onthreadA_finished();
    void onthreadA_newValue(int seq,int diceValue);
    void on_btnRun_clicked();
    void on_btnStart_clicked();
    void on_btnPause_clicked();
    void on_btnEnd_clicked();
    void on_btnClear_clicked();
};
#endif // MAINWINDOW_H
