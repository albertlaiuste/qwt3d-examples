#pragma once

#include <QTimer>

#include "qwt3d/qwt3d_gridplot.h"
#include "qwt3d/qwt3d_function.h"

using namespace Qwt3D;
namespace Qwt3DExamples::AutoSwitch {
class Saddle : public Function
{
public:
    Saddle(GridPlot& pw);
    double operator()(double x, double y);
};

class Hat : public Function
{
public:
    Hat(GridPlot& pw);
    double operator()(double x, double y);
};

class Plot : public GridPlot
{
	Q_OBJECT

public:
    Plot(QWidget* pw, int updateinterval);

public slots:
	void rotate();

};
}
