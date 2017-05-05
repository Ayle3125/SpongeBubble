#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class Bubble: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bubble(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // BULLET_H
