#ifndef QDICETHREAD_H
#define QDICETHREAD_H

#include <QThread>
#include <QMutex>

class QDiceThread : public QThread
{
    Q_OBJECT
public:
    explicit QDiceThread(QObject *parent = nullptr);

    void diceBeagin();

    void dicePause();

    void stopThread();

    int diceValue();

    bool readValue(int *seq,int *dicValue);

private:
    //投骰子次数序号
    int m_seq = 0;

    //骰子点数
    int m_diceValue;

    bool m_Paused = true;
    bool m_stop = false;

    QMutex mutex;

protected:
    void run();

signals:
    void newValue(int seq,int diceValue);

};

#endif // QDICETHREAD_H
