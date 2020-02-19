#include "simpleplot.h"

namespace Qwt3DExamples::SimplePlot {

Rosenbrock::Rosenbrock(GridPlot &pw)
    :Function(pw)
{}

double Rosenbrock::operator()(double x, double y)
{
    return log((1-x)*(1-x) + 100 * (y - x*x)*(y - x*x)) / 8;
}

Qwt3DExamples::SimplePlot::Plot::Plot()
{
    setTitle("A Simple GridPlot Demonstration");

    Rosenbrock rosenbrock(*this);

    rosenbrock.setMesh(100,100);    // 200000 polys
    rosenbrock.setDomain(-1.73,1.5,-1.5,1.5);
    rosenbrock.setMinZ(-10);

    rosenbrock.create();

    setRotation(30,0,15);
    setScale(2,2,1.2);
    setShift(0.15,0,0);
    setZoom(0.6);

    for (unsigned i=0; i!=coordinates()->axes.size(); ++i)
    {
        coordinates()->axes[i].setMajors(7);
        coordinates()->axes[i].setMinors(4);
    }


    coordinates()->axes[X1].setLabelString("x-axis");
    coordinates()->axes[Y1].setLabelString("y-axis");
    //coordinates()->axes[Z1].setLabelString(QChar(0x38f)); // Omega - see http://www.unicode.org/charts/


    setCoordinateStyle(BOX);

    updateData();
    updateGL();
}

}
