#ifndef HOUSE_H
#define HOUSE_H


#include <QGraphicsItem>
#include <QTimer>
#include <QGraphicsPixmapItem>


class House : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    House(QGraphicsItem *parent=0);
    ~House();
public slots:
    void move();
protected:
    QTimer *timer;
};

#endif // HOUSE_H
