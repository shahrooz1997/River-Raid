#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem *parent = 0);
    int get_score();
    void inc_score(int a);
private:
    int score;
};

#endif // SCORE_H
