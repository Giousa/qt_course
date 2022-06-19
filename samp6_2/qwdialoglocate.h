#ifndef QWDIALOGLOCATE_H
#define QWDIALOGLOCATE_H

#include <QDialog>

namespace Ui {
class QWDialogLocate;
}

class QWDialogLocate : public QDialog
{
    Q_OBJECT

public:
    explicit QWDialogLocate(QWidget *parent = nullptr);
    ~QWDialogLocate();

    void setSpinRange(int rowCount,int colCount);

    void setSpinValue(int rowNo,int colNo);

private slots:
    void on_btnSetText_clicked();

private:
    Ui::QWDialogLocate *ui;

    void closeEvent(QCloseEvent *event);
};

#endif // QWDIALOGLOCATE_H
