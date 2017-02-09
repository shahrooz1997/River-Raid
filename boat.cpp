#include "boat.h"

Boat::Boat()
{
    str1 = QString(":/images/boat_right.png");
    str2 = QString(":/images/boat_left.png");
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
