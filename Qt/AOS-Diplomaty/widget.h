#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QHBoxLayout *statusBar;
    QLabel *seasonYear;             // current date (e.g. July, 23th)
    QLabel *treasure;               // current balance (e.g. 103$)
    QPushButton *transportOrders;   // button to transport
    QPushButton *indystryOrders;    // button to industry (city)
    QPushButton *tradeOrders;       // button to trade
    QPushButton *diplomatyOrders;   // button to diplomaty
    QLabel *hint;                   // a simple hint
};

#endif // WIDGET_H
