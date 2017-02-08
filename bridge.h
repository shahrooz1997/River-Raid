#ifndef BRIDGE_H
#define BRIDGE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
//#include <QMediaPlayer>
#include <QThread>


class Bridge: public QObject, public QGraphicsPixmapItem{
public:
    Bridge(QGraphicsItem *parent=nullptr);
    int get_width();
};



#endif // BRIDGE_H
