#ifndef STYLEWIDGET_H
#define STYLEWIDGET_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>

class StyleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StyleWidget(QWidget *parent = 0);
    
    enum HeadItem{
        HI_File,
        HI_Edit,
        HI_Build,
        HI_Debug,
        HI_Helep,
        HI_Close,
        HI_Count
    };

signals:
    
public slots:
    void trigerMenu(QAction *);

protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    void setupUi();


    QMenuBar *m_pMenu;
    QVector<QMenu *> mMenus;

    QPoint mStartPos;
    bool m_bLeftButtonPress;
};

#endif // STYLEWIDGET_H
