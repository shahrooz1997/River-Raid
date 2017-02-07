#include "map_start.h"
#include "Game.h"

extern Game *game;

Map_start::Map_start(bool start, QGraphicsItem *parent)
{
    left = new QGraphicsPixmapItem(parent);
    left->setPixmap(QPixmap(":/images/road.png"));
    left->setPos(0,-20);

    right = new QGraphicsPixmapItem(parent);
    right->setPixmap(QPixmap(":/images/road.png"));
    right->setPos(464,-20);

    bridge = new QGraphicsPixmapItem(parent);
    bridge->setPixmap(QPixmap(":/images/bridge.png"));
    bridge->setPos(336,-20);

    game->scene()->addItem(left);
//    game->scene()->addItem(right);

//    if(!start)
//    {
//        game->scene()->addItem(bridge);
//    }

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
//    timer->start(50);
}

Map_start::~Map_start()
{
    delete timer;
    delete right;
    delete left;
    delete bridge;
}

int Map_start::get_width()
{
    return right->boundingRect().width();
}

void Map_start::move()
{
    right->setPos(right->x(),right->y()+10);
    left->setPos(left->x(),left->y()+10);
    bridge->setPos(bridge->x(),bridge->y()+10);

    if(right->y()>600)
    {
        delete right;
        delete left;
        delete bridge;
        return;
    }

    return;
}
