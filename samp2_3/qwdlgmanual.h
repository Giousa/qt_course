#ifndef QWDLGMANUAL_H
#define QWDLGMANUAL_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>

class QWDlgManual : public QDialog
{
    Q_OBJECT

public:
    QWDlgManual(QWidget *parent = nullptr);
    ~QWDlgManual();

private:
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;

    QRadioButton *rbBlack;
    QRadioButton *rbRed;
    QRadioButton *rbBlue;

    QPlainTextEdit *textEdit;

    QPushButton *btnConfrim;
    QPushButton *btnCancel;
    QPushButton *btnClose;

    void initUI();

    void initSignalSlote();

private slots:
    void onCheckBoxUnder(bool checked);
    void onCheckBoxItalic(bool checked);
    void onCheckBoxBold(bool checked);
    void setTextFontColor();



};
#endif // QWDLGMANUAL_H
