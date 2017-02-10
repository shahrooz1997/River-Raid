#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem *parent=0);
    int get_health();
    void dec_health();
    void init();
private:
    int health;
};

#endif // HEALTH_H
