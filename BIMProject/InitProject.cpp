#include "InitProject.h"
#include "MeCore/FileUtils.h"
#include "MeCore/OECore.h"
#include "MeDB/LayerMgr.h"
#include <QDir>

InitProject::InitProject()
{
}


InitProject::~InitProject()
{
}

void InitProject::initTMS()
{
	Geo::ImageOption option;
	option.strPath = FileUtils::ins()->getPath("../Data/Dom/World/tms.xml");
	LayerMgr::ins()->addLayer(option, LayerMgr::TMS_Dom);

	option.strPath = FileUtils::ins()->getPath("../Data/Dem/World/tms.xml");
	LayerMgr::ins()->addLayer(option, LayerMgr::TMS_Dem);
}

void InitProject::loadModel()
{
	std::string strDir = FileUtils::ins()->getPath("../Data/QinXie/");
	QDir dir(strDir.c_str());
	QFileInfoList dirList = dir.entryInfoList(QDir::Dirs | QDir::NoSymLinks);
	for (QFileInfo file : dirList)
	{
		if (file.isDir())
		{
			QString strModel = QString::fromStdString(strDir) + file.fileName() + "/" + file.baseName() + ".osgb";
			osg::Node* node = osgDB::readNodeFile(strModel.toStdString());
			if (node != nullptr)
			{
				OECore::ins()->getSceneData()->addChild(node);
			}
		}
	}

	OECore::ins()->goToPoint(osg::Vec3d(106.851951, 25.53743, 0), 5000);
}
