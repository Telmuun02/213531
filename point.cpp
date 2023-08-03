#include "point.h"

ClickPoint* ClickPoint::initialPoint = nullptr;
std::vector<ClickPoint*> ClickPoint::points;

ClickPoint::ClickPoint(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent) : QGraphicsEllipseItem(x, y, width, height, parent), isClicked(false) {}
ClickPoint::~ClickPoint() {}

void ClickPoint::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        this->setBrush(Qt::red);
        if (points.empty()) {
            initialPoint = this;
            isClicked = true;
            points.push_back(this);
        } else {
            QGraphicsLineItem* line = new QGraphicsLineItem(
                this->rect().center().x(),
                this->rect().center().y(),
                initialPoint->rect().center().x(),
                initialPoint->rect().center().y()
            );

            scene()->addItem(line);

            initialPoint = this;
            points.push_back(this);
        }
    }
    QGraphicsEllipseItem::mousePressEvent(event);
}

