#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDir>
#include <QStringList>
#include <QDebug>


class MenuWindow : public QWidget {

    Q_OBJECT

    public:
        explicit MenuWindow(QWidget *parent = nullptr);
        ~MenuWindow();

    // Window Components
    private:
        QGridLayout *gridLayout;
        QVBoxLayout *verticalLayout;
        QLabel *header;
        QPushButton *button;

    // Attributes
    public:
        const QString path = "/home/dev/projects/editor/bin/";
        const QString chosenFilePath;

    // Methods
    public:

    private:
        void initUI();
        QStringList retrieveImagesFromFiles();

    private slots:

    // Signals
    signals:
        void signalOpenScreenWindow(QString name);
};

#endif // MENUWINDOW_H
