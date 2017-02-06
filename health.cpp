#include "health.h"
#include <QFont>


Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //initialize the health
    health = 3;

    //draw the text
    QColor c;
    c.setRgb(232,232,92);
    setPlainText(QString::number(health));
    setDefaultTextColor(c);
    QFont f("consolas", 24);
    f.setBold(1);
    setFont(f);

    setPos(268, 564);
    setZValue(11);
}

int Health::get_health()
{
    return health;
}

void Health::dec_health()
{
    health -= 1;
    return;
}
