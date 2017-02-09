#ifndef MAP_H
#define MAP_H

#include <QGraphicsItem>
#include <QTimer>
#include <QGraphicsPixmapItem>


class IMap : public QObject
{
    Q_OBJECT
public:
    virtual int get_width() = 0;

public slots:
    virtual void move() = 0;

};

#endif // MAP_H
