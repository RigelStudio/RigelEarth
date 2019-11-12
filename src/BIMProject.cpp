#include "BIMProject.h"
#include <osgDB/ReadFile>
#include <QMenuBar>
#include "MECore/OECore.h"
#include <osgDB/ReadFile>
#include <osg/DisplaySettings>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/StateSetManipulator>

BIMProject::BIMProject(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_pGraphicsView = new GraphicsView(this);
	setCentralWidget(m_pGraphicsView);
	OECore::ins()->init(m_pGraphicsView->getOSGViewer());
	osg::DisplaySettings::instance()->setNumMultiSamples(16);
	//initScene();
}

void BIMProject::initGUI()
{

}
