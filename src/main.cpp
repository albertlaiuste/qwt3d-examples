#include <QApplication>

#include "mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Qwt3DExamples::MainWindow mainWindow;

    mainWindow.show();

    return app.exec();
}
