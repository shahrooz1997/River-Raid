#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
//#include <QMediaPlayer>
#include "footer.h"
#include <QTimer>
#include "enemy.h"
#include "airplane.h"
#include "boat.h"
#include "score.h"
#include "health.h"
#include "jet.h"
#include "helicopter.h"
#include "fuel_depot.h"
#include "map_start.h"
#include "road.h"
#include "bridge.h"
#include "mymap.h"
#include "wall.h"
#include "QPushButton"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game();
    QGraphicsScene* scene();
    Airplane* airplane();
    Footer *foot();
    Score *score();
    Health *health();
    ~Game();
    void game_over();
    void dispalyMenu();
    void dec_health();
    void restart();
    void start_timer();
    void stop_timer();
    MyMap *active_map();
    MyMap *next_map();
    Map_start *start_map();
    void initial_map();
    QGraphicsTextItem *titleText();
public slots:
    void make_enemy();
    void create_map();
    void stop_the_map();
    void start();

private:
    Airplane *_airplane;
    QGraphicsScene *_scene;
//    QMediaPlayer *bgsound;
    Footer *_foot;
    QTimer *timer;
    Score *_score;
    Health *_health;
    QTimer *map_timer;
    MyMap *_active_map;
    MyMap *_next_map;
    QTimer *timer_for_start;
    Map_start* _start_map;
    QGraphicsTextItem *_titleText;
};


#endif // GAME_H
