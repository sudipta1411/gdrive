#ifndef __INPUTFIELD_H__
#define __INPUTFIELD_H__

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QPaintEvent>
#include <QFocusEvent>
#include <QTimer>
#include <QKeyEvent>
#include "gui/style/LineEditStyle.h"

typedef enum
{
	fade_none = 0x00,
	fade_in = 0x01,
	fade_out = 0x02,
} fade_type;

class InputField : public QLineEdit {
	Q_OBJECT
	private:
		QString placeHolder;
		LineEditStyle *input_st;
		QTimer *anim_timer;
		qreal opacity;

		fade_type fade_ph; /*for fading placeholder*/
		int ph_x; /*Linear translation*/
		bool phVisible;
		int steps;
		void startAnim();
		void stopAnim();
		void startAnim(qreal _opac,fade_type _ft,int _ph_x);

	public:
		InputField(const QString &ph=QString(),QWidget *parent=0);
		~InputField();
		void paintEvent(QPaintEvent *e);
		void focusInEvent(QFocusEvent *e);
		void focusOutEvent(QFocusEvent *e);
		void keyPressEvent(QKeyEvent *e);
	public slots:
		void onAnimationStarted();
};

#endif /*__INPUTFIELD_H__*/
