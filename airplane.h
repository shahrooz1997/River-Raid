#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QThread>


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

public slots:
    void collision();
    void dec_fuel();
    void re_fuel();
private:
    QTimer *timer;
    QTimer *timer2;
    int fuel;
    void inc_fuel();
};


#endif // AIRPLANE_H
