#ifndef POINT_H
#define POINT_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsSceneEvent>
#include <QGraphicsScene>
#include <QMessageBox>
#include <vector>


class ClickPoint : public QGraphicsEllipseItem {
    public:
        explicit ClickPoint(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
        ~ClickPoint();

    private:
        bool isClicked;
        static ClickPoint* initialPoint;
        static std::vector<ClickPoint*> points;

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};


#endif // POINT_H
