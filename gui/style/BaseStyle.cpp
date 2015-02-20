#include <QtGui>
#include <QtDebug>
#include "gui/style/BaseStyle.h"

void
BaseStyle::polish (QPalette & palette)
{
  QColor whitish (229, 229, 229, 70);
  QColor blackish (0, 0, 0, 70);
  QColor darkBlue (95, 95, 211);
  QPixmap background (20, 8);
  background.fill (whitish);

  palette = QPalette (Qt::white);
  palette.setBrush (QPalette::BrightText, whitish);
  palette.setBrush (QPalette::Base, whitish);
  palette.setBrush (QPalette::Highlight, darkBlue);
  palette.setBrush(QPalette::ButtonText, QColor(229, 229, 229, 70));
  qDebug () << "Inside polish";
}

void
BaseStyle::polish (QWidget * widget)
{
  //qDebug () << "Inside polish";
  if (!qobject_cast < QLineEdit * >(widget))
  	widget->setAttribute (Qt::WA_Hover, true);
  else if(qobject_cast < QPushButton * >(widget)){
  	QPalette palette;
	palette.setBrush(QPalette::ButtonText, QColor(0,0,0, 70));
  	widget->setPalette(palette);
  }
  //widget->palette().setBrush (QPalette::BrightText, QColor(229, 229, 229, 70));
}

void
BaseStyle::unpolish (QWidget * widget)
{
  if (!qobject_cast < QLineEdit * >(widget))
    widget->setAttribute (Qt::WA_Hover, false);
  else
    {
    }
}

void
BaseStyle::setTexture (QPalette & palette, QPalette::ColorRole role,
		       const QPixmap & pixmap)
{
  for (int i = 0; i < QPalette::NColorGroups; i++)
    {
      QColor color = palette.brush (QPalette::ColorGroup (i), role).color ();
      palette.setBrush (QPalette::ColorGroup (i), role,
			QBrush (color, pixmap));
    }
}

QPainterPath
BaseStyle::roundedRect (const QRect & rect, int radius) const 
{
  int rad = (radius < 0) ? qMin (rect.width (), rect.height ()) / 2 : radius;
  int diam = rad << 1;
  int x1, x2, y1, y2;
  rect.getCoords (&x1, &y1, &x2, &y2);
  QPainterPath path;
  path.moveTo (x2, y1 + rad);
  path.arcTo (QRect (x2 - diam, y1, diam, diam), 0.0, +90.0);
  path.lineTo (x1 + radius, y1);
  path.arcTo (QRect (x1, y1, diam, diam), 90.0, +90.0);
  path.lineTo (x1, y2 - radius);
  path.arcTo (QRect (x1, y2 - diam, diam, diam), 180.0, +90.0);
  path.lineTo (x1 + radius, y2);
  path.arcTo (QRect (x2 - diam, y2 - diam, diam, diam), 270.0, +90.0);
  path.closeSubpath ();
  return path;
}

void BaseStyle :: drawShadedPanel(QPainter *p,const QRect &r,const QPalette &palette,const QColor &_shade,
				bool sunken,bool hasFocus,int lineWidth,const QBrush *fill) const
{
	//qDebug() << "Sunken : " << sunken;
	QColor shade = _shade;//QColor(49,127,205);//palette.dark().color();
	QColor light = palette.light().color();
	if (fill) {
		if (fill->color() == shade)
			shade = palette.shadow().color();
		if (fill->color() == light)
		    light = palette.midlight().color();
	}
	QPen oldPen = p->pen();
	QVector<QLineF> lines;
	if(hasFocus)
		lines.reserve(2*lineWidth);
	else
		lines.reserve(lineWidth);

	if(sunken)
		p->setPen(shade);
	else
		p->setPen(light);

	int x1,x2,y1,y2;
	if(hasFocus) {
		x1 = r.x();
		y1 = y2 = r.y();
		x2 = x1 + r.width();
		for(int i=0;i<lineWidth;i++)
			lines << QLineF(x1,y1++,x2,y2++); //top
		x2 = x1;
	    y1 = r.y()+r.height();
	    for (int i=0; i<lineWidth; i++)
	        lines << QLineF(x1++, y1, x2++, y2); //left
	    p->drawLines(lines);
	    lines.clear();
	}
	x1 = r.x(); 
	y1 = y2 = r.y()+r.height();
	x2 = x1+r.width();
	for(int i = 0;i<lineWidth;i++)
		lines << QLineF(x1, y1--, x2, y2--); //bottom
	if(hasFocus) {
		x1 = x2;
	    y1 = r.y();
	    y2 = r.y()+r.height()-lineWidth;
	    for (int i=0; i<lineWidth; i++)
		    lines << QLineF(x1--, y1, x2--, y2); //right
	}
	p->drawLines(lines);
	/*p->setPen(Qt::NoPen);
	p->drawRoundedRect(r.x()+lineWidth,r.y()+lineWidth,r.width()-lineWidth,r.height()-lineWidth,4,4);*/
	QBrush brush(QColor(49,127,205,15),Qt::SolidPattern);
	//if(fill)
		p->fillRect(r.x()+lineWidth,r.y()+lineWidth,r.width()-lineWidth,r.height()-lineWidth,brush);
	p->setPen(oldPen);
}
