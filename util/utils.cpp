#include <QResizeEvent>
#include <QDesktopWidget>
#include <QSize>
#include "util/utils.h"
#include "Application.h"

namespace util {
	style::StyleAttribute createStyleAttributeForLoginWidget()
	{
		style::StyleAttribute st;
		st.height = -1;
		st.width = -1;
		st.minHeight = 50;
		st.minWidth = 30;
		st.titleWidth = 39;
		st.slideDuration = 200;
		st.slideShift = 500;
		st.slideDelta = 0;
		st.bg = QColor(255,255,255);
		st.fadingDuration = 30;
		return st;
	}
	
	void sendResizeEvents(QWidget *target)
	{
		QResizeEvent resizeEvent(target->size(),QSize());
		Application::sendEvent(target,&resizeEvent);
		const QObjectList children = target->children();
		for (int i = 0; i < children.size(); ++i) {
			QWidget *child = static_cast<QWidget*>(children.at(i));
			if (child->isWidgetType() && !child->isWindow() && child->testAttribute(Qt::WA_PendingResizeEvent))
				sendResizeEvents(child);
			}

	}

	QPixmap myGrab(QWidget *target, const QRect &rect) 
	{
		if (target->testAttribute(Qt::WA_PendingResizeEvent) || !target->testAttribute(Qt::WA_WState_Created))
			sendResizeEvents(target);
		const qreal dpr = QDesktopWidget().devicePixelRatio();
		QPixmap result(rect.size()*dpr);
      	result.setDevicePixelRatio(dpr);
		result.fill(Qt::transparent);
	    target->render(&result, QPoint(),QRegion(rect),QWidget::DrawWindowBackground|QWidget::DrawChildren|QWidget::IgnoreMask);
		return result;

	}
};
