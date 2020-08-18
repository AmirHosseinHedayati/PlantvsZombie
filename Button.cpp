#include "Button.h"
#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>

Button::Button(QString text2 , QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    //draw rect button
    setRect(0,0,250,100);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGreen);
    setBrush(brush);

    //draw the button text
    text = new QGraphicsTextItem(text2,this);
    double x = (rect().width()/2 )- (text->boundingRect().width()/2);
    double y = (rect().height()/2)- (text->boundingRect().height()/2);
    text->setFont(QFont("Comic Sans MS", 20));
    text->setPos(x-30,y-20);

    //need for HoverEvents
    setAcceptHoverEvents(true);

}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGreen);
    setBrush(brush);
}
