#pragma once

#include <math.h>

#include "qwt3d/qwt3d_gridplot.h"
#include "qwt3d/qwt3d_function.h"

using namespace Qwt3D;
namespace Qwt3DExamples::SimplePlot {
class Rosenbrock : public Function
{
public:
    Rosenbrock(GridPlot& pw);
    double operator()(double x, double y);
};

class Plot : public GridPlot
{
public:
    Plot();
};

}
