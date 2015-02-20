#ifndef __MYBUTTON_H_
#define __MYBUTTON_H_

#include <QPushButton>
#include <QString>
#include <QWidget>

class MyButton : public QPushButton {
	Q_OBJECT
	public :
		MyButton(const QString& text, QWidget *parent=0);
	public slots:
		void onClick();
};
#endif /*__MYBUTTON_H_*/
