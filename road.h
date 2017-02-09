#ifndef ROAD_H
#define ROAD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
//#include <QMediaPlayer>
#include <QThread>


class Road: public QObject, public QGraphicsPixmapItem{
public:
    Road(QGraphicsItem *parent=0);
    int get_width();
};

#endif // ROAD_H
