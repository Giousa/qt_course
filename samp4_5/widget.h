#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTime>
#include <QTimer>

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
    void on_btnGet_clicked();

    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_calendarWidget_selectionChanged();

    void on_timer_timeout();

    void on_btnStart_clicked();

    void on_btnStop_clicked();

private:
    Ui::Widget *ui;

    QTimer *fTimer;

    QTime fTimeCounter;

    void initCurrentTime();
};
#endif // WIDGET_H
