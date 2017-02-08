#include "road.h"
#include <QDebug>

Road::Road(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/road.png"));
}

int Road::get_width()
{
    return this->boundingRect().width();
}
