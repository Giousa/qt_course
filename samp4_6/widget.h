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
    void on_btnInitItems_clicked();

    void on_btnInitCitys_clicked();

    void on_comboBoxCity_currentIndexChanged(int index);

    void on_btnClearContent_clicked();

    void on_btnAddToBox_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
