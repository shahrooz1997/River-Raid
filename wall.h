#ifndef WALL_H
#define WALL_H

#include <QGraphicsRectItem>
#include "QBrush"

class Wall: public QGraphicsRectItem{
public:

    Wall(int width, int hieght = 600, QGraphicsItem *parent = 0);
    ~Wall();
private:
    QBrush *brush;
};

#endif // WALL_H
