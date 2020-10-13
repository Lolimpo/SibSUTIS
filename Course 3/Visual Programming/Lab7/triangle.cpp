#include "triangle.h"

Triangle::Triangle() :
    QGraphicsItem()
{

}

Triangle::~Triangle()
{

}

QRectF Triangle::boundingRect() const
{
    return QRectF(-50,-80,100,160);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QPolygon polygon;
        polygon << QPoint(0,-80) << QPoint(50,80) << QPoint(-50,80);
        painter->setBrush(Qt::green);
        painter->drawPolygon(polygon);
        Q_UNUSED(option);
        Q_UNUSED(widget);
}
