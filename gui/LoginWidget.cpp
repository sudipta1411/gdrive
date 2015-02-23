//#include <QVBoxLayout>
#include <QRect>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QtDebug>
#include "gui/LoginWidget.h"
#include <util/utils.h>
#include "gui/Animation.h"

LoginWidget :: LoginWidget(const style::StyleAttribute &_st,QWidget *parent) : 
		BaseWidget(true,parent)
{
	opacity = 0.0;
	st = _st;
	usernameField = new InputField("Username",this);
	passwordField = new InputField("Password",this);
	//login = new QPushButton("Login",this);
	//username->setFixedSize(st.minWidth,st.minHeight);
	//password->setFixedSize(st.minWidth,st.minHeight);
	//login->setFixedSize(st.minWidth,st.minHeight);
	startAnimation(st.fadingDuration);
	animCache = QPixmap(width(),height());
	animCache.fill(Qt::white);
}

LoginWidget :: ~LoginWidget()
{
	delete usernameField;
	delete passwordField;
	//delete login;
}

void LoginWidget :: paintEvent(QPaintEvent *event)
{
	//BaseWidget::paintEvent(event);
	QRect r(event->rect());
	bool trivial = (r==rect());
	QPainter p(this);
	p.setOpacity(opacity);
	p.drawPixmap(rect(),animCache);
	/*p.drawRect(rect());
	//p.setPen(QPen(Qt::blue));
	p.fillRect(rect(),Qt::white);
	p.drawRect(rect());
	if(trivial)
		p.setClipRect(r);*/
	/*if(animating()) {
		p.setOpacity(aBGAlpha.current());
		p.drawPixmap(aBGCoord.current(),0,bgAnimCache);
		p.setOpacity(aAlpha.current());
		p.drawPixmap(aCoord.current(),0,animCache);
	} else {
		//p.fillRect(rect(), st.bg.blue());
	}*/
	//QPainter p(this);
	//username->move(40,30);
	usernameField->move(50,50);
}

void LoginWidget :: onAnimationStarted() 
{
	opacity += anim::halfSine(0.60,0.05);
	//qDebug() << "opacity : " << opacity;
	if(opacity>1.0) {
		stopAnimation();
		return ;
	}
	update();
}
