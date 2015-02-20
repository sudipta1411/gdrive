#ifndef __STYLEATTRIBUTE_H__
#define __STYLEATTRIBUTE_H__
#include <QColor>
namespace style {
	class StyleAttribute {
		public :
			int height,width;
			int minWidth,minHeight;
			int titleWidth;
			int slideShift,slideDuration,slideDelta;
			QColor bg;
			int fadingDuration;

			StyleAttribute(int _height=-1,int _width=-1,int _minW=-1,
						  int _minH=-1,int _titleW=-1,int _slideShift=-1,int _slideDur=-1,int _slideDelta=-1,int _fadingDuration=-1)
					:height(_height),width(_width),minWidth(_minW),minHeight(_minH),
					titleWidth(_titleW),slideShift(_slideShift),slideDuration(_slideDur),
					slideDelta(_slideDelta),fadingDuration(_fadingDuration)
			{
				bg = QColor();
			}
	};
};
#endif /*__STYLEATTRIBUTE_H__*/
