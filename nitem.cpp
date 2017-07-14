#include "nitem.h"
#include <QDrag>
#include <QMimeData>
#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsSceneEvent>
#include <QApplication>

NItem::NItem(): mColor(qrand()%255, qrand()%255, qrand()%255)
{
    setToolTip("click and drag me!");
    setCursor(Qt::OpenHandCursor);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void NItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() != Qt::LeftButton)
    {
        //如果不是鼠标左键按下，则忽略该事件
        event->ignore();
        return;
    }
    //如果是鼠标左键按下，改变光标形状
    setCursor(Qt::ClosedHandCursor);
}

void NItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    setCursor(Qt::OpenHandCursor);    //改变光标形状
}

void NItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(QLineF(event->screenPos(),
            event->buttonDownScreenPos(Qt::LeftButton)).length() < QApplication::startDragDistance())
    {
      //如果按下的点到现在的点的距离小于程序默认的拖动距离，表明没有拖动，则返回
        return;
    }
    //为event所在窗口部件新建拖动对象
    QDrag *drag = new QDrag(event->widget());
    //新建QMimeData对象，它用来存储拖动的数据
    QMimeData *mime = new QMimeData;
     //关联
    drag->setMimeData(mime);
    //放入颜色数据
    mime->setColorData(mColor);

    //新建QPixmap对象，它用来重新绘制圆形，在拖动时显示
    QPixmap pix(21,21);
    pix.fill(Qt::white);
    QPainter painter(&pix);
    paint(&painter, 0, 0);
    drag->setPixmap(pix);

    //我们让指针指向圆形的(10,15)点
    drag->setHotSpot(QPoint(10, 15));
    //开始拖动
    drag->exec();
    //改变光标形状
    setCursor(Qt::OpenHandCursor);
}

QRectF NItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth, 0 - penWidth, 20 + penWidth, 20 + penWidth);
}

void NItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setBrush(collidingItems().isEmpty()? mColor : Qt::red);
    painter->drawRect(0, 0, 20, 20);
}

void NItem::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
        moveBy(-10, 0);
    else if(event->key() == Qt::Key_D)
        moveBy(10, 0);
    else if(event->key() == Qt::Key_W)
        moveBy(0, -10);
    else if(event->key() == Qt::Key_S)
        moveBy(0, 10);
}
