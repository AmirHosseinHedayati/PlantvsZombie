#ifndef BUTTON_H
#define BUTTON_H

#include "QGraphicsRectItem"
#include "QGraphicsSceneMouseEvent"
#include <QMouseEvent>
#include <QObject>

class Button:public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Button(QString text2, QGraphicsItem *parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
    QGraphicsTextItem *text;

signals:
    void clicked();
};

#endif // BUTTON_H
