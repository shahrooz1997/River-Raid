#include "bullet.h"
#include <QTimer>
#include <QList>
#include "game.h"
#include <QDebug>
#include <typeinfo>
#include "bridge.h"
#include "enemy.h"
extern Game *game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set the pic of bullet
    setPixmap(QPixmap(":/images/bullet.png"));
    //initialize the sound
//    this->bulletsound = new QMediaPlayer();
//    this->bulletsound->setMedia(QUrl("qrc:/sounds/bullet.mp3"));
//    this->bulletsound->play();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(10);

    setPos(game->airplane()->x()+19,game->airplane()->y());
    game->airplane()->scene()->addItem(this);
}

Bullet *Bullet::instance = 0;

Bullet *Bullet::get_instance()
{
    if(!instance)
        instance = new Bullet();
    return instance;
}

Bullet::~Bullet()
{
    instance = 0;
    delete timer;
//    delete bulletsound;
}

void Bullet::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();
    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Boat)){
            // increase the score
            game->score()->inc_score(30);
            qDebug() << "the bullet hit a Boat.";
            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Fuel_depot))
        {
            // increase the score
            game->score()->inc_score(150);
            qDebug() << "the bullet hit a fuel depot.";

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Jet))
        {
            // increase the score
            game->score()->inc_score(100);
            qDebug() << "the bullet hit a Jet.";
            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Helicopter))
        {
            // increase the score
            game->score()->inc_score(60);
            qDebug() << "the bullet hit a Helicopter.";
            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Road))
        {
            qDebug() << "the bullet hit Road.";
            // remove them from the scene (still on the heap)
            scene()->removeItem(this);
            // delete them from the heap to save memory
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Bridge))
        {
            // increase the score
            game->score()->inc_score(500);
            qDebug() << "the bullet hit Bridge.";
            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them from the heap to save memory
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Wall))
        {
            // increase the score
//            game->score()->inc_score(500);
            qDebug() << "the bullet hit Wall.";
            // remove them from the scene (still on the heap)
//            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them from the heap to save memory
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
    }

    //move the bullet forward
    setPos(x(),y()-10);
    //if the bullet is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
