#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QThread>
#include "tplanemove.h"

class Airplane:public QThread, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Airplane(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void strat_timer();
    ~Airplane();
    QTimer *getTimer() const;
    QTimer *getTimer2() const;

    void setStart(bool value);
    void inc_speed();
    void dec_speed();
    void norm_speed();
    void again();

    bool getStart() const;

public slots:
    void collision();
    void dec_fuel();
    void re_fuel();
    void inc_speed_slot();
    void dec_speed_slot();
    void norm_speed_slot();
private:
    TplaneMove *_right;
    TplaneMove* _left;
    QTimer *timer;
    QTimer *timer2;
    QTimer *timer_inc_speed;
    QTimer *timer_dec_speed;
    QTimer *timer_norm_speed;
    int fuel;
    void inc_fuel();
    bool flag;
    bool start;
    int myYspeed;
};


#endif // AIRPLANE_H
