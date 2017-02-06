#include "boat.h"

Boat::Boat()
{
    if(direction == 1)
    {
        setPixmap(QPixmap(":/images/boat_right.png"));
        xspeed = 2;
    }
    else
    {
        setPixmap(QPixmap(":/images/boat_left.png"));
        xspeed = -2;
    }
}
