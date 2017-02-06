#include "airplane.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include <QDebug>
#include "game.h"
#include <QImage>
#include <QBitmap>
#include <QPixmap>

extern Game *game;

Airplane::Airplane(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    // set graphic
    setPixmap(QPixmap(":/images/ap.png"));
    setPos(380,550-115);

//    this->tr;
//    QPixmap a(44,39);
//    a.fill(0,2,2);
//    setPixmap(a);
//    setShapeMode(QGraphicsPixmapItem::MaskShape);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(collision()));
    timer->start(50);

    fuel=100;
    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(dec_fuel()));
    timer2->start(200);
}

void Airplane::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        setPixmap(QPixmap(":/images/ap_left.png"));
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPixmap(QPixmap(":/images/ap-right.png"));
        if (pos().x() + pixmap().width() < 800)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet::get_instance();
    }
}

void Airplane::keyReleaseEvent(QKeyEvent *event)
{
    if((event->key() == Qt::Key_Right) || (event->key() == Qt::Key_Left))
        setPixmap(QPixmap(":/images/ap.png"));
    return;
}

Airplane::~Airplane()
{
    delete timer;
    delete timer2;
}

void Airplane::collision()
{
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) != typeid(Fuel_depot) && typeid(*(colliding_items[i])) != typeid(Bullet))
        {
            //decrease health;

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;
            return;
        }
        else
        {
            if(typeid(*(colliding_items[i])) != typeid(Bullet))
                inc_fuel();
        }
    }
}

void Airplane::dec_fuel()
{
    if(fuel<0)
    {
        //end the game
//        qDebug() << "Game Ended, becuase fuel finished!\n";
        return;
    }
    fuel-=1;
//    qDebug() << "fuel dec one unit\n";
//    game
    game->foot()->slider()->setPos(290+2*fuel,game->foot()->slider()->pos().y());
    return;
}

void Airplane::inc_fuel()
{
    if(fuel > 100)
        return;
    fuel+=5;
    if(fuel > 100)
        fuel=100;
//    qDebug() << "fuel inc 5 unit\n";
    game->foot()->slider()->setPos(290+2*fuel,game->foot()->slider()->pos().y());
    return;
}


