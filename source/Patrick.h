#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Patrick: public QObject,public  QGraphicsPixmapItem{
    Q_OBJECT
public:
     Patrick(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // ENEMY_H
