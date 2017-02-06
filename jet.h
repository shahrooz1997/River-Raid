#ifndef JET_H
#define JET_H

#include "enemy.h"

class Jet: public Enemy{
public:
    Jet();
private:
    QTimer *mytimer;

};

#endif // JET_H
