#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QEvent>
#include <QMessageBox>
#include <QTimer>

#include <QDebug>

class escapedButton : public QPushButton
{
public:
    escapedButton(QWidget *parent = nullptr);
protected:
    bool event(QEvent *e) override;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
