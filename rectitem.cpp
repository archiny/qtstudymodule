#include <QPainter>
#include <QGraphicsSceneEvent>
#include <QMimeData>

#include "rectitem.h"

RectItem::RectItem(): mDragOver(false)
{
    setAcceptDrops(true);  //设置接收拖放
    mColor = QColor(Qt::lightGray);
}

QRectF RectItem::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void RectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setBrush(mDragOver ? mColor.light(130) : mColor);
    painter->drawRect(0,0,50,50);
}

void RectItem::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    mDragOver = false;
    if(event->mimeData()->hasColor()){
        mColor = qvariant_cast<QColor>(event->mimeData()->colorData());
        update();
    }
}

void RectItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasColor()){
        event->setAccepted(true);
        mDragOver = true;
        update();
        return;
    }

    event->setAccepted(false);
}

void RectItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event)
    mDragOver = false;
    update();
}
