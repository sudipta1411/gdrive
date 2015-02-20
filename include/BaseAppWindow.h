#ifndef __BASEAPPWINDOW_H__
#define __BASEAPPWINDOW_H__

#include <QMainWindow>
#include <QWidget>
#include <QtGlobal>
#include <QColor>
#include <QResizeEvent>

class BaseAppWindow : public QMainWindow {
	Q_OBJECT
	public :
		BaseAppWindow(QWidget *parent=0,Qt::WindowFlags flags=0);
		~BaseAppWindow() {}
		void initSize();
		void initColor(QColor background);
		void firstShow() ;
	protected:
		virtual void resizeEvent(QResizeEvent *e);
	private :
		quint32 wndMinHeight;
		quint32 wndMinWidth;
		quint32 wndDefHeight;
		quint32 wndDefWidth;
};
#endif /*__MAINAPPWINDOW_H__*/
