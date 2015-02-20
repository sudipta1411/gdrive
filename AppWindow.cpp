#include "AppWindow.h"
#include <QtDebug>
#include "util/utils.h"

AppWindow :: AppWindow(QWidget *parent,Qt::WindowFlags flags) : BaseAppWindow(parent,flags) 
{
	createStyles();
	loginWidget = new LoginWidget(loginAttr,this);
	//setCentralWidget(loginWidget);
	QPixmap bg = util::myGrab(this, QRect(0, 39, width(), height() - 39));
	loginWidget->setFixedSize(250,250);
	//loginWidget->animShow(bg);
	//qDebug() << "In LoginWidget constructor show";
	//show();
}

AppWindow :: ~AppWindow()
{
	delete loginWidget;
}

void AppWindow :: createStyles()
{
	loginAttr = util::createStyleAttributeForLoginWidget();
}

void AppWindow :: paintEvent(QPaintEvent *e)
{
	loginWidget->move((width()-loginWidget->width())/2,(height()-loginWidget->height())/2);
}
