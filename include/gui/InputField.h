#ifndef __INPUTFIELD_H__
#define __INPUTFIELD_H__

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QPaintEvent>
#include <QFocusEvent>
#include <QTimer>
#include "gui/style/LineEditStyle.h"

class InputField : public QLineEdit {
	Q_OBJECT
	private:
		QString placeHolder;
		LineEditStyle *input_st;
		QTimer *anim_ph_timer;
		qreal opacity;

	public:
		InputField(const QString &ph=QString(),QWidget *parent=0);
		~InputField();
		void paintEvent(QPaintEvent *e);
		void focusInEvent(QFocusEvent *e);
		void focusOutEvent(QFocusEvent *e);
	public slots:
		void onAnimationStarted();
};

#endif /*__INPUTFIELD_H__*/
