#ifndef SCREENWINDOW_H
#define SCREENWINDOW_H

#include <vector>

#include <QWidget>
#include <QLabel>
#include <QFile>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGraphicsView>
#include <QTimer>
#include <QPainter>

#include <scene.h>
#include <point.h>


class ScreenWindow : public QWidget {

    Q_OBJECT

    public:
        explicit ScreenWindow(QWidget *parent = nullptr);
        ~ScreenWindow();

    // Window Components
    private:
        QVBoxLayout *verticalLayout;
        QPushButton *button;
        QGraphicsView *view;

    // Attributes
    private:
        GraphicsScene *scene;
        QTimer *timer;
        Point *point;
        const QString path = "/home/dev/projects/editor/bin/";

    // Methods
    public:
        void drawImage(QString name);

    private:
        void initUI();

    private slots:
        void slotTimer();
    };


#endif // SCREENWINDOW_H
