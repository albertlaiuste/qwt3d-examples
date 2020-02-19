#pragma once
	
#include <QEvent>

#include "qwt3d/qwt3d_meshplot.h"

using namespace Qwt3D;
namespace Qwt3DExamples::FreeMesh {
class Plot : public MeshPlot
{
  Q_OBJECT

public:
  Plot(QWidget* parent);
  void contextMenuEvent(QContextMenuEvent* e);

public slots:
  void showTetrahedron();
  void showCone();
  void openMesh();

private:
  void setSomeThings();
  void createCone(TripleVector& conepos, CellVector& conecell);
  void createTetrahedron(TripleVector& pos, CellVector& poly);
};

}

