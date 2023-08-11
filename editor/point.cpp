#include "point.h"


Point::Point(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsEllipseItem(x, y, width, height, parent) {
    setAcceptHoverEvents(true);

    posX = x;
    posY = y;
}

Point::~Point() {}
