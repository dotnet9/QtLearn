#ifndef TPERSON_H
#define TPERSON_H

#include <QObject>

class TPerson : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author", "Liu")
    Q_CLASSINFO("company", "HM")
    Q_CLASSINFO("version", "1.0.0")

    Q_PROPERTY(quint16 age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int score MEMBER m_score)

public:
    explicit TPerson(QString name, QObject *parent = nullptr);
    ~TPerson();
    int age();
    void setAge(quint16 ageValue);
    void incAge();

signals:
    void ageChanged(int ageValue);

private:
    QString m_name;
    quint16 m_age = 10;
    quint16 m_score = 79;

};

#endif // TPERSON_H
