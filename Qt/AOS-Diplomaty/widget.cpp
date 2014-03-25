#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      statusBar(new QHBoxLayout),
      seasonYear(new QLabel),
      treasure(new QLabel),
      transportOrders(new QPushButton),
      indystryOrders(new QPushButton),
      tradeOrders(new QPushButton),
      diplomatyOrders(new QPushButton),
      hint(new QLabel)
{
    statusBar->addWidget(seasonYear);
    statusBar->addWidget(treasure);
    statusBar->addWidget(transportOrders);
    statusBar->addWidget(indystryOrders);
    statusBar->addWidget(tradeOrders);
    statusBar->addWidget(diplomatyOrders);
    statusBar->addWidget(hint);
    setLayout(statusBar);
}

Widget::~Widget()
{

}
