#include "qdicethread.h"
#include <QTime>
#include <QtDebug>
#include <QRandomGenerator>

QDiceThread::QDiceThread(QObject *parent) : QThread(parent)
{

}

void QDiceThread::diceBeagin()
{
    m_Paused = false;
    for(int i = 0;i < 10;i++){
        int randomV2 = QRandomGenerator::global()->bounded(1,7);
        qDebug() << "随机数测试： 序号 i = " << i << ",随机数 = " << randomV2;
    }


}

void QDiceThread::dicePause()
{
    m_Paused = true;
}

void QDiceThread::stopThread()
{
    m_stop = true;
}

int QDiceThread::diceValue()
{
    return m_diceValue ;
}

void QDiceThread::run()
{
    m_stop = false;
    m_seq = 0;
    while (!m_stop) {
        if(!m_Paused){

            mutex.lock();
            //获取随机数
            m_diceValue = (QRandomGenerator::global()->bounded(1,7) % 6)+1;
            m_seq++;

            mutex.unlock();
            emit newValue(m_seq,m_diceValue);

//            qDebug() << "run 线程ID： " << QThread::currentThreadId();
        }
        msleep(500);
    }
    quit();
}


bool QDiceThread::readValue(int *seq, int *dicValue)
{
    if(mutex.tryLock()){
        qDebug() << "tryLock 尝试加锁success，返回true！";
        *seq = m_seq;
        *dicValue = m_diceValue;
        mutex.unlock();
        return true;
    }else{
        qDebug() << "tryLock 尝试加锁fail，返回false！";
        return false;
    }
}
