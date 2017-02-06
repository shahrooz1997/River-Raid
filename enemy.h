#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QTimer>
#include <QGraphicsPixmapItem>


class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem *parent=nullptr);
    ~Enemy();

public slots:
    void move();
    void movex();

protected:
    int xspeed;
    bool direction;
    bool movingx;
    QTimer *timer;
    QTimer *timer2;
};

#endif // ENEMY_H
