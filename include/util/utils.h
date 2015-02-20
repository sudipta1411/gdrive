#ifndef __UTILS_H__
#define __UTILS_H__
#include <QPixmap>
#include <QRect>
#include <QWidget>
#include "StyleAttribute.h"

namespace util {
	style::StyleAttribute createStyleAttributeForLoginWidget();
	void sendResizeEvents(QWidget *target);
	QPixmap myGrab(QWidget *target, const QRect &rect);
};

#endif /*__UTILS_H__*/
