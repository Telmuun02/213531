#include "paintscene.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent) {}

PaintScene::~PaintScene() {}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    int len = lines.length();
    QColor black = Qt::black;
    QPen pen = QPen(black);
    pen.setWidth(2);

    if (event->buttons() == Qt::LeftButton) {
        QPointF point = QPointF(
            event->scenePos().x(),
            event->scenePos().y()
        );

        if (lines.empty()) {
            lines.push_back(point);
        } else {
            lines.push_back(point);
            clear();
            for (int i = 0; i < len; i++) {
                addLine(
                    lines[i].x(),
                    lines[i].y(),
                    lines[i + 1].x(),
                    lines[i + 1].y(),
                    pen
                );
            }
        }

        addEllipse(
            lines[0].x() - 5,
            lines[0].y() - 5,
            10, 10,
            QPen(Qt::NoPen),
            QBrush(black)
        );
    } else if (event->buttons() == Qt::RightButton) {
        if (len != 0) {
            lines.pop_back();
            clear();
            if (lines.empty()) return;
            for (int i = 0; i < len - 2; i++) {
                addLine(
                    lines[i].x(),
                    lines[i].y(),
                    lines[i + 1].x(),
                    lines[i + 1].y(),
                    pen
                );
            }
            addEllipse(
                lines[0].x() - 5,
                lines[0].y() - 5,
                10, 10,
                QPen(Qt::NoPen),
                QBrush(black)
            );
        }
    }

    previousPoint = event->scenePos();
}
