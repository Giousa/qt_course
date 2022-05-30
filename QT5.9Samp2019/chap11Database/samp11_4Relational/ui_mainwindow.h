/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actOpenDB;
    QAction *actQuit;
    QAction *actRecAppend;
    QAction *actRecInsert;
    QAction *actSubmit;
    QAction *actRevert;
    QAction *actRecDelete;
    QAction *actFields;
    QWidget *centralWidget;
    QTableView *tableView;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(771, 473);
        QFont font;
        font.setPointSize(11);
        MainWindow->setFont(font);
        actOpenDB = new QAction(MainWindow);
        actOpenDB->setObjectName(QStringLiteral("actOpenDB"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/open3.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actOpenDB->setIcon(icon);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon1);
        actRecAppend = new QAction(MainWindow);
        actRecAppend->setObjectName(QStringLiteral("actRecAppend"));
        actRecAppend->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/316.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actRecAppend->setIcon(icon2);
        actRecInsert = new QAction(MainWindow);
        actRecInsert->setObjectName(QStringLiteral("actRecInsert"));
        actRecInsert->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/306.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actRecInsert->setIcon(icon3);
        actSubmit = new QAction(MainWindow);
        actSubmit->setObjectName(QStringLiteral("actSubmit"));
        actSubmit->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/images/save1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSubmit->setIcon(icon4);
        actRevert = new QAction(MainWindow);
        actRevert->setObjectName(QStringLiteral("actRevert"));
        actRevert->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/images/ubdo.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actRevert->setIcon(icon5);
        actRecDelete = new QAction(MainWindow);
        actRecDelete->setObjectName(QStringLiteral("actRecDelete"));
        actRecDelete->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/images/delete1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actRecDelete->setIcon(icon6);
        actFields = new QAction(MainWindow);
        actFields->setObjectName(QStringLiteral("actFields"));
        actFields->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/images/124.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFields->setIcon(icon7);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(60, 20, 431, 311));
        tableView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 771, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actOpenDB);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actRecAppend);
        mainToolBar->addAction(actRecInsert);
        mainToolBar->addAction(actRecDelete);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actSubmit);
        mainToolBar->addAction(actRevert);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actFields);
        mainToolBar->addAction(actQuit);

        retranslateUi(MainWindow);
        QObject::connect(actQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QSqlRelationalTableModel \347\232\204\344\275\277\347\224\250", Q_NULLPTR));
        actOpenDB->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actOpenDB->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\225\260\346\215\256\345\272\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actRecAppend->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actRecAppend->setToolTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\350\256\260\345\275\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actRecInsert->setText(QApplication::translate("MainWindow", "\346\217\222\345\205\245", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actRecInsert->setToolTip(QApplication::translate("MainWindow", "\346\217\222\345\205\245\350\256\260\345\275\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actSubmit->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSubmit->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\344\277\256\346\224\271", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actRevert->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actRevert->setToolTip(QApplication::translate("MainWindow", "\345\217\226\346\266\210\344\277\256\346\224\271", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actRecDelete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actRecDelete->setToolTip(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\256\260\345\275\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actFields->setText(QApplication::translate("MainWindow", "\345\255\227\346\256\265\345\210\227\350\241\250", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actFields->setToolTip(QApplication::translate("MainWindow", "\345\255\227\346\256\265\345\210\227\350\241\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
