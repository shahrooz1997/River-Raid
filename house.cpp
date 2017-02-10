#include "house.h"
#include "game.h"
#include <QList>
#include <typeinfo>

extern Game *game;
extern int yspeed;


House::House(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    /* a random number */
    setPixmap(QPixmap(":/images/house.png"));
    int xPos = qrand()%50;
    int yPos = -20;

    int f = qrand()%2;
    if(f)
        xPos += 0;
    else
        xPos += 700;
    setPos(xPos,yPos);
    this->setZValue(9);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(40);
}


House::~House()
{
    delete timer;
}

void House::move()
{
    setPos(x(),y()+yspeed);

    if(pos().y()+pixmap().height()>600) {
        game->scene()->removeItem(this);
        delete this;
    }
    return;
}
