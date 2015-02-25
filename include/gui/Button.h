#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <QPushButton>
#include <QString>
#include <QIcon>
#include <QWidget>
#include "gui/style/PushButtonStyle.h"

class Button : public QPushButton {
	Q_OBJECT
	private:
		QString txt;
		QIcon icon;
		PushButtonStyle *_st;

		void initStyle();

	public :
		Button(QWidget *parent = 0);
		Button(const QString &text, QWidget *parent = 0);
		Button(const QIcon &icon, const QString &text, QWidget *parent = 0);
		~Button();

};	
#endif /*__BUTTON_H__*/
