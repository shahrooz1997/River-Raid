#ifndef BULLET_H
#define BULLET_H

#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QThread>
#include "game.h"


// a singleton class
class Bullet: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    static Bullet *get_instance();
    ~Bullet();
    void run();
public slots:
    void move();
private:
    Bullet(QGraphicsItem *parent = 0);
    QMediaPlayer *bulletsound;
    QTimer *timer;
    static Bullet *instance;

};

#endif // BULLET_H
