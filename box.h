#ifndef BOX_H
#define BOX_H

#include "widgets/dmainwindow.h"
#include "boxboard.h"
#include "boxsmall.h"
#include "public.h"

#include <QKeyEvent>
#include <QTimer>

DWIDGET_USE_NAMESPACE

class Box : public DMainWindow
{
    Q_OBJECT

public:
    Box(QWidget *parent = 0);
    ~Box();

private:
    void keyPressEvent(QKeyEvent *event);

    void leftmove();
    void rightmove();
    void downmove();
    void startgame();
    void randrow(int i);
    void drawgame();
    void setboxinit(int i);

    bool leftOK();
    bool rightOK();
    bool downOK();
    bool hitTest(int x, int y, int xshift, int yshift);//碰撞检测

    void deleteRow(int delrow);

    QTimer *timer;
//    int test;
    int n[3],m[3];
    int line,row;
    int lx,ry;
    int mbox;
    BoxSmall *sbox[50][50];
    BoxSmall *box[3];
    int stageContent[50][50];

private slots:
    void gameEvent();

};

#endif // BOX_H
