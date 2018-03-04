#ifndef BOXBOARD_H
#define BOXBOARD_H

#include <QFrame>

#include "public.h"

class BoxBoard : public QFrame
{
    Q_OBJECT

public:
    BoxBoard(QWidget *parent = 0);

    void setGrid(int X,int Y,int line,int row);

private:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

    QPixmap *boxboard;
};

#endif // BOXBOARD_H
