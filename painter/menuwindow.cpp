#include <menuwindow.h>


MenuWindow::MenuWindow(QWidget *parent) : QWidget(parent) {
    initUI();
}

MenuWindow::~MenuWindow() {
    delete gridLayout;
    delete verticalLayout;
    delete header;
    delete button;
}


void MenuWindow::initUI() {
    verticalLayout = new QVBoxLayout(this);

    header = new QLabel("List of Images");
    header->setAlignment(Qt::AlignHCenter);
    verticalLayout->addWidget(header);

    gridLayout = new QGridLayout;

    QStringList files = retrieveImagesFromFiles();
    qint16 lenFiles = files.length();
    if (lenFiles <= 0) {
        return;
    }

    for (int i = 0; i < lenFiles; i++) {
        QString nameButton = files[i].split('.').first();
        button = new QPushButton(nameButton);
        connect(button, &QPushButton::clicked, this, [this, nameButton]() {
            emit signalOpenScreenWindow(nameButton);
        });
        gridLayout->addWidget(button);
    }

    verticalLayout->addLayout(gridLayout);
}

QStringList MenuWindow::retrieveImagesFromFiles() {
    QDir directory(path);
    QStringList listDir = directory.entryList(QStringList() << "*.bin" << "*.BIN", QDir::Files);
    return listDir;
}
