#include <QColor>
#include "Application.h"
//#include "gui/Animation.h"

Application :: Application(int &argc,char** argv):BaseApplication(argc,argv)
{
	//anim::startManager();
	window = new AppWindow();
	window->initSize();
	window->initColor(QColor(239,239,239));
	startApp();	
}

Application :: ~Application() 
{
	window->setParent(0);
	//anim::stopManager();
	delete window;
}

void Application :: startApp() 
{
	if(window)
		window->firstShow();
}
