#include <QFile>
#include <QApplication>

#include "commfun.h"

CommFun::CommFun()
{
}

void CommFun::setStyleSheet(const QString &file)
{
#if defined(qApp)
#undef qApp
#endif
#define qApp (static_cast<QApplication *>(QCoreApplication::instance()))

    QFile qss(file);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
}

void CommFun::setStyleSheet(QWidget *widget, const QString &file)
{
    QFile qss(file);
    qss.open(QFile::ReadOnly);
    widget->setStyleSheet(qss.readAll());
}
