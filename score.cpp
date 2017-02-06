#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //initialize the score
    score = 0;

    //draw the text
    QColor c;
    c.setRgb(232,232,92);
    setPlainText(QString::number(score));
    setDefaultTextColor(c);
    QFont f("consolas", 24);
    f.setBold(1);
    setFont(f);

    setPos(430, 482);
    setZValue(11);
}

int Score::get_score()
{
    return score;
}

void Score::inc_score(int a)
{
    score += a;
    setPlainText(QString::number(score));
    return;
}
