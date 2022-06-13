#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStringListModel>

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
    void on_btnRecoverList_clicked();

    void on_btnAddItem_clicked();

    void on_btnInsertItem_clicked();

    void on_btnDeleteCurItem_clicked();

    void on_btnCLearList_clicked();

    void on_btnShowModel_clicked();

    void on_btnClearText_clicked();

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::Widget *ui;

    QStringListModel *theModel;
};
#endif // WIDGET_H
