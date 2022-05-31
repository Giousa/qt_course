#ifndef QWMAINWIND_H
#define QWMAINWIND_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QFontComboBox>


QT_BEGIN_NAMESPACE
namespace Ui { class QWMainWind; }
QT_END_NAMESPACE

class QWMainWind : public QMainWindow
{
    Q_OBJECT

public:
    QWMainWind(QWidget *parent = nullptr);
    ~QWMainWind();

private:
    Ui::QWMainWind *ui;

    QLabel *fLabCurFile;
    QProgressBar *progressBar1;
    QSpinBox *spinFontSize;
    QFontComboBox *comboFont;

    void initUI();
};
#endif // QWMAINWIND_H
