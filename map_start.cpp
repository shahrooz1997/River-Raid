#include "map_start.h"
#include "game.h"

extern Game *game1;
extern int yspeed;

Map_start::Map_start(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    _left = new Road();
    _right = new Road();
    _left->setPos(-32,-80);
    _right->setPos(496,-80);
    _bridge = new Bridge();
    _bridge->setPos(304,-74);
    setZValue(8);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(40);
}

Map_start::~Map_start()
{
    delete timer;
    delete _right;
    delete _left;
    delete _bridge;
}

int Map_start::get_width()
{
    return _left->get_width();
}

void Map_start::show_items(bool start)
{
    game1->scene()->addItem(_left);
    game1->scene()->addItem(_right);
    if(!start)
        game1->scene()->addItem(_bridge);
    return;
}

Road *Map_start::left()
{
    return _left;
}

Road *Map_start::right()
{
    return _right;
}

Bridge *Map_start::bridge()
{
    return _bridge;
}

void Map_start::start_timer()
{
    timer->start(40);
}

void Map_start::stop_timer()
{
    timer->stop();
}


void Map_start::move()
{
    _right->setPos(_right->x(),_right->y()+yspeed);
    _left->setPos(_left->x(),_left->y()+yspeed);
    _bridge->setPos(_bridge->x(),_bridge->y()+yspeed);

    if(_right->y()>600)
    {
        delete this;
        return;
    }

    return;
}
