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

private slots:
    void on_actFontBold_triggered(bool checked);

    void on_actFontItalic_triggered(bool checked);

    void on_actFontUnder_triggered(bool checked);

    void on_textEdit_copyAvailable(bool b);

    void on_textEdit_selectionChanged();

    //自定义槽函数，选择字体
    void on_comboFont_currentIndexChanged(const QString &arg1);

    //自定义槽函数，改变字体大小
    void on_spinBoxFontSize_valueChanged(int aFontSize);

private:
    Ui::QWMainWind *ui;

    QLabel *fLabCurFile;
    QProgressBar *progressBar1;
    QSpinBox *spinFontSize;
    QFontComboBox *comboFont;

    void initUI();

    //初始化关联槽函数和信号
    void initSignalSlots();
};
#endif // QWMAINWIND_H
