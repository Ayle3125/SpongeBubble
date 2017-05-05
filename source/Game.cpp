#include "Patrick.h"
#include "Game.h"
#include "Button.h"
#include <QTimer>
#include <QFont>
#include <QUrl>
#include <QBrush>
#include <QImage>
#include <QMediaPlayer>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>


Game::Game(QWidget *parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    QImage image1(":/images/bgd.jpg");
    QImage image2 = image1.scaled(800,600);
    setBackgroundBrush(QBrush(QImage(image2)));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    show();

}

void Game::start(){

    scene->clear();

    player = new Player();
    player->setPos(400,480);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);


    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/Bells.mp3"));
    music->play();

    // create playAgain button
     Button* playAgain = new Button(QString("Play Again"));
     playAgain->setPos(0,55);
     scene->addItem(playAgain);
     connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

     // create stop button
     Button* quit = new Button(QString("stop"));
     quit->setPos(0,100);
     scene->addItem(quit);
     connect(quit,SIGNAL(clicked()),this,SLOT(breakout()));

}

void Game::displayMainMenu(){
    scene->clear();
    QPixmap image1(":/images/sponge1.png");
    QGraphicsPixmapItem *image = new QGraphicsPixmapItem;
    image->setPixmap(QPixmap(image1));
    image->setOffset(420,200);
    scene->addItem(image);
    QPixmap image2(":/images/biaoti2.png");
    QGraphicsPixmapItem *imagee = new QGraphicsPixmapItem;
    imagee->setPixmap(QPixmap(image2));
    imagee->setOffset(20,80);
    scene->addItem(imagee);

    // create the Play button
    Button* playButton = new Button(QString("Play"));
    playButton->setPos(150,400);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the help button
    Button* helpButton = new Button(QString("help"));
    helpButton->setPos(150,450);
    connect(helpButton,SIGNAL(clicked()),this,SLOT(help()));
    scene->addItem(helpButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    quitButton->setPos(150,500);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);


}

void Game::displayGameOverWindow(){
    // disable all scene items
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
            scene->items()[i]->setEnabled(false);
        }
    //stop the background music & Patrick
    music->stop();
    timer->stop();
    //player->spawn()->enemy()->timer->stop();
    QGraphicsRectItem* panel = new QGraphicsRectItem(0,0,800,600);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    panel->setBrush(brush);
    panel->setOpacity(0.65);
    scene->addItem(panel);

    // create playAgain button
     Button* playAgain = new Button(QString("Play Again"));
     playAgain->setPos(150,400);
     scene->addItem(playAgain);
     connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

     // create backbutton
     Button* back = new Button(QString("back to Menu"));
     back->setPos(150,470);
     scene->addItem(back);
     connect(back,SIGNAL(clicked()),this,SLOT(back()));


     // create text annoucning score
     QGraphicsTextItem* overText = new QGraphicsTextItem(QString("Your score: ") + QString::number(score->getScore()));
     overText->setDefaultTextColor(Qt::white);
     QFont titleFont("comic sans",50);
     overText->setFont(titleFont);
     overText->setPos(150,225);
     scene->addItem(overText);
}

void Game::restartGame(){
    // clear some stuff then call start()
    music->stop();
    colliding_items.clear();
    scene->clear();
    start();
}

void Game::breakout(){
    displayGameOverWindow();
}

void Game::help(){
    scene->clear();
    QGraphicsRectItem* panel = new QGraphicsRectItem(200,150,400,300);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    panel->setBrush(brush);
    panel->setOpacity(0.65);
    scene->addItem(panel);


    QGraphicsTextItem* overText = new QGraphicsTextItem(QString("HELP: "));
    overText->setDefaultTextColor(Qt::white);
    QFont titleFont("t",40);
    overText->setFont(titleFont);
    overText->setPos(200,150);
    scene->addItem(overText);

    overText = new QGraphicsTextItem(QString("    调皮的派大星来了，\n    快来帮海绵宝宝吹泡泡和他一起玩吧！\n\n    按动键盘上的方向键可以移动海绵宝宝，按动空格\n键就可以吹泡泡了！\n    千万不要让多于三个派大星没有泡泡玩哦!健康度为\n零就没办法继续玩耍了。\n    快来试试把泡泡吹到派大星身边吧~\n\n\n\n                                                  Ayle@SpongeBubble v1.0"));
    overText->setDefaultTextColor(Qt::white);
    QFont Font("t",12);
    overText->setFont(Font);
    overText->setPos(205,210);
    scene->addItem(overText);

    // create backbutton
    Button* back = new Button(QString("back to Menu"));
    back->setPos(50,500);
    scene->addItem(back);
    connect(back,SIGNAL(clicked()),this,SLOT(back()));
}

void Game::back(){
    displayMainMenu();
}
