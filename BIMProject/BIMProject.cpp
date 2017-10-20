#include "BIMProject.h"
#include "MeCore/OECore.h"

BIMProject::BIMProject(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_pGraphicsView = new GraphicsView();
	OECore::ins()->init(m_pGraphicsView->getOSGViewer());

	m_initPro.initTMS();
	m_initPro.loadModel();

	m_pTopMenu = nullptr;
	m_pLeftPanel = nullptr;
	initGUI();
}

void BIMProject::initGUI()
{
	QHBoxLayout* hLayout = new QHBoxLayout;
	
	m_pLeftPanel = new LeftPanel();
	m_pLeftPanel->setFixedWidth(220);
	hLayout->addWidget(m_pLeftPanel);
	hLayout->addWidget(m_pGraphicsView);
	hLayout->setMargin(0);

	QVBoxLayout* vLayout = new QVBoxLayout();
	m_pTopMenu = new TopMenu();
	m_pTopMenu->setFixedHeight(40);
	vLayout->addWidget(m_pTopMenu);
	vLayout->addLayout(hLayout);
	vLayout->setMargin(0);
	vLayout->setSpacing(0);

	centralWidget()->setLayout(vLayout);
	
}
