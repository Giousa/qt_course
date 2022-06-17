#ifndef QWDIALOGHEADERS_H
#define QWDIALOGHEADERS_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class QWDialogHeaders;
}

class QWDialogHeaders : public QDialog
{
    Q_OBJECT

public:
    explicit QWDialogHeaders(QWidget *parent = nullptr);
    ~QWDialogHeaders();

    void setHeaderList(QStringList &headers);

    QStringList getHeaderList();

private:
    Ui::QWDialogHeaders *ui;

    QStringListModel *model;
};

#endif // QWDIALOGHEADERS_H
