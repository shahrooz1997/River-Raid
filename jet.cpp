#include "jet.h"

Jet::Jet()
{
    setPixmap(QPixmap(":/images/jet.png"));
    setPos(820,-20 + qrand() % 300);
    xspeed = -10;
    setZValue(9);
    direction = 0;
    timer2->start(50);
    movingx=1;
}
