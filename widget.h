#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private:
    void setupUi();
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *e);

    bool m_bLeftButtonPress;
    QPoint m_StartPoint;
    QPoint m_EndPoint;

    QPixmap mFirstPix;
    QPixmap mSecondPix;
};

#endif // WIDGET_H
