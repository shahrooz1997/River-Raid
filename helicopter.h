#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "enemy.h"

class Helicopter: public Enemy{
public:
    Helicopter();
private:
    QTimer *mytimer;
};

#endif // HELICOPTER_H
