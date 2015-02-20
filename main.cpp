#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <QString>
#include <QFile>
#include <QLineEdit>
#include <QCheckBox>
//#include "Style.h"
#include "gui/style/PushButtonStyle.h"
#include "gui/style/LineEditStyle.h"
#include "gui/style/CheckBoxStyle.h"
#include "gui/InputField.h"
//#include "gui/MyButton.h"
#include "BaseApplication.h"
#include "AppWindow.h"
#include "Application.h"
#include "gui/Animation.h"

int
main (int argc, char **argv)
{
  Application app (argc, argv);
  QPalette pal = app.palette();
  pal.setColor(QPalette::Window, Qt::white);
  app.setPalette(pal);
  QPushButton *quitButton = new QPushButton("Login");
  quitButton->setMinimumWidth(60);
  quitButton->setMinimumHeight(50);
  quitButton->setStyle (new PushButtonStyle);
  QLineEdit *lineEdit = new QLineEdit();
  lineEdit->setPlaceholderText("Username");
  lineEdit->setMinimumWidth(50);
  lineEdit->setMinimumHeight(30);
  //lineEdit->setStyle(new LineEditStyle(QColor(49,127,205)));
  QLineEdit *lineEdit1 = new QLineEdit();
  lineEdit1->setEchoMode(QLineEdit::Password);
  lineEdit1->setMinimumWidth(50);
  lineEdit1->setMinimumHeight(30);
  lineEdit1->setStyle(new LineEditStyle(QColor(49,127,205)));
  QCheckBox *checkBox = new QCheckBox("CheckBox");
  //checkBox->setTristate(true);
  checkBox->setStyle(new CheckBoxStyle);
  QVBoxLayout *layout = new QVBoxLayout ();
  layout->addWidget (quitButton);
  layout->addWidget(lineEdit);
  layout->addWidget(lineEdit1);
  layout->addWidget(checkBox);
  QWidget widget;
  widget.setMinimumWidth(300);
  widget.setMinimumHeight(400);
  widget.setLayout (layout);
  //widget.show ();
  /*AppWindow window;
  window.initSize();
  window.initColor(QColor(208,205,204));
  window.firstShow();*/
  return app.exec ();
}

