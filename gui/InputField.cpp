#include <QtDebug>
#include <QColor>
#include <QRect>
#include <QPainter>
#include "gui/InputField.h"

/*XXX Style attributes 
  Later it should be changed.
  Perhaps read from a configuration file*/
namespace {
	const int HEIGHT = 40;
	const int WIDTH = 160; /*This is multiple of 1/OPACITY_DELTA (20 in this case)*/
	const int PH_MARGIN_H = 6; //Horizontal margin
	const int PH_MARGIN_V = 10; //Vertical margin
	const int fadeDuration = 10;
	const qreal OPACITY_MAX = 1.0;
	const qreal OPACITY_MIN = 0.0;
	const qreal OPACITY_DELTA = 0.05;
}

InputField :: InputField(const QString& ph,QWidget *parent):
		QLineEdit(parent),placeHolder(ph),opacity(1.0),fade_ph(fade_none),
		ph_x(0),phVisible(true)
{
	input_st = new LineEditStyle(QColor(49,127,205));
	setStyle(input_st);
	anim_timer = new QTimer(this);
	connect(anim_timer,SIGNAL(timeout()),this,SLOT(onAnimationStarted()));
	setFixedSize(WIDTH,HEIGHT);
	steps = (OPACITY_MAX-OPACITY_MIN)/OPACITY_DELTA;
}

InputField :: ~InputField()
{
	delete input_st;
	delete anim_timer;
}

void InputField :: startAnim()
{
	if(!anim_timer) return ;
	if(anim_timer->isActive())
		anim_timer->stop();
	anim_timer->start(fadeDuration);
}

void InputField :: stopAnim()
{
	if(!anim_timer) return;
	anim_timer->stop();
}

void InputField :: startAnim(qreal _opac,fade_type _ft,int _ph_x)
{
	opacity = _opac;
	fade_ph = _ft;
	ph_x = _ph_x;
	startAnim();
}

void InputField :: focusInEvent(QFocusEvent *e)
{
	//qDebug() << "focusInEvent";
	//startAnim(OPACITY_MAX,fade_out,0);
	QLineEdit :: focusInEvent(e);
}

void InputField :: focusOutEvent(QFocusEvent *e)
{
	//qDebug() << "focusOutEvent";
	//startAnim(OPACITY_MIN,fade_in,WIDTH);
	QLineEdit :: focusOutEvent(e);
}

void InputField :: keyPressEvent(QKeyEvent *e) 
{
	QLineEdit :: keyPressEvent(e);
	bool empty = (text().length() == 0);
	//qDebug()<<"keyPressEvent : " << text().length();
	if(phVisible && !empty) 
	{
		startAnim(OPACITY_MAX,fade_out,0);
		phVisible = false;
	}
	if(!phVisible && empty) 
	{
		startAnim(OPACITY_MIN,fade_in,WIDTH);
		phVisible = true;
	}
}

void InputField :: paintEvent(QPaintEvent *e)
{
	QLineEdit :: paintEvent(e);
	QRect r = rect();
	QPainter p(this);
	p.setClipRect(r);
	p.save();
	p.setOpacity(opacity);
	QColor col = palette().text().color();
	col.setAlpha(128);
	p.setPen(col);
	QRect phRect(r.x()+ph_x+PH_MARGIN_H,r.y()+PH_MARGIN_V,r.width(),r.height());
	p.drawText(phRect,placeHolder/*,QTextOption(Qt::AlignHCenter)*/);
	p.restore();
}

void InputField :: onAnimationStarted() 
{
	if(fade_ph & fade_in) 
	{
		opacity += OPACITY_DELTA;
		ph_x -= WIDTH/steps;
		if(opacity > OPACITY_MAX) 
		{
			stopAnim();
		}
	} else if(fade_ph & fade_out) 
	{
		opacity -= OPACITY_DELTA;
		ph_x += WIDTH/steps;
		if(opacity < OPACITY_MIN) 
		{
			stopAnim();
		}
	}
	update();
}

