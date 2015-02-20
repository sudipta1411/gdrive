#include "gui/BaseWidget.h"
#include <QPainter>
#include <QtDebug>

BaseWidget :: BaseWidget(bool animated,QWidget *parent) : QWidget(parent/*,Qt::Popup*/)
{
	animationTimer = new QTimer(this);
	connect(animationTimer,SIGNAL(timeout()),this,SLOT(onAnimationStarted()));
	this->animated = animated;
}

BaseWidget :: ~BaseWidget() 
{
	if(animationTimer) delete animationTimer;	
}

void BaseWidget :: paintEvent(QPaintEvent *event)
{
	QWidget :: paintEvent(event);
}

void BaseWidget :: showAll() 
{
	const QObjectList childWidgets = children();
	const int length = childWidgets.length();
	for(int i=0;i<length;i++) {
		QObject *obj = childWidgets.at(i);
		if(obj->inherits("QWidget")) {
			QWidget *w = qobject_cast<QWidget*>(obj);
			w->show();
		}
	}
}

void BaseWidget :: hideAll()
{
	const QObjectList childWidgets = children();
	const int length = childWidgets.length();
	for(int i=0;i<length;i++) {
		QObject *obj = childWidgets.at(i);
		if(obj->inherits("QWidget")) {
			QWidget *w = qobject_cast<QWidget*>(obj);
			w->hide();
		}
	}
}

