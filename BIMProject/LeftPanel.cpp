#include "LeftPanel.h"
#include "MeCore/Fileutils.h"
#include "MeCore/OECore.h"

LeftPanel::LeftPanel(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	//ui.stackedWidget->addWidget(m_pLayerWid);
	
}

LeftPanel::~LeftPanel()
{
}
