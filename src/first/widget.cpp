#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->radioButton_red, SIGNAL(clicked()), this, SLOT(do_fontColor()));
    connect(ui->radioButton_yellow, SIGNAL(clicked()), this, SLOT(do_fontColor()));
    connect(ui->radioButton_black, SIGNAL(clicked()), this, SLOT(do_fontColor()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clear_clicked()
{
    ui->plainTextEdit->clear();
}


void Widget::on_checkBox_underline_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}


void Widget::on_checkBox_italic_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}


void Widget::on_checkBox_bold_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void Widget::do_fontColor()
{
    QPalette palette = ui->plainTextEdit->palette();

    if(ui->radioButton_red->isChecked()) {
        palette.setColor(QPalette::Text, Qt::red);
    }
    if(ui->radioButton_yellow->isChecked()) {
        palette.setColor(QPalette::Text, Qt::yellow);
    }
    if(ui->radioButton_black->isChecked()) {
        palette.setColor(QPalette::Text, Qt::black);
    }

    ui->plainTextEdit->setPalette(palette);
}

