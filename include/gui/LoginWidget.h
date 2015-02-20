#ifndef __LOGINWIDGET_H__
#define __LOGINWIDGET_H__

//#include <QTimer>
#include <QLineEdit>
#include <QPushButton>
#include "gui/BaseWidget.h"
#include "gui/InputField.h"
#include "gui/Animation.h"
#include "StyleAttribute.h"

class LoginWidget : public BaseWidget {
	Q_OBJECT
	public:
		LoginWidget(const style::StyleAttribute &_st,QWidget *parent = 0);
		~LoginWidget();
	public slots:
		void onAnimationStarted();
	protected:
		void paintEvent(QPaintEvent *event);
	private:
		QLineEdit *username,*password;
		InputField *usernameField,*passwordField;
		QPushButton *login;

		qreal opacity;
		QPixmap animCache,bgAnimCache;

		style::StyleAttribute st;
};

#endif/*__LOGINWIDGET_H__*/


