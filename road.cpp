#include "road.h"
#include "bullet.h"
#include <QTimer>
#include <QList>
#include "game.h"
#include <QDebug>
#include <typeinfo>
#include "enemy.h"

extern Game *game;

Road::Road(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/road.png"));
    game->airplane()->scene()->addItem(this);
}

int Road::get_width()
{
    return this->boundingRect().width();
}
