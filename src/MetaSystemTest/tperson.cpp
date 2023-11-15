#include "tperson.h"
#include "qdebug.h"

TPerson::TPerson(QString name, QObject *parent)
    : m_name{name}, QObject{parent}
{

}

TPerson::~TPerson()
{
    qDebug() << "TPersion类的对象被删除";
}

int TPerson::age()
{
    return m_age;
}

void TPerson::setAge(quint16 ageValue)
{
    if(m_age != ageValue) {
        m_age = ageValue;
        emit ageChanged(m_age);
    }
}

void TPerson::incAge()
{
    ++m_age;
    emit ageChanged(m_age);
}
