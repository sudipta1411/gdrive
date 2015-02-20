#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "BaseApplication.h"
#include "AppWindow.h"

class Application : public BaseApplication {
	Q_OBJECT
	public :
		Application(int &argc,char **argv);
		~Application();
	private:
		void startApp();

		AppWindow *window;
};
#endif /*__APPLICATION_H__*/
