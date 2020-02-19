#include "mainpanel.h"

#include <QHBoxLayout>
#include <QSplitter>

#include "examples/dynamicplot/dynamicplot.h"
#include "examples/simpleplot/simpleplot.h"
#include "examples/autoswitch/autoswitch.h"
#include "examples/freemesh/freemesh.h"
#include "examples/graph/graph.h"
#include "examples/volumeplot/volumeplot.h"

namespace Qwt3DExamples {

MainPanel::MainPanel(QWidget* parent) :
    QWidget{parent},
    m_tabWidget{new QTabWidget(this)}
{
    setupStyle();
    setupLayout();
    setupDynamicPlot();
    setupSimplePlot();
    setupAutoSwitch();
    setupFreeMesh();
    setupGraph();
    setupVolumePlot();
}

void MainPanel::setupStyle()
{
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    setAutoFillBackground(true);
    setPalette(pal);
}

void MainPanel::setupLayout()
{
    setMinimumSize(1024, 768);

    auto l = new QHBoxLayout(this);
    l->addWidget(m_tabWidget);
}

void MainPanel::setupDynamicPlot()
{
    auto dynamicPlot = new DynamicPlot::Plot;
    m_tabWidget->addTab(dynamicPlot, "Dynamic Plot");
}

void MainPanel::setupSimplePlot()
{
    auto simplePlot = new SimplePlot::Plot;
    m_tabWidget->addTab(simplePlot, "Simple Plot");
}

void MainPanel::setupAutoSwitch()
{
    auto spl = new QSplitter(Qt::Horizontal);
    auto plot1 = new AutoSwitch::Plot(spl, 30);
    plot1->setFloorStyle(FLOORISO);
    plot1->setCoordinateStyle(BOX);
    AutoSwitch::Saddle saddle(*plot1);
    saddle.create();
    plot1->setTitle("Autoswitching axes");
    plot1->makeCurrent();
    plot1->updateData();
    plot1->updateGL();


    auto plot2 = new AutoSwitch::Plot(spl, 80);
    plot2->setZoom(0.8);
    AutoSwitch::Hat hat(*plot2);
    hat.create();
    plot2->setPlotStyle(HIDDENLINE);
    plot2->setFloorStyle(FLOORDATA);
    plot2->setCoordinateStyle(FRAME);
    plot2->makeCurrent();
    plot2->updateData();
    plot2->updateGL();

    spl->show();
    m_tabWidget->addTab(spl, "AutoSwitching Axes");
}

void MainPanel::setupFreeMesh()
{
    auto freeMesh = new FreeMesh::Plot(this);
    m_tabWidget->addTab(freeMesh, "FreeMesh");
}

void MainPanel::setupGraph()
{
    auto graph = new Graph::Plot;
    graph->create();
    m_tabWidget->addTab(graph, "Graph");
}

void MainPanel::setupVolumePlot()
{
    auto volumePlot = new VolPlot::Plot;
    m_tabWidget->addTab(volumePlot, "Volume Plot");
}

}
