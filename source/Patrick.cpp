#include <QTimer>
#include <QTime>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"
#include "Patrick.h"

extern Game * game;

Patrick::Patrick(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int random_number = qrand() % 700;
    setPos(random_number,0);
    QPixmap image1(":/images/patrick.png");
    QPixmap image2 = image1.scaled(100,100);
    setPixmap(QPixmap(image2));
    setTransformOriginPoint(50,50);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Patrick::move(){
    setPos(x(),y()+5);
    if (pos().y() > 600){
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
        }
}


