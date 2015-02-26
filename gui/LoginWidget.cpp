//#include <QVBoxLayout>
#include <QRect>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QtDebug>
#include "gui/LoginWidget.h"
#include <util/utils.h>
#include "gui/Animation.h"

namespace {
	const int topSpacing = 30;
	const int spacingBetweenWidget = 10;
}

LoginWidget :: LoginWidget(const style::StyleAttribute &_st,QWidget *parent) : 
		BaseWidget(true,parent)
{
	opacity = 0.0;
	st = _st;
	usernameField = new InputField("Username",this);
	passwordField = new InputField("Password",this);
	login = new Button("Sign In",this);
	passwordField->setEchoMode(QLineEdit::Password);
	//login->setFixedSize(st.minWidth,st.minHeight);
	startAnimation(st.fadingDuration);
	animCache = QPixmap(width(),height());
	animCache.fill(Qt::white);
}

LoginWidget :: ~LoginWidget()
{
	delete usernameField;
	delete passwordField;
	delete login;
}

void LoginWidget :: paintEvent(QPaintEvent *event)
{
	int top = topSpacing;
	//BaseWidget::paintEvent(event);
	QRect r(event->rect());
	bool trivial = (r==rect());
	QPainter p(this);
	p.setOpacity(opacity);
	p.drawPixmap(rect(),animCache);
	usernameField->move((width() - usernameField->width()) / 2,top);
	top += usernameField->height() + spacingBetweenWidget;
	passwordField->move((width() - passwordField->width()) / 2,top);
	top += passwordField->height() + spacingBetweenWidget*4;
	login->move((width() - login->width()) / 2,top);
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
