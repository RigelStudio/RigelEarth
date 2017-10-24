#include "BIMProject.h"
#include <QtWidgets/QApplication>
#include "MeCore/FileUtils.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FileUtils::ins()->init(QApplication::applicationDirPath().toStdString());
	BIMProject w;
	w.showFullScreen();
	return a.exec();
}
