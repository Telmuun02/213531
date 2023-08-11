#include "point.h"


int Point::index = 0;
std::vector<QPointF> Point::lines;


Point::Point(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsEllipseItem(x, y, width, height, parent) {
    setAcceptHoverEvents(true);
}

Point::~Point() {}


void Point::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        setBrush(Qt::black);
        if (lines.empty()) {
            lines.push_back(event->scenePos());
        } else {
            QGraphicsLineItem* line = new QGraphicsLineItem(
                this->rect().center().x(),
                this->rect().center().y(),
                lines.at(index - 1).x(),
                lines.at(index - 1).y()
            );
            scene()->addItem(line);
            lines.push_back(event->scenePos());
        }
        index += 1;
    }
}
