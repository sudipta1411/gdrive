#include <QRect>
#include <QDesktopWidget>
#include "BaseAppWindow.h"
#include <QPalette>
#include <QLinearGradient>
#include <QPointF>
#include <QBrush>
#include <QtDebug>

BaseAppWindow :: BaseAppWindow(QWidget *parent,Qt::WindowFlags flags):QMainWindow(parent,flags)
{
	wndMinHeight = 480;
	wndMinWidth = 380;
	wndDefHeight = 600;
	wndDefWidth = 800;
}

void BaseAppWindow :: initSize()
{
	setMinimumWidth(wndMinWidth);
	setMinimumHeight(wndMinHeight);
	QRect avail(QDesktopWidget().availableGeometry());
	QRect r(avail.x()+(avail.width()-wndDefWidth)/2,
					avail.y()+(avail.height()-wndDefHeight)/2,
					wndDefWidth,wndDefHeight);
	setGeometry(r);
}

void BaseAppWindow :: resizeEvent(QResizeEvent *e)
{
	//qDebug() << "resizeEvent";
}

void BaseAppWindow :: initColor(QColor background)
{
	QPalette palette;
	QLinearGradient linearGradient(QPointF(0,0),QPointF(rect().width(),rect().height()));
    linearGradient.setColorAt(0,background);
    linearGradient.setColorAt(1,background.darker());
	palette.setBrush(QPalette::Window,/*background*/QBrush(linearGradient));
	setPalette(palette);
}

void BaseAppWindow :: firstShow() {
	show();
}
