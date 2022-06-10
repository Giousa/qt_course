/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actAddFolder;
    QAction *actAddFiles;
    QAction *actZoomIn;
    QAction *actZoomOut;
    QAction *actZoomRealSize;
    QAction *actZoomFitW;
    QAction *actDeleteItem;
    QAction *actQuit;
    QAction *actZoomFitH;
    QAction *actScanItems;
    QAction *actDockVisible;
    QAction *actDockFloat;
    QWidget *centralWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *LabPicture;
    QMenuBar *menuBar;
    QMenu *menuPic;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeFiles;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(934, 500);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        actAddFolder = new QAction(MainWindow);
        actAddFolder->setObjectName(QString::fromUtf8("actAddFolder"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/open3.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAddFolder->setIcon(icon);
        actAddFiles = new QAction(MainWindow);
        actAddFiles->setObjectName(QString::fromUtf8("actAddFiles"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icons/824.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAddFiles->setIcon(icon1);
        actZoomIn = new QAction(MainWindow);
        actZoomIn->setObjectName(QString::fromUtf8("actZoomIn"));
        actZoomIn->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icons/418.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomIn->setIcon(icon2);
        actZoomOut = new QAction(MainWindow);
        actZoomOut->setObjectName(QString::fromUtf8("actZoomOut"));
        actZoomOut->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icons/416.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomOut->setIcon(icon3);
        actZoomRealSize = new QAction(MainWindow);
        actZoomRealSize->setObjectName(QString::fromUtf8("actZoomRealSize"));
        actZoomRealSize->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/icons/414.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomRealSize->setIcon(icon4);
        actZoomFitW = new QAction(MainWindow);
        actZoomFitW->setObjectName(QString::fromUtf8("actZoomFitW"));
        actZoomFitW->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/icons/424.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomFitW->setIcon(icon5);
        actDeleteItem = new QAction(MainWindow);
        actDeleteItem->setObjectName(QString::fromUtf8("actDeleteItem"));
        actDeleteItem->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/icons/delete1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDeleteItem->setIcon(icon6);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/icons/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon7);
        actZoomFitH = new QAction(MainWindow);
        actZoomFitH->setObjectName(QString::fromUtf8("actZoomFitH"));
        actZoomFitH->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/icons/426.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomFitH->setIcon(icon8);
        actScanItems = new QAction(MainWindow);
        actScanItems->setObjectName(QString::fromUtf8("actScanItems"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/icons/fold.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actScanItems->setIcon(icon9);
        actDockVisible = new QAction(MainWindow);
        actDockVisible->setObjectName(QString::fromUtf8("actDockVisible"));
        actDockVisible->setCheckable(true);
        actDockVisible->setChecked(true);
        actDockVisible->setIcon(icon4);
        actDockFloat = new QAction(MainWindow);
        actDockFloat->setObjectName(QString::fromUtf8("actDockFloat"));
        actDockFloat->setCheckable(true);
        actDockFloat->setChecked(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/icons/814.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDockFloat->setIcon(icon10);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(25, 25, 541, 361));
        scrollArea->setMinimumSize(QSize(200, 0));
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 539, 359));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        LabPicture = new QLabel(scrollAreaWidgetContents);
        LabPicture->setObjectName(QString::fromUtf8("LabPicture"));
        LabPicture->setScaledContents(false);
        LabPicture->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(LabPicture);

        scrollArea->setWidget(scrollAreaWidgetContents);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 934, 23));
        menuPic = new QMenu(menuBar);
        menuPic->setObjectName(QString::fromUtf8("menuPic"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(4, 2, 4, 2);
        treeFiles = new QTreeWidget(dockWidgetContents);
        QFont font1;
        font1.setBold(true);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(1, Qt::AlignLeading|Qt::AlignVCenter);
        __qtreewidgetitem->setFont(1, font1);
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        __qtreewidgetitem->setFont(0, font1);
        treeFiles->setHeaderItem(__qtreewidgetitem);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/icons/15.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/icons/31.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeFiles);
        __qtreewidgetitem1->setIcon(0, icon11);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem2->setIcon(0, icon);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem2);
        __qtreewidgetitem3->setIcon(0, icon12);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem5->setIcon(0, icon12);
        treeFiles->setObjectName(QString::fromUtf8("treeFiles"));
        treeFiles->setColumnCount(2);
        treeFiles->header()->setDefaultSectionSize(150);

        verticalLayout->addWidget(treeFiles);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

        menuBar->addAction(menuPic->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuPic->addAction(actAddFolder);
        menuPic->addAction(actAddFiles);
        menuPic->addAction(actDeleteItem);
        menuPic->addAction(actScanItems);
        menuPic->addSeparator();
        menuPic->addAction(actQuit);
        menuView->addAction(actZoomIn);
        menuView->addAction(actZoomOut);
        menuView->addAction(actZoomRealSize);
        menuView->addAction(actZoomFitW);
        menuView->addAction(actZoomFitH);
        mainToolBar->addAction(actAddFolder);
        mainToolBar->addAction(actAddFiles);
        mainToolBar->addAction(actDeleteItem);
        mainToolBar->addAction(actScanItems);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actZoomIn);
        mainToolBar->addAction(actZoomOut);
        mainToolBar->addAction(actZoomRealSize);
        mainToolBar->addAction(actZoomFitW);
        mainToolBar->addAction(actZoomFitH);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actDockFloat);
        mainToolBar->addAction(actDockVisible);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actQuit);

        retranslateUi(MainWindow);
        QObject::connect(actQuit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QTreeWidget\347\232\204\344\275\277\347\224\250", nullptr));
        actAddFolder->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\233\256\345\275\225...", nullptr));
#if QT_CONFIG(tooltip)
        actAddFolder->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\233\256\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actAddFolder->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actAddFiles->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266...", nullptr));
#if QT_CONFIG(tooltip)
        actAddFiles->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actAddFiles->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actZoomIn->setText(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247", nullptr));
#if QT_CONFIG(tooltip)
        actZoomIn->setToolTip(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247\345\233\276\347\211\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actZoomIn->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actZoomOut->setText(QCoreApplication::translate("MainWindow", "\347\274\251\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        actZoomOut->setToolTip(QCoreApplication::translate("MainWindow", "\347\274\251\345\260\217\345\233\276\347\211\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actZoomOut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actZoomRealSize->setText(QCoreApplication::translate("MainWindow", "\345\256\236\351\231\205\345\244\247\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        actZoomRealSize->setToolTip(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\345\256\236\351\231\205\345\244\247\345\260\217\346\230\276\347\244\272", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomFitW->setText(QCoreApplication::translate("MainWindow", "\351\200\202\345\220\210\345\256\275\345\272\246", nullptr));
#if QT_CONFIG(tooltip)
        actZoomFitW->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\202\345\220\210\345\256\275\345\272\246\346\230\276\347\244\272", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actZoomFitW->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actDeleteItem->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\212\202\347\202\271", nullptr));
#if QT_CONFIG(tooltip)
        actDeleteItem->setToolTip(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\212\202\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
        actQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actQuit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\346\234\254\347\263\273\347\273\237", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomFitH->setText(QCoreApplication::translate("MainWindow", "\351\200\202\345\220\210\351\253\230\345\272\246", nullptr));
#if QT_CONFIG(shortcut)
        actZoomFitH->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actScanItems->setText(QCoreApplication::translate("MainWindow", "\351\201\215\345\216\206\350\212\202\347\202\271", nullptr));
#if QT_CONFIG(tooltip)
        actScanItems->setToolTip(QCoreApplication::translate("MainWindow", "\351\201\215\345\216\206\350\212\202\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
        actDockVisible->setText(QCoreApplication::translate("MainWindow", "\347\252\227\344\275\223\345\217\257\350\247\201", nullptr));
#if QT_CONFIG(tooltip)
        actDockVisible->setToolTip(QCoreApplication::translate("MainWindow", "\347\252\227\344\275\223\345\217\257\350\247\201", nullptr));
#endif // QT_CONFIG(tooltip)
        actDockFloat->setText(QCoreApplication::translate("MainWindow", "\347\252\227\344\275\223\346\265\256\345\212\250", nullptr));
#if QT_CONFIG(tooltip)
        actDockFloat->setToolTip(QCoreApplication::translate("MainWindow", "\347\252\227\344\275\223\346\265\256\345\212\250", nullptr));
#endif // QT_CONFIG(tooltip)
        LabPicture->setText(QString());
        menuPic->setTitle(QCoreApplication::translate("MainWindow", "\347\233\256\345\275\225\346\240\221", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
        dockWidget->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\347\233\256\345\275\225\346\240\221", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeFiles->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "\350\212\202\347\202\271\347\261\273\345\236\213", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\350\212\202\347\202\271", nullptr));

        const bool __sortingEnabled = treeFiles->isSortingEnabled();
        treeFiles->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeFiles->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\346\226\207\344\273\266", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "\345\210\206\347\273\204\350\212\202\347\202\271", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\350\212\202\347\202\271", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("MainWindow", "\345\210\206\347\273\2042", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem4->child(0);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("MainWindow", "\345\233\276\347\211\2072", nullptr));
        treeFiles->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
