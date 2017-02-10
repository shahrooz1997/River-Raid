#ifndef TPLANEMOVE_H
#define TPLANEMOVE_H

#include <QThread>
#include <QGraphicsPixmapItem>

class TplaneMove : public QThread
{
public:
    TplaneMove(int x,QGraphicsPixmapItem* item);
    void run();
private:
    QGraphicsPixmapItem* MyItem;
    int dx;
};

#endif // TPLANEMOVE_H
