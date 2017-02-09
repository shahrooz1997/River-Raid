#ifndef MAP_START_H
#define MAP_START_H

#include <QGraphicsItem>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include "imap.h"
#include "road.h"
#include "bridge.h"

class Map_start: public IMap, public QGraphicsPixmapItem{
public:

    Map_start(QGraphicsItem *parent = 0);
    ~Map_start();
    int get_width();
    void show_items(bool start);
    Road *left();
    Road *right();
    Bridge *bridge();
    void start_timer();
    void stop_timer();
public slots:
    void move();
private:
    QTimer *timer;
    Road *_left;
    Road *_right;
    Bridge *_bridge;
};

#endif // MAP_START_H
