#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    layout = new QHBoxLayout;
    first = new QLineEdit;
    second = new QLineEdit("ojojoo");

    layout->addWidget(first);
    layout->addWidget(second);

    setLayout(layout);

    connect( first, SIGNAL( textChanged(QString) ), this, SLOT( reciveText(QString) ) );
    connect( this, SIGNAL( sendText(QString) ), second, SLOT( setText(QString) ) );
}

Widget::~Widget()
{
}

void Widget::reciveText(const QString &str)
{
    QRegularExpressionMatchIterator it = QRegularExpression("(2[0-5]|1[0-9]|[1-9])").globalMatch(str);
    QString text("");

    while( it.hasNext( ) )
    {
        text += it.next( ).captured(1) + " ";
    }
    emit sendText(text);
}
