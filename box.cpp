#include "box.h"
#include <QDebug>
#include <QDateTime>

Box::Box(QWidget *parent)
    : DMainWindow(parent)
{
    line=18;
    row=18;
    mbox=0;
    resize(500,500);
    BoxBoard *board = new BoxBoard(this);
    board->setGrid(0,0,line,row);
    for(int i=0;i<line;i++){
        for(int j=0;j<row;j++){
           stageContent[i][j] = 0;
           sbox[i][j] = new BoxSmall(this);
           sbox[i][j]->setbox(0);
           sbox[i][j]->setmove(i,j);
           sbox[i][j]->update();
        }
    }

    setboxinit(line/9);
    startgame();
    //随机数种子
    qsrand(QDateTime::currentDateTime().toTime_t());
    //计时器
    timer=new QTimer();
    timer->start(700);
    connect(timer,SIGNAL(timeout()),this,SLOT(gameEvent()));
}

void Box::gameEvent()
{
    int l;
    for(int i=0;i<line/9;i++){
        n[i]=box[i]->boxline;
        m[i]=box[i]->boxrow;
    }
    for(int i=0;i<line/9;i++){
        if(hitTest(n[i],m[i],0,1)){
            stageContent[n[i]][m[i]]=0;
            m[i]++;
            box[i]->setmove(n[i],m[i]);
            stageContent[n[i]][m[i]]=1;
        }else if(!(ry==m[i+1]-1)){
            stageContent[n[i]][m[i]]=1;
            sbox[n[i]][m[i]]->setbox(1);
            sbox[n[i]][m[i]]->update();
            for(l=0;l<line;l++){
                if(stageContent[l][m[i]]==0) break;
            }
            if(l==line) deleteRow(m[i]);
            box[i]->setmove(4+i*9,0);
            box[i]->update();
        }
    }
}

//消除某行
void Box::deleteRow(int delrow){
    for(int l=0;l<line;l++) {
        stageContent[l][delrow] = 0;
    }
    int _s[50][50];
    memcpy(_s,stageContent,sizeof(stageContent));
    for(int l=0;l<line;l++) {
        for(int r=row-1;r>delrow;r--){
            stageContent[l][r-1] =_s[l][r];
        }
    }
    for(int l=0;l<line;l++) {
       stageContent[l][row-1] = qrand()%2;
    }
    drawgame();
}

void Box::setboxinit(int i)
{
    for(int _i=0;_i<i;_i++){
        box[_i] = new BoxSmall(this);
        box[_i]->setbox(1);
        box[_i]->setmove(4+_i*9,0);
        box[_i]->update();
    }
//    qDebug()<<box[1]->boxline <<box[1]->boxrow;
}

void Box::startgame()
{
    randrow(3);
    drawgame();
}

void Box::randrow(int r)
{
    for(int i=0;i<line;i++){
        for(int j=row-1;j>=row-r;j--){
           stageContent[i][j]=qrand()%2;
        }
    }
}

void Box::drawgame()
{
    for(int i=0;i<line;i++){
        for(int j=0;j<row;j++){
            if(stageContent[i][j]){
                sbox[i][j]->setbox(1);
                sbox[i][j]->update();
            }else{
                sbox[i][j]->setbox(0);
                sbox[i][j]->update();
            }
        }
    }
}

void Box::keyPressEvent(QKeyEvent *event){
    switch (event->key()){
    case Qt::Key_1 : mbox=0; break;
    case Qt::Key_2 : mbox=1; break;
    case Qt::Key_3 : mbox=2; break;
    }

    switch (event->key()){
        case Qt::Key_S :
        case Qt::Key_Down :
            while(downOK()) downmove();
        break;
        case Qt::Key_A :
        case  Qt::Key_Left :
            if(leftOK()) leftmove();
        break;
        case Qt::Key_D :
        case  Qt::Key_Right :
            if(rightOK()) rightmove();
        break;
    }
//    drawgame();
}

void Box::leftmove()
{
    n[mbox]=box[mbox]->boxline;
    m[mbox]=box[mbox]->boxrow;
    stageContent[n[mbox]][m[mbox]]=0;
    n[mbox]--;
    box[mbox]->setmove(n[mbox],m[mbox]);
    stageContent[n[mbox]][m[mbox]]=1;
}

void Box::rightmove()
{
    n[mbox]=box[mbox]->boxline;
    m[mbox]=box[mbox]->boxrow;
    stageContent[n[mbox]][m[mbox]]=0;
    n[mbox]++;
    box[mbox]->setmove(n[mbox],m[mbox]);
    stageContent[n[mbox]][m[mbox]]=1;
}

void Box::downmove()
{
    n[mbox]=box[mbox]->boxline;
    m[mbox]=box[mbox]->boxrow;
    stageContent[n[mbox]][m[mbox]]=0;
    m[mbox]++;
    box[mbox]->setmove(n[mbox],m[mbox]);
    stageContent[n[mbox]][m[mbox]]=1;
}

Box::~Box()
{

}
