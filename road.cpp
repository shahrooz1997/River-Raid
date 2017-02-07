#include "road.h"
#include "game.h"

extern Game *game;

Road::Road(QGraphicsPixmapItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/road.png"));
    game->scene()->addItem(this);
}

int Road::get_width()
{
    return this->boundingRect().width();
}
