#include "boxsmall.h"

BoxSmall::BoxSmall(QWidget *parent)
    : QFrame (parent)
{
    resize(BOX-1,BOX-1);
}

void BoxSmall::setbox(int i)
{
    boxsmall = new QPixmap(BOX,BOX);
    QPainter painter(boxsmall);

    static const QRgb colorTable[8] = {
        0x000000, 0xCC6666, 0x66CC66, 0x6666CC,
        0xCCCC66, 0xCC66CC, 0x66CCCC, 0xDAAA00
    };
    if(i==0){
        painter.fillRect(0,0,BOX,BOX,Qt::white);
    }else {
    QColor color = colorTable[i];
    painter.fillRect(0, 0, BOX - 2, BOX - 2,
                     color);
    painter.setPen(color.dark());
    painter.drawLine(0,BOX - 2,
                     BOX - 2, BOX - 2);
    painter.drawLine(BOX - 2, BOX - 2,
                     BOX - 2, 0);
    }
}

void BoxSmall::setmove(int line,int row){
    boxline=line;
    boxrow=row;
    move(line*BOX+21,row*BOX+41);
}

void BoxSmall::paintEvent(QPaintEvent *)  //重绘事件
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);//这样可以反锯齿
    painter.drawPixmap(0,0,*boxsmall);
}
