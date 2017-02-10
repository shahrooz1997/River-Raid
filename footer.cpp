#include "footer.h"


Footer::Footer()
{
    //set the graphic
    setPixmap(QPixmap(":/images/bottom.png"));
    setPos(-56,485);

    // set slider
    _slider = new QGraphicsPixmapItem();
    _slider->setPixmap(QPixmap(":/images/slider.png"));
    _slider->setPos(490, 533);
    _slider->setZValue(11);
}

void Footer::keyPressEvent(QKeyEvent *event)
{
    return;
}

QGraphicsPixmapItem *Footer::slider()
{
    return _slider;
}

void Footer::set_slider_pos()
{
    _slider->setPos(490, 533);
    return;
}
