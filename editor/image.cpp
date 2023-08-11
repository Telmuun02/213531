#include "image.h"


Image::Image(QPixmap &pixmap) : QGraphicsPixmapItem(pixmap) {
    setCursorOpenHand();
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

Image::~Image() {}


void Image::setCursorOpenHand() {
    setCursor(Qt::OpenHandCursor);
}


void Image::setCursorClosedHand() {
    setCursor(Qt::ClosedHandCursor);
}
