#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QSignalMapper>
#include<QJSEngine>
#include<QJSValue>
#include<QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    Ui::Widget *ui;
    QLabel *Label;
    QPushButton *btn[16];
    QSignalMapper *btnMapper;
    bool flag = true;
};
#endif // WIDGET_H
