#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QMediaPlayer>
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


class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget *parent=0);
    QGraphicsScene* scene();
    Airplane* airplane();
    Footer *foot();
    Score *score();
    Health *health();
    ~Game();
    void game_over();
    void create_map();

public slots:
    void make_enemy();

private:
    Airplane *_airplane;
    QGraphicsScene *_scene;
    QMediaPlayer *bgsound;
    Footer *_foot;
    QTimer *timer;
    Score *_score;
    Health *_health;
//    void exchange_map(int a, int b);
};


#endif // GAME_H
