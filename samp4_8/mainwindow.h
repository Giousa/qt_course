#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actAddFolder_triggered();

    void on_actAddFiles_triggered();

    void on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

    void on_actDeleteItem_triggered();

    void on_actScanItems_triggered();

    void on_actZoomFitH_triggered();

    void on_actZoomIn_triggered();

    void on_actZoomRealSize_triggered();

    void on_actDockVisible_toggled(bool arg1);

    void on_actDockFloat_triggered(bool checked);

    void on_dockWidget_2_visibilityChanged(bool visible);

    void on_dockWidget_2_topLevelChanged(bool topLevel);

private:
    Ui::MainWindow *ui;

    enum treeItemType{itTopItem=1001,itGroupItem,itImageItem};
    enum treeColNum{colItem=0,colItemType=1};

    QLabel *LabFileName;
    QPixmap curPixmap;
    float pixRatio;

    void iniTree();
    void addFolderItem(QTreeWidgetItem *parItem,QString dirName);
    QString getFinalFolderName(const QString &fullPathName);
    void addImageItem(QTreeWidgetItem *parItem,QString aFilename);
    void displayImage(QTreeWidgetItem *item);
    void changeItemCaption(QTreeWidgetItem *item);

};
#endif // MAINWINDOW_H
