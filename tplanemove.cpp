#include "tplanemove.h"

TplaneMove::TplaneMove(int x,QGraphicsPixmapItem* item)
{
    MyItem = item;
    dx =x;
}

void TplaneMove::run()
{
    if (MyItem->pos().x() + MyItem->pixmap().width() < 800)
        MyItem->setPos(MyItem->pos().x()+dx,MyItem->pos().y());
}

