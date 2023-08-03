#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>

#include <paintscene.h>
#include <point.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void resizeWindow();

    private:
        Ui::MainWindow *ui;
        QTimer *timer;
        PaintScene *scene;

    private:
        void resizeEvent(QResizeEvent *event);

    private slots:
        void slotTimer();

};
#endif // MAINWINDOW_H
