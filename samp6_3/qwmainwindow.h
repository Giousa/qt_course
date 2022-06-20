#ifndef QWMAINWINDOW_H
#define QWMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QWMainWindow; }
QT_END_NAMESPACE

class QWMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWMainWindow(QWidget *parent = nullptr);
    ~QWMainWindow();

private slots:
    void on_actWindowInsite_triggered();

    void on_actWidet_triggered();

private:
    Ui::QWMainWindow *ui;

    void paintEvent(QPaintEvent *e);

};
#endif // QWMAINWINDOW_H
