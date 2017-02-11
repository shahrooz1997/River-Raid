#include "airplane.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "game.h"
#include <QImage>
#include <QBitmap>
#include <QPixmap>
#include <typeinfo>
#include "bullet.h"

extern Game *game;
extern int yspeed;

Airplane::Airplane(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    myYspeed = yspeed;

    flag = 0;
    // set graphic
    setPixmap(QPixmap(":/images/ap.png"));
    setPos(380,550-115);
    start=1;
//    this->tr;
//    QPixmap a(44,39);
//    a.fill(0,2,2);
//    setPixmap(a);
//    setShapeMode(QGraphicsPixmapItem::MaskShape);
    _right = new TplaneMove(+20,this);
    _left= new TplaneMove(-20,this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(collision()));
    timer->start(50);

    fuel=100;
    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(dec_fuel()));
//    timer2->start(200);

    timer_inc_speed = new QTimer();
    timer_dec_speed = new QTimer();
    connect(timer_inc_speed, SIGNAL(timeout()),this,SLOT(inc_speed_slot()));
    connect(timer_dec_speed, SIGNAL(timeout()),this, SLOT(dec_speed_slot()));

    timer_norm_speed = new QTimer();
    connect(timer_norm_speed, SIGNAL(timeout()),this,SLOT(norm_speed_slot()));

}

void Airplane::again()
{
    myYspeed = yspeed;

    flag = 0;
    // set graphic

    setPixmap(QPixmap(":/images/ap.png"));
    setPos(380,550-115);
    start=1;

//    connect(timer, SIGNAL(timeout()), this, SLOT(collision()));
    timer->start(50);

    fuel=100;
//    connect(timer2, SIGNAL(timeout()), this, SLOT(dec_fuel()));
//    timer2->start(200);
//    connect(timer_inc_speed, SIGNAL(timeout()),this,SLOT(inc_speed_slot()));
//    connect(timer_dec_speed, SIGNAL(timeout()),this, SLOT(dec_speed_slot()));

//    connect(timer_norm_speed, SIGNAL(timeout()),this,SLOT(norm_speed_slot()));

}

void Airplane::keyPressEvent(QKeyEvent *event){
    //start game by space    

    // move the player left and right
    if (event->key() == Qt::Key_Left){
        setPixmap(QPixmap(":/images/ap_left.png"));
        _left->run();
    }
    else if (event->key() == Qt::Key_Right){
        setPixmap(QPixmap(":/images/ap-right.png"));
        _right->run();
    }
    else if (event->key() == Qt::Key_Up){
        inc_speed();//increase speed up to 4 units
    }
    else if (event->key() == Qt::Key_Down){
        dec_speed();//decrease speed up to 3 units
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space)
    {
        if(start == 1){
            start = 0;
            strat_timer();
            game->start_timer();
            game->active_map()->start_timer();
            game->start_map()->start_timer();
//            game->next_map()->start_timer();
        }
        else
            // create a bullet
            Bullet::get_instance();
    }
}

void Airplane::keyReleaseEvent(QKeyEvent *event)
{
    if((event->key() == Qt::Key_Right) || (event->key() == Qt::Key_Left))
        setPixmap(QPixmap(":/images/ap.png"));
    else if(event->key() == Qt::Key_Up || event->key() == Qt::Key_Down)
    {
        norm_speed();
    }
    return;
}

void Airplane::strat_timer()
{
    timer->start(50);
    timer2->start(400);
}

Airplane::~Airplane()
{
    delete timer;
    delete timer2;
    delete timer_dec_speed;
    delete timer_inc_speed;
    delete timer_norm_speed;
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
            //set speed
            yspeed = myYspeed;

            //decrease health;
            game->dec_health();
            // remove them from the scene (still on the heap)

            if(typeid(*(colliding_items[i])) != typeid(Road))
                scene()->removeItem(colliding_items[i]);
//            scene()->removeItem(this);

            // delete them from the heap to save memory
            if(typeid(*(colliding_items[i])) != typeid(Road) && typeid(*(colliding_items[i])) != typeid(Bridge) && typeid(*(colliding_items[i])) != typeid(Wall))
                if(colliding_items[i] != 0)
                    delete colliding_items[i];
//            delete this;
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
        game->dec_health();
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
    fuel+=2;
    if(fuel > 100)
        fuel=100;
//    qDebug() << "fuel inc 5 unit\n";
    game->foot()->slider()->setPos(290+2*fuel,game->foot()->slider()->pos().y());
    return;
}

bool Airplane::getStart() const
{
    return start;
}

void Airplane::setStart(bool value)
{
    start = value;
}

void Airplane::inc_speed()
{
    if(flag == 0)
    {
        flag = 1;
        myYspeed = yspeed;
        timer_inc_speed->start(100);
    }
    return;
}

void Airplane::dec_speed()
{
    if(flag == 0)
    {
        flag = 1;
        myYspeed = yspeed;
        timer_dec_speed->start(100);
    }
    return;
}

void Airplane::norm_speed()
{
    timer_dec_speed->stop();
    timer_inc_speed->stop();
    timer_norm_speed->start(200);
    return;
}

void Airplane::re_fuel()
{
    fuel = 100;
    game->foot()->slider()->setPos(490,533);
}

void Airplane::inc_speed_slot()
{
    if(yspeed < myYspeed + 10)
    {
        yspeed += 1;
    }
    qDebug() << "speed is "<<yspeed;
    return;
}

void Airplane::dec_speed_slot()
{
    if(yspeed > myYspeed - 3)
    {
        yspeed -= 1;
    }
    qDebug() << "speed is "<<yspeed;
    return;
}

void Airplane::norm_speed_slot()
{
    if(yspeed < myYspeed)
    {
        yspeed += 1;
    }
    else if(yspeed > myYspeed)
    {
        yspeed -= 1;
    }
    else
    {
        flag = 0;
        timer_norm_speed->stop();
    }
    qDebug() << "speed is "<<yspeed;
    return;
}

QTimer *Airplane::getTimer2() const
{
    return timer2;
}

QTimer *Airplane::getTimer() const
{
    return timer;
}
