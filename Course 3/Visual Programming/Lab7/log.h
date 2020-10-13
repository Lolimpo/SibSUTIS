#ifndef LOG_H
#define LOG_H

#include <QGraphicsItem>
#include <QPainter>

class log : public QGraphicsItem
{
public:
    log();
    ~log();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};


#endif // LOG_H
