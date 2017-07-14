#ifndef COMMFUN_H
#define COMMFUN_H

#include <QWidget>
#include <QString>

class CommFun
{
public:
    CommFun();

    static void setStyleSheet(const QString &file);
    static void setStyleSheet(QWidget *widget, const QString &file);
};

#endif // COMMFUN_H
