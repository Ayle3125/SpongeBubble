#include <QTimer>
#include <typeinfo>
#include <QGraphicsScene>
#include <QList>
#include "Patrick.h"
#include "Bubble.h"
#include "Game.h"

extern Game * game;

Bubble::Bubble(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    QPixmap image1(":/images/bullet.png");
    QPixmap image2 = image1.scaled(90,90);
    setPixmap(QPixmap(image2));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bubble::move(){
    game->colliding_items = collidingItems();
    for (int i = 0, n = game->colliding_items.size(); i < n; ++i){
           if (typeid(*(game->colliding_items[i])) == typeid(Patrick)){
               game->score->increase();
               scene()->removeItem(game->colliding_items[i]);
               scene()->removeItem(this);
               delete game->colliding_items[i];
               delete this;
               return;
           }
       }

    setPos(x(),y()-10);
    if (pos().y()+40 < 0){
            scene()->removeItem(this);
            delete this;
        }
}
