#pragma once

#include "qwt3d/qwt3d_graphplot.h"

using namespace Qwt3D;
namespace Qwt3DExamples::Graph {
class Plot : public GraphPlot
{
public:
    Plot();
    void create();

private:
    void createCube(double length, const Triple& shift);
    void createCubic1();
    void createCubic2();
    void createCubic3();

    TripleVector nodes;
    EdgeVector edges;
};

}
