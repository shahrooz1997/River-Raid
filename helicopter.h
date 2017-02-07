#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "enemy.h"

class Helicopter: public Enemy{
    Q_OBJECT
public:
    Helicopter();
public slots:
    void round_wing();
private:
    QTimer *mytimer;
    bool wingState;
};

#endif // HELICOPTER_H
