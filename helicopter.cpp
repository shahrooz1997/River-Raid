#include "helicopter.h"

Helicopter::Helicopter()
{
    if(direction == 1)
    {
        setPixmap(QPixmap(":/images/hc-right.png"));
        xspeed = 5;
    }
    else
    {
        setPixmap(QPixmap(":/images/hc-left.png"));
        xspeed = -5;
    }
    wingState = 0;
    mytimer = new QTimer();
    connect(mytimer, SIGNAL(timeout()), this, SLOT(round_wing()));
    mytimer->start(60);
}

void Helicopter::round_wing()
{
    if(direction == 1)
    {
        if(wingState)
        {
            setPixmap(QPixmap(":/images/hc-right.png"));
            wingState = 0;
        }
        else
        {
            setPixmap(QPixmap(":/images/hc-right2.png"));
            wingState = 1;
        }
    }
    else
    {
        if(wingState)
        {
            setPixmap(QPixmap(":/images/hc-left.png"));
            wingState = 0;
        }
        else
        {
            setPixmap(QPixmap(":/images/hc-left2.png"));
            wingState = 1;
        }
    }
}
