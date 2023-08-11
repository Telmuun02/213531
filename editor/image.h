#ifndef IMAGE_H
#define IMAGE_H


#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>


class Image : public QGraphicsPixmapItem {
    public:
        Image(QPixmap &pixmap);
        ~Image();

    // Methods
    public:
        void setCursorOpenHand();
        void setCursorClosedHand();
};


#endif // IMAGE_H
