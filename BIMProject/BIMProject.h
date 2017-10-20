#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BIMProject.h"
#include "MeQt/GraphicsView.h"
#include "InitProject.h"
#include "TopMenu.h"
#include "LeftPanel.h"


class BIMProject : public QMainWindow
{
	Q_OBJECT

public:
	BIMProject(QWidget *parent = Q_NULLPTR);

	void initGUI();

private:
	Ui::BIMProject ui;
	GraphicsView*	m_pGraphicsView;
	InitProject		m_initPro;
	TopMenu*		m_pTopMenu;
	LeftPanel*		m_pLeftPanel;
	QLayout*		m_pLayout;
};
