#include "boat.h"

Boat::Boat()
{
    str1 = QString(":/images/boat_right.png");
    str2 = QString(":/images/boat_left.png");
//    if((pix->width()+this->x()>600) || (pix->width()+this->x()>300)) {
//        setPos(x()-100,y());
//    }
//    if(((this->x() < 500) && (this->x() > 400)) || (this->x()<200)) {
//        setPos(x()+100,y());
//    }
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

    int xPos = qrand()%20;
    int yPos = -20;

    int f = qrand()%2;
    if(f)
        xPos += 200;
    else
        xPos += 500;
    setPos(xPos,yPos);

}
