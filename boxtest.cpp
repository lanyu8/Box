#include "box.h"
#include <QDebug>
//可以下落
bool Box::downOK(){
//    qDebug()<<hitTest(_x,_y,0,1);
    return hitTest(n[mbox],m[mbox],0,1);
}
//是否可以左移
bool Box::leftOK(){
    return hitTest(n[mbox],m[mbox],-1,0);
}
//是否可以右移
bool Box::rightOK(){
    return hitTest(n[mbox],m[mbox],1,0);
}
//是否可以添加
//bool ElsfkWindow::addOK(){
//    for(int i=0;i<4;i++)
//        for(int j=0;j<4;j++)
//            if(_stageContent[i][3+j]&&_shapes[nextShape][nextPos][i][j]) return false;
//    return true;
//}
//碰撞检测
bool Box::hitTest(int x, int y, int xshift, int yshift){
    int _s[50][50];
    int test;
    memcpy(_s,stageContent,sizeof(stageContent));
    test=_s[x+xshift][y+yshift]+1;
        if(x+xshift<0||x+xshift>line-1||y+yshift<0||y+yshift>row-1) {
            qDebug()<<"("<<x+xshift<<","<<y+yshift<<")";
            return false;
        }
        if(test>1) {lx=x;ry=y; return false;}

        return true;
}
