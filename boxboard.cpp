#include "boxboard.h"

#include <QPainter>
#include <QTime>

BoxBoard::BoxBoard(QWidget *parent)
    : QFrame(parent)
{
    resize(430,430);
    //将游戏区域设置为较大的正方形
    move(20,40);
}

void BoxBoard::setGrid(int X,int Y,int line,int row)
{
    int width = line*BOX;
    int height = row*BOX;
    boxboard = new QPixmap(width+1,height+1);
    boxboard->fill(Qt::white);
    QPainter painter(boxboard);
    painter.setPen(Qt::DotLine);
    for(int i = X; i <= height; i=i+BOX)
    {
        painter.drawLine(QPoint(0,i),QPoint(width,i));
    }
    for(int j = Y; j <= width; j=j+BOX)
    {
        painter.drawLine(QPoint(j,0),QPoint(j,height));
    }
}

void BoxBoard::paintEvent(QPaintEvent *)  //重绘事件
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);//这样可以反锯齿
    painter.drawPixmap(0,0,*boxboard);
}
