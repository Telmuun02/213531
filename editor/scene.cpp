#include "scene.h"


// Static variables
Point* GraphicsScene::initialPoint = nullptr;
std::vector<Point*> GraphicsScene::points;


GraphicsScene::GraphicsScene(QObject *parent) : QGraphicsScene(parent), isClicked(false) {
    isDrawingEnabled = true;
    isDraggingEnabled = false;
    img = nullptr;
}

GraphicsScene::~GraphicsScene() {
    delete img;
    delete point;
}


void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (isDrawingEnabled && event->button() == Qt::LeftButton) {
        QPointF scenePos = event->scenePos();
        point = new Point(
                    scenePos.x() - 10, scenePos.y() - 10,
                    20, 20
                );
        addItem(point);

        if (points.empty()) {
            initialPoint = point;
            isClicked = true;
            points.push_back(point);
        } else {
            QGraphicsLineItem *line = new QGraphicsLineItem(
                point->rect().center().x(),
                point->rect().center().y(),
                initialPoint->rect().center().x(),
                initialPoint->rect().center().y()
            );
            addItem(line);
            initialPoint = point;
            points.push_back(point);
        }


        event->accept();
    } else if (isDraggingEnabled && event->button() == Qt::LeftButton) {
        if (img != nullptr) {
            img->setCursorClosedHand();
        }
        event->accept();
    }
}


void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (isDraggingEnabled && event->buttons() == Qt::LeftButton) {
        if (img != nullptr) {
            img->setPos(event->scenePos() - event->lastPos());
            event->accept();
        }
    }
}


void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (isDraggingEnabled && img != nullptr) {
        img->setCursorOpenHand();
        event->accept();
    }
}


void GraphicsScene::enableDrawing() {
    isDrawingEnabled = true;
    isDraggingEnabled = false;
}


void GraphicsScene::enableDragging() {
    isDrawingEnabled = false;
    isDraggingEnabled = true;
}


void GraphicsScene::disableDrawing() {
    isDrawingEnabled = false;
}


void GraphicsScene::disableDragging() {
    isDraggingEnabled = false;
}

void GraphicsScene::deletePointers() {
    delete GraphicsScene::initialPoint;
    if (!GraphicsScene::points.empty()) {
        for (auto p : GraphicsScene::points) {
            delete p;
        }
    }
    GraphicsScene::points.clear();
}

void GraphicsScene::clearPointer() {
    GraphicsScene::initialPoint = nullptr;
    GraphicsScene::points.clear();
}

std::vector<Point*> GraphicsScene::getPointers() {
    return GraphicsScene::points;
}
