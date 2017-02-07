#ifndef MAP_START_H
#define MAP_START_H

#include <QGraphicsItem>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include "map.h"
#include "road.h"

class Map_start: Map{
public:
    Map_start(bool start, QGraphicsItem *parent = nullptr);
    ~Map_start();
    int get_width();
public slots:
    void move();
private:
    QTimer *timer;
    Road *left;
    Road *right;

};

#endif // MAP_START_H
