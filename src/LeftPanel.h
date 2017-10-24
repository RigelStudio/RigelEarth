#ifndef LEFTPANEL_H
#define LEFTPANEL_H

#include "ui_LeftPanel.h"
#include "LayerMoudle.h"
#include "Common.h"

class LeftPanel : public QWidget
{
	Q_OBJECT

public:
	LeftPanel(QWidget *parent = Q_NULLPTR);
	~LeftPanel();

	//设置面板当前模块
	void setMoudle(Moudle moudle);

public:
	Ui::LeftPanel ui;

private:
	LayerMoudle* m_pLayerMoudle;
};

#endif//LEFTPANEL_H