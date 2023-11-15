#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clear_clicked();

    void on_checkBox_underline_clicked(bool checked);

    void on_checkBox_italic_clicked(bool checked);

    void on_checkBox_bold_clicked(bool checked);

    void do_fontColor();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
