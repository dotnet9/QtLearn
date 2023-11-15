#include "widget.h"
#include "./ui_widget.h"
#include "tperson.h"
#include <QMetaProperty>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    boy = new TPerson("小明", this);
    boy->setProperty("sex", "boy");
    boy->setProperty("age", 10);
    boy->setProperty("score", 70);
    boy->setAge(10);
    girl = new TPerson("小红", this);
    girl->setProperty("sex", "girl");
    girl->setProperty("age", 20);
    girl->setProperty("score", 99);
    girl->setAge(20);
    ui->spBoyAge->setProperty("isBoy", true);
    ui->spGirlAge->setProperty("isBoy", false);

    connect(boy, SIGNAL(ageChanged(int)), ui->spBoyAge, SLOT(setValue(int)));
    connect(girl, SIGNAL(ageChanged(int)), ui->spGirlAge, SLOT(setValue(int)));
    connect(boy, SIGNAL(ageChanged(int)), this, SLOT(do_ageChanged(int)));
    connect(girl, SIGNAL(ageChanged(int)), this, SLOT(do_ageChanged(int)));
    connect(ui->spBoyAge, SIGNAL(valueChanged(int)), this, SLOT(do_spinChanged(int)));
    connect(ui->spGirlAge, SIGNAL(valueChanged(int)), this, SLOT(do_spinChanged(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::do_ageChanged(int age)
{
    TPerson *person = qobject_cast<TPerson*>(sender());
    QString str = QString("%1，%2，年龄=%3")
                      .arg(person->property("name").toString())
                      .arg(person->property("sex").toString())
                      .arg(age);
    ui->plainTextEdit->appendPlainText(str);
}

void Widget::do_spinChanged(int age)
{
    QSpinBox *spinBox = qobject_cast<QSpinBox*>(sender());
    if(spinBox->property("isBoy").toBool()) {
        boy->setAge(age);
    } else {
        girl->setAge(age);
    }
}


void Widget::on_btnBoyInc_clicked()
{
    boy->incAge();
}


void Widget::on_btnGirlInc_clicked()
{
    girl->incAge();
}


void Widget::on_btnClearData_clicked()
{
    ui->plainTextEdit->clear();
}


void Widget::on_btnMetaInfo_clicked()
{
    const QMetaObject *meta = boy->metaObject();
    ui->plainTextEdit->appendPlainText(QString("类名称：%1\n").arg(meta->className()));

    ui->plainTextEdit->appendPlainText("属性：");
    for(int i = meta->propertyOffset(); i < meta->propertyCount(); i++) {
        const char* propName = meta->property(i).name();
        QString propValue = boy->property(propName).toString();
        ui->plainTextEdit->appendPlainText(QString("属性名称=%1，属性值=%2").arg(propName).arg(propValue));
    }

    ui->plainTextEdit->appendPlainText("\n类信息(classInfo): ");
    for(int i = meta->classInfoOffset(); i < meta->classInfoCount(); i++) {
        QMetaClassInfo classInfo = meta->classInfo(i);
        ui->plainTextEdit->appendPlainText(QString("Name=%1, Value=%2").arg(classInfo.name()).arg(classInfo.value()));
    }
}

