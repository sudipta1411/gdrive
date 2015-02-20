#include <QtDebug>
#include "gui/style/CheckBoxStyle.h"

int CheckBoxStyle :: pixelMetric(PixelMetric metric,const QStyleOption *option,
				const QWidget *widget) const
{
	switch(metric) {
		case PM_CheckBoxLabelSpacing:
			return 8;
		case PM_IndicatorWidth:
		case PM_IndicatorHeight:
			return 20;
		default:
			return QCommonStyle :: pixelMetric(metric,option,widget);
	}
}

int CheckBoxStyle :: styleHint(StyleHint hint,const QStyleOption *option,
				const QWidget *widget,QStyleHintReturn *returnData) const
{
	return QCommonStyle :: styleHint(hint,option,widget,returnData);
}

void CheckBoxStyle :: drawPrimitive(PrimitiveElement element,const QStyleOption *option,
				QPainter *painter,const QWidget *widget) const
{
	switch(element) {
		case PE_IndicatorCheckBox:
		{
			QColor shade = QColor(63,120,205);
			QPen oldPen = painter->pen();
			painter->save();
			painter->setRenderHint(QPainter::Antialiasing, true);
			if(option->state & State_MouseOver) {
				painter->setBrush(option->palette.alternateBase());
			} else {
				painter->setBrush(option->palette.base());
			}
			if(option->state & State_HasFocus)
				painter->setPen(shade);

			//painter->drawRoundedRect(option->rect.adjusted(+1, +1, -1, -1),2,2);
			painter->drawRect(option->rect.adjusted(1,1,-1,-1));
			QRect r = option->rect;
			/*if(option->state & State_NoChange) {
				bool t = (option->state & State_On);
				qDebug() << "Tis State " << t;
			}*/
			if(option->state & State_On) {
				painter->fillRect(r,shade);
				painter->setPen(QPen(QColor(255,255,255),2));
				painter->drawLine(r.x()-2,r.y()+r.height()/2,r.x()+r.width()/2,r.y()+r.height()-2);
				painter->drawLine(r.x()+r.width()/2,r.y()+r.height()-2,r.x()+r.width(),r.y()-2);
			}
			painter->setPen(oldPen);
			painter->restore();
		}
		break;
		default :
			QCommonStyle :: drawPrimitive(element,option,painter,widget);
	}
}

void CheckBoxStyle :: drawControl(ControlElement control, const QStyleOption *option,
			   	QPainter *painter, const QWidget *widget) const
{
		switch(control) {
			default :
				QCommonStyle :: drawControl(control,option,painter,widget);
		}
}
