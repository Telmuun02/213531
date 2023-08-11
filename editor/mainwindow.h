#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include <QDataStream>
#include <QByteArray>
#include <QDebug>

#include <point.h>
#include <image.h>
#include <scene.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    // Attributes
    private:
        Ui::MainWindow *ui;
        GraphicsScene *scene;
        Image *referenceImage;
        QTimer *timer;

    // Methods
    private:
        void setMenuBar();

    private slots:
        void slotTimer();
        void slotNewFile();
        void slotOpenImage();
        void slotSavePoints();
        void on_pencilButton_toggled(bool checked);
        void on_handButton_toggled(bool checked);
};
#endif // MAINWINDOW_H
