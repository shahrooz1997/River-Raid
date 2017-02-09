#include "enemy.h"
#include "game.h"


extern Game *game;

Enemy::Enemy(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    /* a random number */
    setPos(qrand()%800,-20);

    direction = qrand()%2;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(movex()));
    movingx=0;

}


Enemy::~Enemy()
{
    delete timer;
    delete timer2;
}

void Enemy::move()
{
    setPos(x(),y()+5);
    if(movingx == 0 && pos().y()+pixmap().height()>250)
    {
        timer2->start(50);
        movingx=1;
    }
    if(pos().y()+pixmap().height()>600) {
        game->scene()->removeItem(this);
        delete this;
    }

    return;
}

void Enemy::movex()
{
    setPos(x()+xspeed, y());
    if(pos().x()<0) {
        xspeed *= 1;
        return;
    }
    if(pos().x()+pixmap().width()>800) {
        xspeed *= 1;
        return;
    }

    return;
}
