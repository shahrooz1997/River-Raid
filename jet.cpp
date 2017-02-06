#include "jet.h"

Jet::Jet()
{
    setPixmap(QPixmap(":/images/jet.png"));
    xspeed = -10;
    setZValue(9);
    direction = 0;
}
