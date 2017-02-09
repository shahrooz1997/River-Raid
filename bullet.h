#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
//#include <QMediaPlayer>
#include <QThread>



// a singleton class
class Bullet: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    static Bullet *get_instance();
    ~Bullet();
public slots:
    void move();
private:
    Bullet(QGraphicsItem *parent = 0);
//    QMediaPlayer *bulletsound;
    QTimer *timer;
    static Bullet *instance;

};

#endif // BULLET_H
