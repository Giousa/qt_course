/********************************************************************************
** Form generated from reading UI file 'qwdialogpen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWDIALOGPEN_H
#define UI_QWDIALOGPEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_QWDialogPen
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinWidth;
    QLabel *label_3;
    QLabel *label_2;
    QComboBox *comboPenStyle;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnColor;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QDialog *QWDialogPen)
    {
        if (QWDialogPen->objectName().isEmpty())
            QWDialogPen->setObjectName(QStringLiteral("QWDialogPen"));
        QWDialogPen->resize(339, 163);
        QFont font;
        font.setPointSize(11);
        QWDialogPen->setFont(font);
        groupBox = new QGroupBox(QWDialogPen);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 231, 141));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        spinWidth = new QSpinBox(groupBox);
        spinWidth->setObjectName(QStringLiteral("spinWidth"));
        spinWidth->setMinimumSize(QSize(100, 0));
        spinWidth->setMinimum(1);
        spinWidth->setMaximum(100);

        gridLayout->addWidget(spinWidth, 2, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        comboPenStyle = new QComboBox(groupBox);
        comboPenStyle->setObjectName(QStringLiteral("comboPenStyle"));

        gridLayout->addWidget(comboPenStyle, 0, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        btnColor = new QPushButton(groupBox);
        btnColor->setObjectName(QStringLiteral("btnColor"));
        btnColor->setAutoFillBackground(false);
        btnColor->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 255);"));
        btnColor->setFlat(false);

        gridLayout->addWidget(btnColor, 4, 1, 1, 1);

        btnOK = new QPushButton(QWDialogPen);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setGeometry(QRect(250, 30, 75, 23));
        btnCancel = new QPushButton(QWDialogPen);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(250, 90, 75, 23));

        retranslateUi(QWDialogPen);
        QObject::connect(btnOK, SIGNAL(clicked()), QWDialogPen, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), QWDialogPen, SLOT(reject()));

        QMetaObject::connectSlotsByName(QWDialogPen);
    } // setupUi

    void retranslateUi(QDialog *QWDialogPen)
    {
        QWDialogPen->setWindowTitle(QApplication::translate("QWDialogPen", "QPen\345\261\236\346\200\247\350\256\276\347\275\256\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("QWDialogPen", "Pen\345\261\236\346\200\247\350\256\276\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("QWDialogPen", "\347\272\277 \345\236\213", Q_NULLPTR));
        label_3->setText(QApplication::translate("QWDialogPen", "\351\242\234 \350\211\262", Q_NULLPTR));
        label_2->setText(QApplication::translate("QWDialogPen", "\347\272\277 \345\256\275", Q_NULLPTR));
        btnColor->setText(QString());
        btnOK->setText(QApplication::translate("QWDialogPen", "\347\241\256 \345\256\232", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("QWDialogPen", "\345\217\226 \346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QWDialogPen: public Ui_QWDialogPen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWDIALOGPEN_H
