#include <QtDebug>
#include "gui/MyButton.h"
#include "gui/BaseWidget.h"

MyButton :: MyButton(const QString& text, QWidget *parent) : QPushButton(text,parent) 
{
	connect(this,SIGNAL(clicked()),this,SLOT(onClick()));
}

void MyButton :: onClick()
{
	//qDebug() << "Button Clicked";
	BaseWidget *baseWidget = new BaseWidget(parentWidget());
	baseWidget->show();
}
