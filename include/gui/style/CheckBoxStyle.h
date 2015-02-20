#ifndef __CHECKBOX_STYLE__
#define __CHECKBOX_STYLE__

#include "BaseStyle.h"

class CheckBoxStyle : public BaseStyle {
	Q_OBJECT
	public:
		int pixelMetric(PixelMetric metric, const QStyleOption *option,
			   	const QWidget *widget) const;
		int styleHint(StyleHint hint, const QStyleOption *option, const QWidget *widget,
					   	QStyleHintReturn *returnData) const;
        void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
					   	QPainter *painter, const QWidget *widget) const;
        void drawControl(ControlElement control, const QStyleOption *option,
						QPainter *painter, const QWidget *widget) const;
};
#endif /*__CHECKBOX_STYLE__*/
