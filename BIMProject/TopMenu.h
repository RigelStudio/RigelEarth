#pragma once

#include "ui_TopMenu.h"

class TopMenu : public QWidget
{
	Q_OBJECT

public:
	TopMenu(QWidget *parent = Q_NULLPTR);
	~TopMenu();

public slots:
	void slotExit();

public:
	Ui::TopMenu ui;
};
