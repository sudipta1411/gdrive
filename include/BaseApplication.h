#ifndef __BASEAPPLICATION_H__
#define __BASEAPPLICATION_H__

#include <QApplication>

class BaseApplication : public QApplication {
	Q_OBJECT
	public :
		BaseApplication(int &argc,char **argv) : QApplication(argc,argv) {}
		~BaseApplication() {}
};

#endif /*__BASEAPPLICATION_H__*/
