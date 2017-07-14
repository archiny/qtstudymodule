#ifndef RECTITEM_H
#define RECTITEM_H

#include <QGraphicsItem>

class RectItem: public QGraphicsItem
{
public:
    RectItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void dropEvent(QGraphicsSceneDragDropEvent *event);
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);

    QColor mColor;
    bool mDragOver;
};

#endif // RECTITEM_H
