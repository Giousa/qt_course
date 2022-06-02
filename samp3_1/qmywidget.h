#ifndef QMYWIDGET_H
#define QMYWIDGET_H

#include <QWidget>
#include "qperson.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QmyWidget; }
QT_END_NAMESPACE

class QmyWidget : public QWidget
{
    Q_OBJECT

public:
    QmyWidget(QWidget *parent = nullptr);
    ~QmyWidget();

private:
    Ui::QmyWidget *ui;

    QPerson *boy;
    QPerson *girl;

private slots:
    void on_ageChanged(int value);
    void on_spin_valueChanged(int arg1);


    void on_btnClassInfo_clicked();
};
#endif // QMYWIDGET_H
