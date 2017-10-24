#ifndef NCSECURITY_INPUTLIB_H
#define NCSECURITY_INPUTLIB_H

#ifdef _DEBUG
#pragma comment(lib,"OpenThreadsd.lib")
#pragma comment(lib,"osgd.lib")
#pragma comment(lib,"osgDBd.lib")
#pragma comment(lib,"osgGAd.lib")
#pragma comment(lib,"osgViewerd.lib")
#pragma comment(lib,"osgEarthd.lib")
#pragma comment(lib,"osgEarthUtild.lib")
#pragma comment(lib,"osgWidgetd.lib")

#pragma comment(lib,"MeQtd.lib")
#pragma comment(lib,"MeDBd.lib")
#pragma comment(lib,"MeCored.lib")

#

#else
#pragma comment(lib,"OpenThreads.lib")
#pragma comment(lib,"osg.lib")
#pragma comment(lib,"osgDB.lib")
#pragma comment(lib,"osgGA.lib")
#pragma comment(lib,"osgViewer.lib")
#pragma comment(lib,"osgEarth.lib")
#pragma comment(lib,"osgEarthUtil.lib")
#pragma comment(lib,"osgWidget.lib")

#pragma comment(lib,"MeQt.lib")
#pragma comment(lib,"MeDB.lib")
#pragma comment(lib,"MeCore.lib")

#endif

#endif // NCSECURITY_INPUTLIB_H
