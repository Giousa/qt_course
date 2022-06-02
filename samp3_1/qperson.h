#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>

class QPerson : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author","不笑猫")
    Q_CLASSINFO("company","UOG")
    Q_CLASSINFO("version","1.3.15")
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int score MEMBER m_score)


private:
    int m_age = 10;
    QString m_name;
    int m_score = 79;

public:
    explicit QPerson(QString fName,QObject *parent = nullptr);

    int age();
    void setAge(int value);
    void incAge();

signals:
    void ageChanged(int value);

};

#endif // QPERSON_H
