#include <QtDebug>
#include "gui/style/LineEditStyle.h"

int LineEditStyle :: pixelMetric(PixelMetric metric,
				const QStyleOption *option, const QWidget *widget) const
{
	int ret;
	//qDebug()<<"PixelMetric : " << metric;
	ret = QCommonStyle :: pixelMetric(metric,option,widget);
	//qDebug()<<"PixelMetric return value : " << ret;
	return ret;
}

int LineEditStyle :: styleHint(StyleHint hint,const QStyleOption *option,
				const QWidget *widget,QStyleHintReturn *returnData) const
{
	int ret;
	//qDebug()<<"StyleHint : "<<hint;
	ret = QCommonStyle :: styleHint(hint,option,widget,returnData);
	return ret;
}

void LineEditStyle :: drawPrimitive(PrimitiveElement element, 
				const QStyleOption *option,QPainter *painter, 
				const QWidget *widget) const
{
	//qDebug()<<"drawPrimitive : "<<element;
		switch(element) {
			case PE_FrameLineEdit:
			{
				if(const QStyleOptionFrame *frame = qstyleoption_cast<const QStyleOptionFrame *>(option)) {
					drawShadedPanel(painter,frame->rect,frame->palette,highlightColor,
									frame->state & State_Sunken,frame->state & State_HasFocus,
									frame->lineWidth);
				}
			}
			break;
			default:
				QCommonStyle :: drawPrimitive(element,option,painter,widget);
	}
}

void LineEditStyle :: drawControl(ControlElement control, const QStyleOption *option, 
				QPainter *painter, const QWidget *widget) const
{
	//qDebug()<<"drawControl : "<< control;
    QCommonStyle ::drawControl(control,option,painter,widget);
}

