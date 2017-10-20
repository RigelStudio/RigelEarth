#ifndef LEFTPANEL_H
#define LEFTPANEL_H

#include "ui_LeftPanel.h"

class LeftPanel : public QWidget
{
	Q_OBJECT

public:
	LeftPanel(QWidget *parent = Q_NULLPTR);
	~LeftPanel();

public:
	Ui::LeftPanel ui;

private:
	
};

#endif//LEFTPANEL_H