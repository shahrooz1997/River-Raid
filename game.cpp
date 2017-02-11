#include "game.h"
#include <QDebug>
#include "enemy.h"
#include "jet.h"
#include "balloon.h"
#include "map_start.h"
#include "house.h"
#include <QtCore>
#include <QtGui>
#include <typeinfo>

extern int yspeed;
extern int max_speed;


Game::Game()
{
    //intialize the speed
    yspeed = 5;
    // create the scene
    _scene = new QGraphicsScene();
    _scene->setSceneRect(0,0,800,600);

    //initialize the view window
    this->setScene(_scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(800,600);
    this->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

    this->bgsound = new QMediaPlayer();
    this->bgsound->setMedia(QUrl("qrc:/sounds/bg.mp3"));
    this->bgsound->play();

    _foot = new Footer();

    //you should change the location of these code to start()
    map_timer = new QTimer();
    connect(map_timer, SIGNAL(timeout()),this, SLOT(create_map()));
//    map_timer->start(6000);


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
    delete _panel1;
    delete _panel2;
    delete _gameOvr;
    delete _health;
    delete _play;
    delete _score;
    delete _cancelg;
    delete _playg;
    delete _cancel;
    delete map_timer;
    delete _active_map;
    delete _next_map;
    delete timer_for_start;
    delete _start_map;
    delete _titleText;
}

void Game::game_over()
{
    active_map()->stop_timer();
    stop_timer();
//    timer->stop();
    _airplane->getTimer()->stop();
    _airplane->getTimer2()->stop();
    QList<QGraphicsItem*> mitem = _scene->items();
    //health,score,foot,aiplane
    foreach (QGraphicsItem* it, mitem) {
        it->setEnabled(false);
    }

    _panel1 = new QGraphicsRectItem(0,0,800,600);
    _panel1->setBrush(QBrush(QImage(":/images/menu.png")));
    _panel1->setOpacity(0.15);
    this->scene()->addItem(_panel1);

    _panel2 = new QGraphicsRectItem(300,200,200,200);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    _panel2->setBrush(brush);
    _panel2->setOpacity(0.75);
    this->scene()->addItem(_panel2);

    _gameOvr =new QGraphicsTextItem(QString("GameOver"));
    QFont titleFont("comic sans", 15);
    _gameOvr->setFont(titleFont);
    int tXpos = rect().width()/2 - _gameOvr->boundingRect().width()/2;
    int tYpos = 195;
    _gameOvr->setPos(tXpos,tYpos);
    scene()->addItem(_gameOvr);
    _playg = new QPushButton(QString("Play"));
    _playg->setGeometry(rect().width()/2 - 50,225,100,60);
    scene()->addWidget(_playg);
    delete _health;
    delete _score;
//    delete _foot;
    connect(_playg,SIGNAL(clicked()),this,SLOT(start()));
    _cancelg = new QPushButton(QString("Quit"));
    _cancelg->setGeometry(rect().width()/2 - 50,315,100,60);
    scene()->addWidget(_cancelg);
    connect(_cancelg,SIGNAL(clicked()),this,SLOT(close()));

    return;
}

void Game::start_timer()
{
    timer->start(2000);
//    map_timer->start(6760);
}

void Game::stop_timer()
{
    timer->stop();
//    map_timer->stop();
//    timer_for_start->stop();
    return;
}

MyMap *Game::active_map()
{
    return _active_map;
}

MyMap *Game::next_map()
{
    return _next_map;
}

Map_start *Game::start_map()
{
    return _start_map;
}

void Game::make_next_map()
{
    _next_map = new MyMap(1);
    return;
}

void Game::initial_map()
{
    _start_map = new Map_start();
    scene()->addItem(start_map()->left());
    scene()->addItem(start_map()->right());

    _active_map = new MyMap(3);
    scene()->addItem(active_map()->left());
    scene()->addItem(active_map()->right());
    if(active_map()->mid()!=0)
        scene()->addItem(active_map()->mid());

//    for(int i=0;i<4;i++)
//    {
//        if(active_map()->smoother_left()[i]!=0)
//            scene()->addItem(active_map()->smoother_left()[i]);
//        if(active_map()->smoother_right()[i]!=0)
//            scene()->addItem(active_map()->smoother_right()[i]);
//        if(active_map()->smoother_mid()[i]!=0)
//            scene()->addItem(active_map()->smoother_mid()[i]);
    //    }
}

QGraphicsTextItem *Game::titleText()
{
    return _titleText;
}

void Game::create_map()
{
    if(counter % 5 == 0 || counter % 5 == 4)
        _active_map = new MyMap(1);
    else
        _active_map = new MyMap(0);
    if(counter % 5 == 0)
    {
        Map_start *start = new Map_start();
        scene()->addItem(start->left());
        scene()->addItem(start->right());
        scene()->addItem(start->bridge());
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            if(active_map()->smoother_left()[i]!=0)
                scene()->addItem(active_map()->smoother_left()[i]);
            if(active_map()->smoother_right()[i]!=0)
                scene()->addItem(active_map()->smoother_right()[i]);
//            if(active_map()->smoother_mid()[i]!=0)
//                scene()->addItem(active_map()->smoother_mid()[i]);
        }
    }
    scene()->addItem(active_map()->left());
    scene()->addItem(active_map()->right());
    if(active_map()->mid()!=0)
        scene()->addItem(active_map()->mid());
    for(int i=0;i<4;i++)
    {
        if(active_map()->smoother_mid_s()[i] != 0)
            scene()->addItem(active_map()->smoother_mid_s()[i]);
        if(active_map()->smoother_mid_e()[i] != 0)
            scene()->addItem(active_map()->smoother_mid_e()[i]);
    }

    counter++;
}

void Game::stop_the_map()
{
    this->active_map()->stop_timer();
    this->start_map()->stop_timer();
//    timer_for_start->stop();
    this->_airplane->setFlag(QGraphicsItem::ItemIsFocusable);
    this->_airplane->setFocus();
}

void Game::dispalyMenu() {
    _titleText =new QGraphicsTextItem(QString("RiverRaid"));
    this->setBackgroundBrush(QBrush(QImage(":/images/menu.png")));
    QFont titleFont("comic sans", 50);    
    _titleText->setFont(titleFont);
    int tXpos = rect().width()/2 - _titleText->boundingRect().width()/2;
    int tYpos = 150;
    _titleText->setPos(tXpos,tYpos);
    scene()->addItem(_titleText);
    _play = new QPushButton(QString("Play"));
    _play->setGeometry(rect().width()/2 - 50,250,100,60);
    scene()->addWidget(_play);
    connect(_play,SIGNAL(clicked()),this,SLOT(start()));
    _cancel = new QPushButton(QString("Quit"));
    _cancel->setGeometry(rect().width()/2 - 50,350,100,60);
    scene()->addWidget(_cancel);
    connect(_cancel,SIGNAL(clicked()),this,SLOT(close()));
}

void Game::dec_health()
{
    _health->dec_health();
    QList<QGraphicsItem*> mitem = _scene->items();
    //health,score,foot,aiplane
    for(int i =0 ;i<mitem.size();i++) {
        if((typeid(*mitem[i]) != typeid(Airplane)) && (typeid(*mitem[i]) != typeid(Score)) && (typeid(*mitem[i]) != typeid(Health)) && (typeid(*mitem[i]) != typeid(Footer)) &&  (typeid(*mitem[i]) != typeid(QGraphicsPixmapItem)))
        {
            this->scene()->removeItem(mitem[i]);
        }
    }
    if(_health->get_health() == 0) {
        game_over();
        return;
    }
    restart();

//    this->scene()->addItem(this->_airplane);
}

void Game::restart()
{
        _airplane->setPos(380,550-115);
        _airplane->re_fuel();
//        delete active_map();
//        stop_the_map();
        stop_timer();
        this->active_map()->stop_timer();
        _airplane->getTimer()->stop();
        _airplane->getTimer2()->stop();
        this->_foot->setFlag(QGraphicsItem::ItemIsFocusable);
        this->_foot->setFocus();
        _airplane->setStart(1);
        _airplane->setPixmap(QPixmap(":/images/ap.png"));
        initial_map();
}

void Game::start()
{
    counter = 1;
//    _scene->clear();
   QList<QGraphicsItem*> mitem = _scene->items();
   foreach (QGraphicsItem* it, mitem) {
       _scene->removeItem(it);       
   }      
    this->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    this->_airplane = new Airplane();
    //must change and enhance
//    this->_airplane->setFlag(QGraphicsItem::ItemIsFocusable);
//    this->_airplane->setFocus();
    this->_airplane->setZValue(10);
    this->scene()->addItem(this->_airplane);
    this->_airplane->setStart(1);

//    this->bgsound = new QMediaPlayer();
//    this->bgsound->setMedia(QUrl("qrc:/sounds/bg.mp3"));
//    this->bgsound->play();

    //set foot
//    _foot = new Footer();
    this->scene()->addItem(this->_foot);
    this->scene()->addItem(this->_foot->slider());
    this->_foot->setZValue(10);
    this->_foot->set_slider_pos();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(make_enemy()));
    connect(timer, SIGNAL(timeout()), this, SLOT(make_house()));
//    timer->start(2000);

    _score = new Score();
    scene()->addItem(_score);

    _health = new Health();
    scene()->addItem(_health);

    this->initial_map();

//    timer_for_start = new QTimer();
//    connect(timer_for_start, SIGNAL(timeout()),this, SLOT(stop_the_map()));
//    timer_for_start->start(5050);

}

QPushButton *Game::getCancelg() const
{
    return _cancelg;
}

QPushButton *Game::getPlayg() const
{
    return _playg;
}

QGraphicsTextItem *Game::getGameOvr() const
{
    return _gameOvr;
}

QGraphicsRectItem *Game::getPanel2() const
{
    return _panel2;
}

QGraphicsRectItem *Game::getPanel1() const
{
    return _panel1;
}

QPushButton *Game::cancel() const
{
    return _cancel;
}

QPushButton *Game::play() const
{
    return _play;
}


void Game::make_enemy()
{
    int a=((int)qrand())%4;
    if(a == 0)
        scene()->addItem(new Boat());
    else if(a == 1) {
        scene()->addItem(new Fuel_depot());
        qDebug() << "fuel deput added";
    }
    else if(a == 2)
        scene()->addItem(new Jet());
    else if(a == 3)
        scene()->addItem(new Helicopter());
    if(counter >= 3) {
        int a=((int)qrand())%5;
        if(a == 0)
            scene()->addItem(new Boat());
        else if(a == 1) {
            scene()->addItem(new Fuel_depot());
            qDebug() << "fuel deput added";
        }
        else if(a == 2)
            scene()->addItem(new Jet());
        else if(a == 3)
            scene()->addItem(new Helicopter());
        else if(a == 4)
            scene()->addItem(new Balloon());
    }

    return;
}

void Game::make_house()
{
    int a=((int)qrand())%4;
    if(a !=0 )
        scene()->addItem(new House());
}
