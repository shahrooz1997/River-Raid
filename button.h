#ifndef BUTTON_H
#define BUTTON_H

#include <QtCore>
#include <QtGui>

class Button
//        : public QGraphicsRectItem
{   
//    Q_Object
public:    
    Button(QString name, QGraphicsItem* parent = 0);

//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
//    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
//    QGraphicsTextItem *text;
signals:
//    void clicked();
};

#endif // BUTTON_H
