/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStartThread;
    QPushButton *btnStopThread;
    QPushButton *btnClear;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *plainTextEdit;
    QLabel *LabPic;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabA;
    QLabel *LabB;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(502, 430);
        QFont font;
        font.setPointSize(10);
        Dialog->setFont(font);
        verticalLayout_2 = new QVBoxLayout(Dialog);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnStartThread = new QPushButton(groupBox);
        btnStartThread->setObjectName(QStringLiteral("btnStartThread"));

        horizontalLayout->addWidget(btnStartThread);

        btnStopThread = new QPushButton(groupBox);
        btnStopThread->setObjectName(QStringLiteral("btnStopThread"));
        btnStopThread->setEnabled(false);

        horizontalLayout->addWidget(btnStopThread);

        btnClear = new QPushButton(groupBox);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        horizontalLayout->addWidget(btnClear);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        horizontalLayout_3->addWidget(plainTextEdit);

        LabPic = new QLabel(groupBox);
        LabPic->setObjectName(QStringLiteral("LabPic"));
        LabPic->setMinimumSize(QSize(150, 0));
        LabPic->setPixmap(QPixmap(QString::fromUtf8(":/dice/images/d0.jpg")));

        horizontalLayout_3->addWidget(LabPic);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        LabA = new QLabel(groupBox);
        LabA->setObjectName(QStringLiteral("LabA"));

        horizontalLayout_2->addWidget(LabA);

        LabB = new QLabel(groupBox);
        LabB->setObjectName(QStringLiteral("LabB"));

        horizontalLayout_2->addWidget(LabB);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\345\244\232\347\272\277\347\250\213\357\274\214\344\275\277\347\224\250QWaitCondition", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Dialog", "\347\272\277\347\250\213", Q_NULLPTR));
        btnStartThread->setText(QApplication::translate("Dialog", "\345\220\257\345\212\250\347\272\277\347\250\213", Q_NULLPTR));
        btnStopThread->setText(QApplication::translate("Dialog", "\347\273\223\346\235\237\347\272\277\347\250\213", Q_NULLPTR));
        btnClear->setText(QApplication::translate("Dialog", "\346\270\205\347\251\272\346\226\207\346\234\254", Q_NULLPTR));
        LabPic->setText(QString());
        LabA->setText(QApplication::translate("Dialog", "Thread Producer\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        LabB->setText(QApplication::translate("Dialog", "Thread Consumer\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
