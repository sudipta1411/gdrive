#ifndef __PUSHBUTTON_STYLE__
#define __PUSHBUTTON_STYLE__

//#include <QStyleOption>
#include <QPainter>
//#include <QStyleHintReturn>
#include "BaseStyle.h"

class PushButtonStyle : public BaseStyle {
	Q_OBJECT
	public:
		PushButtonStyle() {}
		~PushButtonStyle() {}
		
		int pixelMetric(PixelMetric metric, const QStyleOption *option,
			   	const QWidget *widget) const;
		int styleHint(StyleHint hint, const QStyleOption *option, const QWidget *widget,
					   	QStyleHintReturn *returnData) const;
        void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
					   	QPainter *painter, const QWidget *widget) const;
        void drawControl(ControlElement control, const QStyleOption *option,
						QPainter *painter, const QWidget *widget) const;
		/*QRect subElementRect(SubElement element,const QStyleOption *opt,
						const QWidget *widget) const;*/
};
#endif /*__PUSHBUTTON_STYLE__*/
