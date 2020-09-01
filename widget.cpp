#include "widget.h"

escapedButton::escapedButton(QWidget * parent) : QPushButton(parent)
{
    setText("CatchMe");
    connect(this,&QPushButton::clicked,this,[=]{
        QMessageBox::information(this,"","");
    });
}

bool escapedButton::event(QEvent *e){
    if (e->type() == QHoverEvent::HoverMove){
        if (pos().x() == 0){
            setGeometry(650,550,150,50);
        }else{
            setGeometry(0,0,150,50);
        }
    }else if (e->type() == QFocusEvent::FocusIn){
        setEnabled(false);
        QTimer::singleShot(2500,[this]{
            setEnabled(true);
        });
    }

    return QPushButton::event(e);
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    escapedButton *btn = new escapedButton(this);
    btn->setGeometry(0,0,150,50);
    setMaximumSize(800,600);
    setMinimumSize(800,600);
}

Widget::~Widget()
{
}

