#ifndef POINT_H
#define POINT_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneEvent>
#include <QMessageBox>


class ClickPoint : public QGraphicsEllipseItem {
    public:
        explicit ClickPoint(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
        ~ClickPoint();

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};


#endif // POINT_H
