#ifndef WALL_H
#define WALL_H

#include <QGraphicsRectItem>
#include "QBrush"

class Wall: public QGraphicsRectItem{
public:
    Wall(int width, int hieght = 600, QGraphicsItem *parent = nullptr);
    ~Wall();
private:
    QBrush *brush;
};

#endif // WALL_H
