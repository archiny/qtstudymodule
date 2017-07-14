#include <QPushButton>
#include <QDebug>
#include <QBoxLayout>
#include <QMouseEvent>

#include "stylewidget.h"
#include "commfun.h"

StyleWidget::StyleWidget(QWidget *parent) :
    QWidget(parent), mMenus(HI_Count), m_bLeftButtonPress(false)
{
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::FramelessWindowHint);
    setupUi();
}

void StyleWidget::trigerMenu(QAction *)
{
    qDebug("clicked !\n");
}

void StyleWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(m_bLeftButtonPress){
        QPoint endPos = mapToGlobal(e->pos());
        qreal x = endPos.x() - mStartPos.x();
        qreal y = endPos.y() - mStartPos.y();
        mStartPos = endPos;

        QPoint pos = mapToGlobal(QPoint(x, y));
        move(pos);
    }
}

void StyleWidget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        m_bLeftButtonPress = true;
        mStartPos = mapToGlobal(e->pos());
    }
}

void StyleWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        m_bLeftButtonPress = false;
    }
}

void StyleWidget::setupUi()
{
    m_pMenu = new QMenuBar(this);

    m_pMenu->setMinimumSize(180, 36);

    mMenus[HI_File] = m_pMenu->addMenu(QString::fromUtf8("文件"));
    mMenus[HI_Edit] = m_pMenu->addMenu(QString::fromUtf8("编辑"));
    mMenus[HI_Build] = m_pMenu->addMenu(QString::fromUtf8("构建"));
    mMenus[HI_Debug] = m_pMenu->addMenu(QString::fromUtf8("调试"));
    mMenus[HI_Helep] = m_pMenu->addMenu(QString::fromUtf8("帮助"));
    mMenus[HI_Close] = m_pMenu->addMenu(QString::fromUtf8("关闭"));

    QVBoxLayout *top_v_layout = new QVBoxLayout;
    top_v_layout->addWidget(m_pMenu);
    top_v_layout->addStretch();
    top_v_layout->setContentsMargins(0, 0, 0, 11);

    connect(mMenus[HI_Close],SIGNAL(triggered(QAction*)),this,SLOT(trigerMenu(QAction*)));

    setLayout(top_v_layout);
}
