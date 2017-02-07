#ifndef ROAD_H
#define ROAD_H


#include <QGraphicsPixmapItem>

class Road: public QObject, public QGraphicsPixmapItem{
public:
    Road(QGraphicsPixmapItem *parent=nullptr);
    int get_width();
private:
public slots:
};

#endif // ROAD_H
