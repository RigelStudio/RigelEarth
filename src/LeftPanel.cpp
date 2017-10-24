#include "LeftPanel.h"
#include "MeCore/Fileutils.h"
#include "MeCore/OECore.h"

LeftPanel::LeftPanel(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	m_pLayerMoudle = new LayerMoudle;
	ui.stackedWidget->addWidget(m_pLayerMoudle);
	
}

LeftPanel::~LeftPanel()
{
}

void LeftPanel::setMoudle(Moudle moudle)
{
	switch (moudle)
	{
	case MOD_Layer:
		break;
	case MOD_Model:
		break;
	default:
		break;
	}
}
