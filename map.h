#ifndef MAP_H
#define MAP_H

#include <QGraphicsItem>
#include <QTimer>
#include <QGraphicsPixmapItem>


class Map : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
//    Map(QGraphicsItem *parent=nullptr);
//    ~Map();
    virtual int get_width() = 0;

public slots:
    virtual void move() = 0;

private:

};

#endif // MAP_H
