#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bubble.h"
#include "Patrick.h"
#include <QDebug>

Player::Player(QGraphicsItem *parent):QGraphicsPixmapItem(parent){

    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/biubiu.wav"));
    setPixmap(QPixmap(":/images/sponge.png"));
}



void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0) setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800) setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 0) setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + 120 < 600) setPos(x(),y()+10);
    }
    else if (event->key() == Qt::Key_Space){
            Bubble * bubble = new Bubble();
            bubble->setPos(x(),y());
            scene()->addItem(bubble);

            if (bulletsound->state() == QMediaPlayer::PlayingState){
                bulletsound->setPosition(0);
                }
            else if (bulletsound->state() == QMediaPlayer::StoppedState){
                bulletsound->play();
                }
    }
}


void Player::spawn(){
    Patrick * patrick = new Patrick();
    scene()->addItem(patrick);
}
