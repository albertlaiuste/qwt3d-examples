#include "mainwindow.h"

#include "widgets/mainpanel.h"

namespace Qwt3DExamples {

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow{parent},
    m_panel{new MainPanel(this)}
{
    setCentralWidget(m_panel);
}

}
