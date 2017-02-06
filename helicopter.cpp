#include "helicopter.h"

Helicopter::Helicopter()
{
    if(direction == 1)
    {
        setPixmap(QPixmap(":/images/hc_right.png"));
        xspeed = 5;
    }
    else
    {
        setPixmap(QPixmap(":/images/hc_left.png"));
        xspeed = -5;
    }
}
