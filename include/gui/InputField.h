#ifndef __INPUTFIELD_H__
#define __INPUTFIELD_H__

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QPaintEvent>
#include <QFocusEvent>
#include <QTimer>
#include <QColor>
#include <QKeyEvent>

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
		QTimer *anim_timer;

		 /*placeholder animation*/
		qreal opacity;
		fade_type fade_ph; /*for fading placeholder*/
		int ph_x; /*Linear translation*/
		bool phVisible;
		int steps;

		/*Border Animation*/
		bool borderAnim;
		int borderWidth;
		QColor borderColor;

		void startAnim();
		void stopAnim();
		void startAnim(qreal _opac,fade_type _ft,int _ph_x);
		void startBorderAnim(const QColor &bColor,bool anim,int bWidth);

	public:
		InputField(const QString &ph=QString(),QWidget *parent=0);
		~InputField();
		void paintEvent(QPaintEvent *e);
		void focusInEvent(QFocusEvent *e);
		void focusOutEvent(QFocusEvent *e);
		void keyPressEvent(QKeyEvent *e);
		void changeBorderColor(const QColor &bColor);

	public slots:
		void onAnimationStarted();
		void onInvalidate();

	signals :
		void pressed();
};

#endif /*__INPUTFIELD_H__*/
