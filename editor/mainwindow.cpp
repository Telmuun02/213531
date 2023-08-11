#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pencilButton->setCheckable(true);
    ui->handButton->setCheckable(true);

    setWindowTitle("Editor");
    setWindowState(Qt::WindowMaximized);
    setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    // Setting GraphicsScene
    scene = new GraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Setting Timer
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);

    // Setting Menu Bar
    setMenuBar();

    // Pencil tool is active
    ui->pencilButton->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete referenceImage;
    delete timer;

    GraphicsScene::deletePointers();
}


void MainWindow::setMenuBar() {
    QPixmap newIcon(":/new");
    QPixmap openIcon(":/open");
    QPixmap saveIcon(":/save");
    QPixmap quitIcon(":/quit");

    QAction *newAction = new QAction(newIcon, "&New", this);
    QAction *openAction = new QAction(openIcon, "&Open", this);
    QAction *saveAction = new QAction(saveIcon, "&Save", this);
    QAction *quitAction = new QAction(quitIcon, "&Close", this);

    newAction->setShortcut(tr("CTRL+N"));
    openAction->setShortcut(tr("CTRL+O"));
    saveAction->setShortcut(tr("CTRL+S"));
    quitAction->setShortcut(tr("CTRL+Q"));

    QMenu *file = menuBar()->addMenu("&File");
    file->addAction(newAction);
    file->addAction(openAction);
    file->addAction(saveAction);
    file->addSeparator();
    file->addAction(quitAction);

    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);
    connect(newAction, &QAction::triggered, this, &MainWindow::slotNewFile);
    connect(openAction, &QAction::triggered, this, &MainWindow::slotOpenImage);
    connect(saveAction, &QAction::triggered, this, &MainWindow::slotSavePoints);
    connect(quitAction, &QAction::triggered, this, &QApplication::quit);
}


void MainWindow::slotTimer() {
    timer->stop();
    scene->setSceneRect(
                0, 0,
                ui->graphicsView->width() - 20,
                ui->graphicsView->height() - 20
    );
}


void MainWindow::slotNewFile() {
    GraphicsScene::clearPointer();
    scene->clear();
}


void MainWindow::slotOpenImage() {
    QString filename = QFileDialog::getOpenFileName(nullptr, "Choose an Image", "", "Images (*.png *.jpg *.jpeg)");
    if (!filename.isEmpty()) {
        QPixmap image(filename);
        if (!image.isNull()) {
            referenceImage = new Image(image);
            referenceImage->setZValue(-1);
            referenceImage->setOpacity(0.8);
            scene->addItem(referenceImage);
            scene->img = referenceImage;
        } else {
            QMessageBox::warning(nullptr, "Error", "Invalid file type. Please choose an Image file!");
        }
    }
}


void MainWindow::slotSavePoints() {
    qint16 n = 1;
    QString projName = "/home/dev/projects/editor/bin/project_" + QString::number(n) + ".bin";
    while (QFile::exists(projName)) {
        n += 1;
        projName = "/home/dev/projects/editor/bin/project_" + QString::number(n) + ".bin";
    }

    QString filename = QFileDialog::getSaveFileName(nullptr, "Save a file", projName, "Binary File (*.bin)");
    if (!filename.isEmpty()) {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(nullptr, tr("Unable to open file"), file.errorString());
            return;
        }

        QString title = filename.split('/').last().split('.').first();
        qint16 vectorSize = GraphicsScene::getPointers().size();

        QDataStream outStream(&file);
        outStream << title;
        outStream << vectorSize;

        for (auto point : GraphicsScene::getPointers()) {
            qint16 x = point->rect().center().x();
            qint16 y = point->rect().center().y();
            outStream << x;
            outStream << y;
        }

        file.close();
    }
}


void MainWindow::on_pencilButton_toggled(bool checked) {
    if (checked) {
        scene->enableDrawing();
        ui->handButton->setChecked(false);
        return;
    }

    scene->disableDrawing();
}


void MainWindow::on_handButton_toggled(bool checked) {
    if (checked) {
        scene->enableDragging();
        ui->pencilButton->setChecked(false);
        return;
    }

    scene->disableDragging();
}

