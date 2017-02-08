#include "bridge.h"

Bridge::Bridge(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/bridge.png"));
}

int Bridge::get_width()
{
    return this->boundingRect().width();
}
