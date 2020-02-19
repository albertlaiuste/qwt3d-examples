#pragma once

#include <QWidget>
#include <QTabWidget>

namespace Qwt3DExamples {
class MainPanel : public QWidget
{
    Q_OBJECT

public:
    MainPanel(QWidget* parent = nullptr);

private:
    void setupStyle();
    void setupLayout();
    void setupDynamicPlot();
    void setupSimplePlot();
    void setupAutoSwitch();
    void setupFreeMesh();
    void setupGraph();
    void setupVolumePlot();

private:
    QTabWidget* m_tabWidget;
};

}
