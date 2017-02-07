#include "game.h"
#include <QDebug>
#include "enemy.h"
#include "jet.h"
#include "map_start.h"

Game::Game(QWidget *parent)
{
    // create the scene
    _scene = new QGraphicsScene();
    _scene->setSceneRect(0,0,800,600);

    //initialize the view window
    this->setScene(_scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(800,600);
    this->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

    //initialize the airplane
    this->_airplane = new Airplane();
    //must change and enhance
    this->_airplane->setFlag(QGraphicsItem::ItemIsFocusable);
    this->_airplane->setFocus();
    this->_airplane->setZValue(10);
    this->scene()->addItem(this->_airplane);

    this->bgsound = new QMediaPlayer();
    this->bgsound->setMedia(QUrl("qrc:/sounds/bg.mp3"));
    this->bgsound->play();

    //set foot
    _foot = new Footer();
    this->scene()->addItem(this->_foot);
    this->scene()->addItem(this->_foot->slider());
    this->_foot->setZValue(10);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(make_enemy()));
    timer->start(2000);

    _score = new Score();
    scene()->addItem(_score);

    _health = new Health();
    scene()->addItem(_health);

    this->create_map();

    //the more initialize must be here...

//    qDebug() <<"game constructor ran.";

}

QGraphicsScene *Game::scene()
{
    return this->_scene;
}

Airplane *Game::airplane()
{
    return this->_airplane;
}

Footer *Game::foot()
{
    return _foot;
}

Score *Game::score()
{
    return _score;
}

Health *Game::health()
{
    return _health;
}

Game::~Game()
{
    delete _airplane;
    delete _scene;
    delete bgsound;
    delete _foot;
    delete timer;
}

void Game::game_over()
{
    return;
}

void Game::create_map()
{
//    Map_start *a = new Map_start(1);
}


void Game::make_enemy()
{
    int a=((int)qrand())%4;
    if(a == 0)
        scene()->addItem(new Boat());
    else if(a == 1)
        scene()->addItem(new Fuel_depot());
    else if(a == 2)
        scene()->addItem(new Jet());
    else if(a == 3)
        scene()->addItem(new Helicopter());

    return;
}
