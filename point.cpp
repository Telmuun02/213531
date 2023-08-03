#include "point.h"

ClickPoint::ClickPoint(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent) : QGraphicsEllipseItem(x, y, width, height, parent) {}
ClickPoint::~ClickPoint() {}

void ClickPoint::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        QMessageBox::information(nullptr, "Info", "Clicked");
    }
    QGraphicsEllipseItem::mousePressEvent(event);
}
