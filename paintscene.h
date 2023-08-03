#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>

class PaintScene : public QGraphicsScene {
    Q_OBJECT

    public:
        explicit PaintScene(QObject *parent = nullptr);
        ~PaintScene();

    private:
        QList<QPointF> lines;
        int lineCounter = 0;

    private:
        //void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
