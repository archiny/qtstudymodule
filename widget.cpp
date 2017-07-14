#include <QEvent>
#include <QMouseEvent>
#include <QPainter>

#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), m_bLeftButtonPress(false)
{
    setWindowOpacity(0.8);
}

Widget::~Widget()
{
}


void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if(m_bLeftButtonPress){
        m_EndPoint = e->pos();
        update();
    }
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        m_bLeftButtonPress = true;
        m_StartPoint = e->pos();
        m_EndPoint = m_StartPoint;
        update();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        m_bLeftButtonPress = false;
        m_EndPoint = e->pos();
        update();
    }
}

void Widget::resizeEvent(QResizeEvent *)
{
    mFirstPix = QPixmap(size());
    mSecondPix = QPixmap(size());

    mFirstPix.fill(QColor(255, 255, 255, 0));
    mSecondPix.fill(QColor(255, 255, 255, 0));

}

void Widget::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);

    if(m_bLeftButtonPress)
        mFirstPix = mSecondPix;

    QPainter tempPainter(m_bLeftButtonPress? &mFirstPix : &mSecondPix);
    tempPainter.setPen(Qt::red);
    int w = m_EndPoint.x() - m_StartPoint.x();
    int h = m_EndPoint.y() - m_StartPoint.y();
    tempPainter.drawRect(m_StartPoint.x(), m_StartPoint.y(), w, h);

    QPainter painter(this);
    painter.drawPixmap(0,0, m_bLeftButtonPress? mFirstPix : mSecondPix);
}




