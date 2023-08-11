#ifndef POINT_H
#define POINT_H


#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneHoverEvent>
#include <QPainter>
#include <QByteArray>
#include <QDataStream>


class Point : public QGraphicsEllipseItem {
    public:
        explicit Point(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
        ~Point();

    // Attributes
    public:
        qint16 posX;
        qint16 posY;
};


#endif // POINT_H
