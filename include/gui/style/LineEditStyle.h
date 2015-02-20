#ifndef __LINEEDIT_STYLE__
#define __LINEEDIT_STYLE__

//#include <QVector>
//#include <QLineF>
#include <QColor>
#include <QStyleOptionFrame>
#include "BaseStyle.h"

class LineEditStyle : public BaseStyle {
	Q_OBJECT
	public :
		LineEditStyle(const QColor &_hlColor) : highlightColor(_hlColor){}
		~LineEditStyle() {}

		int pixelMetric(PixelMetric metric, const QStyleOption *option,
			   	const QWidget *widget) const;
		int styleHint(StyleHint hint, const QStyleOption *option, const QWidget *widget,
					   	QStyleHintReturn *returnData) const;
        void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
					   	QPainter *painter, const QWidget *widget) const;
        void drawControl(ControlElement control, const QStyleOption *option,
						QPainter *painter, const QWidget *widget) const;
	private:
		QColor highlightColor;
};
#endif /*__LINEEDIT_STYLE__*/
