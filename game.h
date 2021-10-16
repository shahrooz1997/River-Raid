#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "footer.h"
#include <QTimer>
#include "enemy.h"
#include "airplane.h"
#include "boat.h"
#include "score.h"
#include "health.h"
#include "jet.h"
#include "balloon.h"
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
    void make_next_map();
    void initial_map();
    QGraphicsTextItem *titleText();
    QPushButton *play() const;

    QPushButton *cancel() const;

    QGraphicsRectItem *getPanel1() const;

    QGraphicsRectItem *getPanel2() const;

    QGraphicsTextItem *getGameOvr() const;

    QPushButton *getPlayg() const;

    QPushButton *getCancelg() const;

public slots:
    void make_enemy();
    void make_house();
    void create_map();
    void stop_the_map();
    void start();

private:
    Airplane *_airplane;
    QGraphicsScene *_scene;
    QMediaPlayer *bgsound;
    Footer *_foot;
    QTimer *timer;
    Score *_score;
    QGraphicsRectItem* _panel2;
    Health *_health;
    QPushButton* _play;
    QPushButton *_cancelg;
    QGraphicsRectItem *_panel1;
    QGraphicsTextItem* _gameOvr;
    QPushButton *_playg;
    QPushButton* _cancel;
    QTimer *map_timer;
    MyMap *_active_map;
    MyMap *_next_map;
    QTimer *timer_for_start;
    Map_start* _start_map;
    QGraphicsTextItem *_titleText;
    int counter;
};


#endif // GAME_H
