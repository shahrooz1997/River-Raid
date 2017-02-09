#include "wall.h"
#include "QColor"
#include <QMargins>

Wall::Wall(int width,int height, QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(0, 0, width, height);
    brush = new QBrush();
    brush->setColor(*(new QColor(108,152,80)));
    brush->setStyle(Qt::SolidPattern);
    setBrush(*brush);
}

Wall::~Wall()
{
    delete brush;
}

