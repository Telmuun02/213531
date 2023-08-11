#include <screenwindow.h>


ScreenWindow::ScreenWindow(QWidget *parent) : QWidget(parent) {
    initUI();
}

ScreenWindow::~ScreenWindow() {
    delete verticalLayout;
    delete button;
    delete view;
    delete scene;
    delete timer;
    delete point;
}


void ScreenWindow::drawImage(QString name) {
    QString filename = path + name + ".bin";
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QDataStream in(&file);
    QString title;
    qint16 size;
    qint16 posX;
    qint16 posY;
    in >> title >> size;
    std::vector<Point*> points;
    for (int i = 0; i < size; i++) {
        in >> posX;
        in >> posY;
        Point *point = new Point(posX, posY, 20, 20);
        scene->addItem(point);
        points.push_back(point);
    }

    for (auto p : points) {
        qDebug() << p->rect().center().x() << " " << p->rect().center().y();
    }


    file.close();
}


void ScreenWindow::initUI() {
    verticalLayout = new QVBoxLayout(this);
    button = new QPushButton("Check");
    view = new QGraphicsView();

    verticalLayout->addWidget(button);
    verticalLayout->addWidget(view);

    scene = new GraphicsScene();
    view->setScene(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->resetMatrix();
    view->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &ScreenWindow::slotTimer);
    timer->start(100);
}


void ScreenWindow::slotTimer() {
    timer->stop();
    scene->setSceneRect(
        0, 0,
        view->width() - 20,
        view->height() - 20
    );
}
