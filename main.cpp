#include "stylewidget.h"
#include "nitem.h"
#include "rectitem.h"
#include "commfun.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsLineItem>

#define DEBUG_WIDGET
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if defined(DEBUG_WIDGET)
    CommFun::setStyleSheet(":/qss/style.qss");
    StyleWidget w;
    w.setObjectName("StyleWidget");
    w.setFixedSize(800, 600);
    w.show();
//#else
//    QGraphicsScene *scene = new QGraphicsScene;
//    QGraphicsView *view = new QGraphicsView;
//    NItem *item = new NItem;

//    scene->addItem(item);
//    view->setScene(scene);
//    view->show();


#else

    QGraphicsScene *scene = new QGraphicsScene;
    for(int i=0; i<5; i++) //在不同位置新建5个圆形
    {
        NItem *item = new NItem;
        item->setPos(i*50+20, 100);
        scene->addItem(item);
    }
    RectItem *rect = new RectItem; //新建矩形
    rect->setPos(100,200);
    scene->addItem(rect);
    QGraphicsLineItem *line = new QGraphicsLineItem(10, 0, 10, 240);
    line->setPen(QPen(Qt::yellow));
    scene->addItem(line);
    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    view->resize(400, 300); //设置视图大小
    view->show();
#endif

    return a.exec();
}
