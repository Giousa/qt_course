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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
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
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labPicture;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_4;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(759, 521);
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icons/418.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomIn->setIcon(icon2);
        actZoomOut = new QAction(MainWindow);
        actZoomOut->setObjectName(QString::fromUtf8("actZoomOut"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icons/416.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomOut->setIcon(icon3);
        actZoomRealSize = new QAction(MainWindow);
        actZoomRealSize->setObjectName(QString::fromUtf8("actZoomRealSize"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/icons/414.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomRealSize->setIcon(icon4);
        actZoomFitW = new QAction(MainWindow);
        actZoomFitW->setObjectName(QString::fromUtf8("actZoomFitW"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/icons/424.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomFitW->setIcon(icon5);
        actDeleteItem = new QAction(MainWindow);
        actDeleteItem->setObjectName(QString::fromUtf8("actDeleteItem"));
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
        actDockVisible->setIcon(icon4);
        actDockFloat = new QAction(MainWindow);
        actDockFloat->setObjectName(QString::fromUtf8("actDockFloat"));
        actDockFloat->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/icons/814.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDockFloat->setIcon(icon10);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 452, 386));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labPicture = new QLabel(scrollAreaWidgetContents_2);
        labPicture->setObjectName(QString::fromUtf8("labPicture"));
        labPicture->setScaledContents(false);
        labPicture->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labPicture);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_3->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 759, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy);
        toolBar->setLayoutDirection(Qt::LeftToRight);
        toolBar->setAllowedAreas(Qt::AllToolBarAreas);
        toolBar->setOrientation(Qt::Horizontal);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidget_2->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        horizontalLayout = new QHBoxLayout(dockWidgetContents_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeWidget = new QTreeWidget(dockWidgetContents_4);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/icons/15.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/icons/folder1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/icons/31.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem1->setIcon(0, icon11);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem2->setIcon(0, icon12);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem2);
        __qtreewidgetitem3->setIcon(0, icon13);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem5->setIcon(1, icon13);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        horizontalLayout->addWidget(treeWidget);

        dockWidget_2->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget_2);

        toolBar->addAction(actAddFolder);
        toolBar->addAction(actAddFiles);
        toolBar->addAction(actDeleteItem);
        toolBar->addAction(actScanItems);
        toolBar->addSeparator();
        toolBar->addAction(actZoomIn);
        toolBar->addAction(actZoomOut);
        toolBar->addAction(actZoomRealSize);
        toolBar->addAction(actZoomFitW);
        toolBar->addAction(actZoomFitH);
        toolBar->addSeparator();
        toolBar->addAction(actDockVisible);
        toolBar->addAction(actDockFloat);
        toolBar->addSeparator();
        toolBar->addAction(actQuit);

        retranslateUi(MainWindow);
        QObject::connect(actQuit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actAddFolder->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\233\256\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        actAddFolder->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\233\256\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        actAddFiles->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        actAddFiles->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomIn->setText(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247", nullptr));
#if QT_CONFIG(tooltip)
        actZoomIn->setToolTip(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247\345\233\276\347\211\207", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomOut->setText(QCoreApplication::translate("MainWindow", "\347\274\251\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        actZoomOut->setToolTip(QCoreApplication::translate("MainWindow", "\347\274\251\345\260\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomRealSize->setText(QCoreApplication::translate("MainWindow", "\345\256\236\351\231\205\345\244\247\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        actZoomRealSize->setToolTip(QCoreApplication::translate("MainWindow", "\345\256\236\351\231\205\345\244\247\345\260\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomFitW->setText(QCoreApplication::translate("MainWindow", "\351\200\202\345\220\210\345\256\275\345\272\246", nullptr));
        actDeleteItem->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\212\202\347\202\271", nullptr));
        actQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actZoomFitH->setText(QCoreApplication::translate("MainWindow", "\351\200\202\345\220\210\351\253\230\345\272\246", nullptr));
        actScanItems->setText(QCoreApplication::translate("MainWindow", "\351\201\215\345\216\206\350\212\202\347\202\271", nullptr));
        actDockVisible->setText(QCoreApplication::translate("MainWindow", "\347\252\227\344\275\223\345\217\257\350\247\201", nullptr));
        actDockFloat->setText(QCoreApplication::translate("MainWindow", "\347\252\227\344\275\223\346\265\256\345\212\250", nullptr));
        labPicture->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "\350\212\202\347\202\271\347\261\273\345\236\213", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\350\212\202\347\202\271", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\346\226\207\344\273\266", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "\345\210\206\347\273\204\350\212\202\347\202\271", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\350\212\202\347\202\271", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("MainWindow", "\345\210\206\347\273\2042", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem4->child(0);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("MainWindow", "\345\233\276\347\211\2072", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
