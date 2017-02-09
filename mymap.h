#ifndef MYMAP_H
#define MYMAP_H

#include "wall.h"
#include <QTimer>

class MyMap: public QObject
{
    Q_OBJECT
public:
    MyMap(int help);
    int get_width();
    Wall *right();
    Wall *left();
    Wall *mid();
    Wall **smoother_left();
    Wall **smoother_right();
    Wall **smoother_mid();
    void start_timer();
    void stop_timer();
    ~MyMap();
    void set_before_state(bool a);
    int get_before_state();

    void set_smooth(int now);

public slots:
    void move();

private:
    Wall *_left;
    Wall *_right;
    Wall *_mid;
    Wall *_smoother_left[4];
    Wall *_smoother_right[4];
    Wall *_smoother_mid[4];
    QTimer *timer;

    static int before_state;

};

#endif // MYMAP_H
