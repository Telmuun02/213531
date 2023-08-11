#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include <menuwindow.h>
#include <screenwindow.h>


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
        QStackedWidget *stackedWidget;
        MenuWindow *menuWindow;
        ScreenWindow *screenWindow;

    // Methods
    private:
        void initUI();

    private slots:
        void slotOpenScreenWindow(QString name);


};
#endif // MAINWINDOW_H
