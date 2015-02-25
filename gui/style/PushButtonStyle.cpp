#include <QStyleOptionButton>
#include <QLinearGradient>
#include <QtDebug>
#include "gui/style/PushButtonStyle.h"

int PushButtonStyle :: pixelMetric(PixelMetric metric,const QStyleOption *option,
				const QWidget *widget) const
{
	switch(metric) {
		case PM_ButtonMargin :
			return 0;
		case PM_ButtonShiftHorizontal :
			return 1;
		case PM_ButtonShiftVertical :
			return 1;
		case PM_ButtonDefaultIndicator :
			return 5;
		case PM_DefaultFrameWidth:
			return 0;
		default :
			return QCommonStyle :: pixelMetric(metric,option,widget);
	}
}

int PushButtonStyle :: styleHint(StyleHint hint, const QStyleOption *option,
				const QWidget* widget, QStyleHintReturn *returnData) const
{
	switch(hint) {
		case SH_DialogButtonLayout:
	        return 1;
		case SH_DitherDisabledText :
			return int(false);
		case SH_EtchDisabledText :
			return int(true);
		default :
			return QCommonStyle :: styleHint(hint,option,widget,returnData);
	}
}

void PushButtonStyle :: drawPrimitive(PrimitiveElement element,const QStyleOption *option,
				QPainter *painter,const QWidget *widget) const
{
	switch(element) {
		case PE_PanelButtonCommand:
		{
			//QColor buttonColor = QColor(91,116,168);/*option->palette.button().color();*/
			double penWidth = 0.2/*1.0*/;
			if (const QStyleOptionButton * buttonOpt = 
							qstyleoption_cast< const QStyleOptionButton *>(option)) {
				if (buttonOpt->features & QStyleOptionButton::DefaultButton)
						penWidth = 2.0;
			}
			//qDebug() << penWidth;
			QRect roundRect = option->rect.adjusted (+1, +1, -1, -1);
			if (!roundRect.isValid())
				return;
			int diameter = 4;
			int cx = 100 * diameter / roundRect.width();
			int cy = 100 * diameter / roundRect.height();
			painter->save();
			painter->setPen(Qt::NoPen);
			painter->setBrush(/*gradient*/buttonColor);
			painter->drawRoundRect(roundRect, cx, cy);
			if (option->state & (State_On | State_Sunken)) {
				QColor slightlyOpaqueBlack(0, 0, 0, 20);
				painter->setBrush(slightlyOpaqueBlack);
				painter->drawRoundRect(roundRect, cx, cy);
			}
			if(option->state & State_MouseOver) {
				QColor slightlyOpaqueBlack(0, 0, 0, 10);
				painter->setBrush(slightlyOpaqueBlack);
				painter->drawRoundRect(roundRect, cx, cy);
			}
			painter->setRenderHint(QPainter::Antialiasing, true);
			painter->setPen(QPen(option->palette.foreground(), penWidth)/*Qt::NoPen*/);
			painter->setBrush(Qt::NoBrush);
			painter->drawRoundRect(roundRect, cx, cy);
			painter->restore();
		}
		break;
		case PE_FrameDefaultButton:
			break;
		default:
			QCommonStyle :: drawPrimitive(element, option, painter, widget);
	}
}

void PushButtonStyle :: drawControl(ControlElement control,const QStyleOption *option,
				QPainter *painter,const QWidget *widget) const
{
	switch(control) {
		case CE_PushButtonLabel:
		{
			const QStyleOptionButton *buttonOption =
				   	qstyleoption_cast<const QStyleOptionButton *>(option);
			//qDebug() << buttonOption->text;
			if(buttonOption) {
				if(buttonOption->palette.currentColorGroup() != QPalette::Disabled)
					if(buttonOption->state & (State_Sunken | State_On))
						buttonOption->palette.brightText();

			}
			painter->setRenderHint(QPainter::TextAntialiasing,true);
			drawItemText(painter, buttonOption->rect,Qt::AlignHCenter|Qt::AlignVCenter, 
							buttonOption->palette, (buttonOption->state & State_Enabled),
						   	buttonOption->text, QPalette::ButtonText);
			//QCommonStyle :: drawControl(control,option,painter,widget);
		}
		break;
		case CE_PushButtonBevel:
		{
			QCommonStyle :: drawControl(control,option,painter,widget);
		}
		break;
		default:
			QCommonStyle :: drawControl(control,option,painter,widget);
	}
}

