#include "gui/Button.h"

/*XXX Style attributes 
  Later it should be changed.
  Perhaps read from a configuration file*/
namespace {
	const int HEIGHT = 40;
	const int WIDTH = 160;
	const QColor buttonColor = QColor(49,127,205);
}

Button :: Button(QWidget *parent) : QPushButton(parent),
		txt(QString()),icon(QIcon())
{
	initStyle();
	setFixedSize(WIDTH,HEIGHT);
}

Button :: Button(const QString &text, QWidget *parent) : QPushButton(text,parent),
		txt(text),icon(QIcon())
{
	initStyle();
	setFixedSize(WIDTH,HEIGHT);
}

Button :: Button(const QIcon &icn, const QString &text, QWidget *parent):QPushButton(icn,text,parent),
		txt(text),icon(icn)
{
	initStyle();
	setFixedSize(WIDTH,HEIGHT);
}

Button :: ~Button() 
{
	delete _st;
}

void Button :: initStyle()
{
	_st = new PushButtonStyle(/*QColor(91,116,168)*/buttonColor);
	setStyle(_st);
}
