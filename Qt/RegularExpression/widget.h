#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void reciveText(const QString& str);

signals:
    void sendText(const QString& str);


private:
    QHBoxLayout *layout;
    QLineEdit *first;
    QLineEdit *second;
};

#endif // WIDGET_H
