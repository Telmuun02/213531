#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new PaintScene();
    ClickPoint *point_1 = new ClickPoint(300, 300, 20, 20);
    point_1->setBrush(Qt::blue);
    scene->addItem(point_1);

    ClickPoint *point_2 = new ClickPoint(500, 440, 20, 20);
    point_2->setBrush(Qt::blue);
    scene->addItem(point_2);

    ClickPoint *point_3 = new ClickPoint(700, 200, 20, 20);
    point_3->setBrush(Qt::blue);
    scene->addItem(point_3);

    ClickPoint *point_4 = new ClickPoint(500, 740, 20, 20);
    point_4->setBrush(Qt::blue);
    scene->addItem(point_4);

    ClickPoint *point_5 = new ClickPoint(100, 200, 20, 20);
    point_5->setBrush(Qt::blue);
    scene->addItem(point_5);

    ui->graphicsView->setScene(scene);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimer() {
    timer->stop();
    scene->setSceneRect(0, 0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    timer->start(100);
    QWidget::resizeEvent(event);
}

void MainWindow::resizeWindow() {
    QSize availableSize = qApp->desktop()->availableGeometry().size();
    int width = availableSize.width();
    int height = availableSize.height();

    QSize minSize(width * 0.8, height * 0.8);
    setMinimumSize(minSize);
    setMaximumSize(width, height);

    //QSize mwSize = qApp->screens()[0]->size();
    //QSize mwSize = this->size();
    ui->graphicsView->setMinimumWidth(width - 100);
    //ui->pushButton->setMaximumWidth(width * 0.2);


    QWidget::setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); // TEMPORARY
}
