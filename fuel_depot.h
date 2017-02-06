#ifndef FUEL_DEPOT_H
#define FUEL_DEPOT_H

#include "enemy.h"

class Fuel_depot: public Enemy{
public:
    Fuel_depot();
private:
    QTimer *mytimer;

};

#endif // FUEL_DEPOT_H
