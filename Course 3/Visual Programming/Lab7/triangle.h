#ifndef TRIANGLE_H
#define TRIANGLE_H


#include <QGraphicsItem>
#include <QPainter>

class Triangle : public QGraphicsItem
{
public:
    Triangle();
    ~Triangle();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TRIANGLE_H
