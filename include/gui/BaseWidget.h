#ifndef __BASEWIDGET_H__
#define __BASEWIDGET_H__

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <QPaintEvent>
#define DECLARE_ANIMATION \
		protected: \
			bool animated;\
			QTimer *animationTimer;

#define ANIMATION_HANDLER virtual void onAnimationStarted() {}

class BaseWidget : public QWidget {
	Q_OBJECT
	private :
	public :
		BaseWidget(bool animated = false,QWidget *parent = 0);
		~BaseWidget();
		void setAnimated(bool animated) {this->animated = animated; }
		void startAnimation(int ms) { if(animated && animationTimer) animationTimer->start(ms);}
		void stopAnimation() { if(animated && animationTimer) animationTimer->stop();}
		void showAll();
		void hideAll();
	protected:
		void paintEvent(QPaintEvent *event);
	DECLARE_ANIMATION
	public slots:
		ANIMATION_HANDLER
};

#endif /*__BASEWIDGET_H__*/
