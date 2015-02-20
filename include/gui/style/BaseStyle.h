#ifndef __BASESTYLE_H__
#define __BASESTYLE_H__

#include <QCommonStyle>
#include <QLineEdit>
#include <QPushButton>
#include <QColor>
#include <QPalette>
#include <QPixmap>
#include <QWidget>
#include <QBrush>
#include <QPainterPath>
#include <QRect>
#include <QPainter>
#include <QStyleHintReturn>

class BaseStyle : public QCommonStyle {
	Q_OBJECT
	public :
		BaseStyle() {}
		~BaseStyle() {}
		void polish(QPalette &palette);
		void polish(QWidget *widget);
		void unpolish(QWidget *widget);
		virtual int pixelMetric(PixelMetric metric, const QStyleOption *option,
			   	const QWidget *widget) const = 0;
		virtual int styleHint(StyleHint hint, const QStyleOption *option, const QWidget *widget,
					   	QStyleHintReturn *returnData) const = 0;
        virtual void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
					   	QPainter *painter, const QWidget *widget) const = 0;
        virtual void drawControl(ControlElement control, const QStyleOption *option,
						QPainter *painter, const QWidget *widget) const = 0; 

	protected :
		void setTexture(QPalette &palette, 
						QPalette::ColorRole role,
						const QPixmap &pixmap);
		QPainterPath roundedRect(const QRect &rect,int radius = -1) const;
		void drawShadedPanel(QPainter *p,const QRect &r,const QPalette &palette, 
						const QColor &highlight,bool sunken = false, bool hasFocus = false,int lineWidth = 1,
					   	const QBrush * fill = 0) const;
};

#endif /*__BASESTYLE_H__*/
