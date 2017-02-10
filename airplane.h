#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QThread>
#include <tplanemove.h>

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

    bool getStart() const;

public slots:
    void collision();
    void dec_fuel();
    void re_fuel();
private:
    TplaneMove *_right;
    TplaneMove* _left;
    QTimer *timer;
    QTimer *timer2;
    int fuel;
    void inc_fuel();
    bool start;
};


#endif // AIRPLANE_H
