#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QDebug>

#include <point.h>
#include <image.h>


class GraphicsScene : public QGraphicsScene {
    Q_OBJECT

    public:
        explicit GraphicsScene(QObject *parent = nullptr);
        ~GraphicsScene();

    // Attributes
    public:
        Image* img;
        Point* point;

    private:
        bool isClicked;
        static Point* initialPoint;
        static std::vector<Point*> points;
        bool isDrawingEnabled;
        bool isDraggingEnabled;

    // Methods
    public:
        void enableDrawing();
        void enableDragging();
        void disableDrawing();
        void disableDragging();
        static void clearPointer();
        static void deletePointers();
        static std::vector<Point*> getPointers();


    private:
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};


#endif // SCENE_H
