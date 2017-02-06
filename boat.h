#ifndef BOAT_H
#define BOAT_H

#include "enemy.h"

class Boat: public Enemy{
public:
    Boat();
private:
    QTimer *mytimer;

};

#endif // BOAT_H
