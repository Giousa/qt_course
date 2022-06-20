#ifndef QFORMDOC_H
#define QFORMDOC_H

#include <QWidget>

namespace Ui {
class QFormDoc;
}

class QFormDoc : public QWidget
{
    Q_OBJECT

public:
    explicit QFormDoc(QWidget *parent = nullptr);
    ~QFormDoc();

private:
    Ui::QFormDoc *ui;
};

#endif // QFORMDOC_H
