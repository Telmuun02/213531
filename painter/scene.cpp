#include "scene.h"


GraphicsScene::GraphicsScene(QObject *parent) : QGraphicsScene(parent) {}

GraphicsScene::~GraphicsScene() {
    delete point;
}

