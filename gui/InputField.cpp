#include <QtDebug>
#include <QColor>
#include <QRect>
#include <QPainter>
#include "gui/InputField.h"

/*XXX Style attributes 
  Later it should be changed.
  Perhaps read from a configuration file*/
namespace {
	const int HEIGHT = 35;
	const int WIDTH = 120;
	const int fadeDuration = 10; //10 ms
	const qreal OPACITY_MAX = 1.0;
	const qreal OPACITY_MIN = 0.0;
	const qreal OPACITY_DELTA = 0.05;
}

InputField :: InputField(const QString& ph,QWidget *parent):
		QLineEdit(parent),placeHolder(ph),opacity(1.0),fade_ph(fade_none)
{
	input_st = new LineEditStyle(QColor(49,127,205));
	setStyle(input_st);
	anim_ph_timer = new QTimer(this);
	connect(anim_ph_timer,SIGNAL(timeout()),this,SLOT(onAnimationStarted()));
	setFixedSize(WIDTH,HEIGHT);
}

InputField :: ~InputField()
{
	delete input_st;
	delete anim_ph_timer;
}

void InputField :: startAnim()
{
	if(!anim_ph_timer) return ;
	if(anim_ph_timer->isActive())
		anim_ph_timer->stop();
	anim_ph_timer->start(fadeDuration);
}

void InputField :: stopAnim()
{
	if(!anim_ph_timer) return;
	anim_ph_timer->stop();
}

void InputField :: focusInEvent(QFocusEvent *e)
{
	//qDebug() << "focusInEvent";
	opacity = OPACITY_MAX;
	fade_ph = fade_out;
	startAnim();
	QLineEdit :: focusInEvent(e);
}

void InputField :: focusOutEvent(QFocusEvent *e)
{
	//qDebug() << "focusOutEvent";
	opacity = OPACITY_MIN;
	fade_ph = fade_in;
	startAnim();
	QLineEdit :: focusOutEvent(e);
}

void InputField :: keyPressEvent(QKeyEvent *e) 
{
	//qDebug()<<"keyPressEvent : " << e->count();
	QLineEdit :: keyPressEvent(e);
}
void InputField :: paintEvent(QPaintEvent *e)
{
	QLineEdit :: paintEvent(e);
	//qDebug() << "paintEvent" << rect().width() << "," << rect().height();
	QPainter p(this);
	QStyleOptionFrameV2 panel;
    initStyleOption(&panel);
	p.setClipRect(rect());
	p.save();
	p.setOpacity(opacity);
	QColor col = palette().text().color();
	col.setAlpha(128);
	p.setPen(col);
	p.drawText(rect(),placeHolder,QTextOption(Qt::AlignHCenter));
	p.restore();
}

void InputField :: onAnimationStarted() 
{
	if(fade_ph & fade_in) 
	{
		opacity += OPACITY_DELTA;
		if(opacity > OPACITY_MAX) 
		{
			stopAnim();
		}
	} else if(fade_ph & fade_out) 
	{
		opacity -= OPACITY_DELTA;
		if(opacity < OPACITY_MIN) 
		{
			stopAnim();
		}
	}
	//qDebug() << "opacity : " << opacity;
	update();
}

