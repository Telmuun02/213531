#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();

    connect(menuWindow, &MenuWindow::signalOpenScreenWindow, this, &MainWindow::slotOpenScreenWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete stackedWidget;
    delete menuWindow;
    delete screenWindow;
}


void MainWindow::initUI() {
    setWindowTitle("Painter");
    setWindowState(Qt::WindowMaximized);
    setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    menuWindow = new MenuWindow();
    screenWindow = new ScreenWindow();

    stackedWidget->addWidget(menuWindow);
    stackedWidget->addWidget(screenWindow);

    stackedWidget->setCurrentIndex(0);
}


// SLOTS
void MainWindow::slotOpenScreenWindow(QString name) {
    stackedWidget->setCurrentIndex(1);
    screenWindow->drawImage(name);
}
