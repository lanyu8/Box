#ifndef BOXSMALL_H
#define BOXSMALL_H

#include <QFrame>
#include <QPainter>

#include "public.h"

class BoxSmall : public QFrame
{
public:
    BoxSmall(QWidget *parent = 0);

    void setbox(int i);
    void setmove(int line,int row);

    int boxline,boxrow;
private:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

    QPixmap *boxsmall;
};

#endif // BOXSMALL_H
