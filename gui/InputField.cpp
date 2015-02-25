#include <QtDebug>
#include <QRect>
#include <QPainter>
#include <QBrush>
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
	int MaxBorderWidth = 3;
	const QColor borderColor = QColor(49,127,205);
}

InputField :: InputField(const QString& ph,QWidget *parent):QLineEdit(parent),
		placeHolder(ph),opacity(1.0),fade_ph(fade_none),ph_x(0),phVisible(true),
		borderAnim(false),borderWidth(0),borderColor(::borderColor)
{
	input_st = new LineEditStyle(QColor(49,127,205));
	//setStyle(input_st);
	anim_timer = new QTimer(this);
	connect(anim_timer,SIGNAL(timeout()),this,SLOT(onAnimationStarted()));
	setFixedSize(WIDTH,HEIGHT);
	steps = (OPACITY_MAX-OPACITY_MIN)/OPACITY_DELTA;

	connect(this,SIGNAL(pressed()),this,SLOT(onInvalidate()));
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

void InputField :: startBorderAnim(const QColor &bColor,bool anim,int bWidth)
{
	borderColor = bColor;
	borderAnim = anim;
	borderWidth = bWidth;
	fade_ph = fade_none;
	startAnim();
	
}

void InputField :: focusInEvent(QFocusEvent *e)
{
	//qDebug() << "focusInEvent";
	startBorderAnim(::borderColor,true,0);
	QLineEdit :: focusInEvent(e);
}

void InputField :: focusOutEvent(QFocusEvent *e)
{
	//qDebug() << "focusOutEvent";
	startBorderAnim(::borderColor,false,MaxBorderWidth);
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
	if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return)
		emit pressed();
}

void InputField :: paintEvent(QPaintEvent *e)
{
	QLineEdit :: paintEvent(e);
	QRect r = rect();
	QPainter p(this);

	QBrush b(borderColor);
	/*p.fillRect(r.x(),r.y(),r.width()-borderWidth,r.height()-borderWidth
					,QBrush(borderColor.light().light(),Qt::SolidPattern));*/
	if(borderWidth) {
		p.fillRect(0, 0, width() - borderWidth, borderWidth, b);
		p.fillRect(width() - borderWidth, 0, borderWidth, height() - borderWidth, b);
		p.fillRect(borderWidth, height() - borderWidth, width() - borderWidth,borderWidth, b);
		p.fillRect(0, borderWidth, borderWidth, height() - borderWidth, b);
	}

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

void InputField :: changeBorderColor(const QColor &bColor)
{
	startBorderAnim(bColor,true,0);
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
	} else {
		if(borderAnim) {
			borderWidth++;
			if(borderWidth >= MaxBorderWidth)
				stopAnim();
		} else {
			borderWidth--;
			if(borderWidth<=0)
				stopAnim();
		}
	}
	//qDebug() << "borderWidth : " << borderWidth; 
	update();
}

void InputField :: onInvalidate() 
{
	changeBorderColor(QColor(250,128,114));
}

