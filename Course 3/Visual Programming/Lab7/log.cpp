#include "log.h"

log::log():
    QGraphicsItem()
{

}

log::~log()
{}

QRectF log::boundingRect() const
{
    return QRectF(-50, -80, 100, 160);
}

void log::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << QPoint(0, 50) << QPoint(0, -50) << QPoint(50, -50) << QPoint(50, 50);
    painter->setBrush(Qt::darkYellow);
    //150, 75, 0 NOT BROWN WTF MZF
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
