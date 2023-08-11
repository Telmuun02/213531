#ifndef SCENE_H
#define SCENE_H


#include <vector>

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QDebug>

#include <point.h>


class GraphicsScene : public QGraphicsScene {
    Q_OBJECT

    public:
        explicit GraphicsScene(QObject *parent = nullptr);
        ~GraphicsScene();

    // Attributes
    public:
        Point* point;

};


#endif // SCENE_H
