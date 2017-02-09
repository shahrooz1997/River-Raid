#ifndef FOOTER_H
#define FOOTER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QThread>
#include <QKeyEvent>

class Footer:public QThread, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Footer();
    void keyPressEvent(QKeyEvent *event);
    QGraphicsPixmapItem *slider();
    //public slots:
//    void move_slider();
private:
    QGraphicsPixmapItem *_slider;
};

#endif // FOOTER_H
