#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include "Player.h"
#include "Score.h"
#include "Health.h"


class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=NULL);
    void displayMainMenu();
    void displayGameOverWindow();
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    QMediaPlayer * music;
    QTimer * timer;
    QList<QGraphicsItem *> colliding_items;



public slots:
    void start();
    void restartGame();
    void breakout();
    void help();
    void back();

};

#endif // GAME_H
