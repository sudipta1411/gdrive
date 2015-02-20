#ifndef __APPWINDOW_H__
#define __APPWINDOW_H__

#include "gui/LoginWidget.h"
#include "BaseAppWindow.h"
#include "StyleAttribute.h"

class AppWindow : public BaseAppWindow {
	Q_OBJECT
	public :
		AppWindow(QWidget *parent = 0,Qt::WindowFlags flags = 0);
		~AppWindow();
	protected:
		void paintEvent(QPaintEvent *e);
	private:
		void createStyles();
		LoginWidget *loginWidget;

		style::StyleAttribute loginAttr;

};
#endif /*__APPWINDOW_H__*/
