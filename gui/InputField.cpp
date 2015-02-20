#include <QtDebug>
#include <QColor>
#include <QRect>
#include <QPainter>
#include "gui/InputField.h"

namespace {
	const int fadeDuration = 20; //20 ms
}

InputField :: InputField(const QString& ph,QWidget *parent):
		QLineEdit(parent),placeHolder(ph)
{
	input_st = new LineEditStyle(QColor(49,127,205));
	opacity = 0.0;
	setStyle(input_st);
	anim_ph_timer = new QTimer(this);
	connect(anim_ph_timer,SIGNAL(timeout()),this,SLOT(onAnimationStarted()));
}

InputField :: ~InputField()
{
	delete input_st;
	delete anim_ph_timer;
}

void InputField :: focusInEvent(QFocusEvent *e)
{
	qDebug() << "focusInEvent";
	opacity = 0.0;
	update();
	QLineEdit :: focusInEvent(e);
}

void InputField :: focusOutEvent(QFocusEvent *e)
{
	qDebug() << "focusOutEvent";
	anim_ph_timer->start(fadeDuration);
	QLineEdit :: focusOutEvent(e);
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
	opacity+=0.05;
	if(opacity>=1.0) 
	{
		anim_ph_timer->stop();
		return ;
	}
	update();
}

