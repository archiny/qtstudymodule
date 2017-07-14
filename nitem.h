#ifndef NITEM_H
#define NITEM_H

#include <QGraphicsItem>
#include <QCursor>

class NItem: public QGraphicsItem
{
public:
    NItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
private:
    QColor mColor;

};

#endif // NITEM_H
