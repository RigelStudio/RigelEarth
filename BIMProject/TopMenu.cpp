#include "TopMenu.h"

TopMenu::TopMenu(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton_Exit, SIGNAL(clicked()), SLOT(slotExit()));
}

TopMenu::~TopMenu()
{
}

void TopMenu::slotExit()
{
	QApplication::exit(0);
}
