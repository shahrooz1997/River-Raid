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
    Airplane(QGraphicsItem *parent=nullptr);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    ~Airplane();
public slots:
    void collision();
    void dec_fuel();
private:
    QTimer *timer;
    QTimer *timer2;
    int fuel;
    void inc_fuel();
//    QPixmap &setAlpha(QPixmap &px, int val);
//    void run() override;
};


#endif // AIRPLANE_H
