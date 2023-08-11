#ifndef POINT_H
#define POINT_H

#include <vector>

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneHoverEvent>
#include <QPainter>
#include <QPair>


class Point : public QGraphicsEllipseItem {
    public:
        explicit Point(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
        ~Point();

    // Attributes
    public:
        qint16 posX;
        qint16 posY;

    private:
        static int index;
        static std::vector<QPointF> lines;

    // Methods
    private:
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
};


#endif // POINT_H
