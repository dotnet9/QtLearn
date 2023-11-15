#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class TPerson;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    TPerson *boy;
    TPerson *girl;

private slots:
    void do_ageChanged(int age);
    void do_spinChanged(int age);

    void on_btnBoyInc_clicked();

    void on_btnGirlInc_clicked();

    void on_btnClearData_clicked();

    void on_btnMetaInfo_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
