  GJsonString* js = gjson_cast<GJsonString*>(v);//dynamic_cast<GJsonString*>(v);
  if(!js)
    std::cout<<"Invalid conversion" << std::endl;
  else
  	std::cout << j->getValue() << "," << js->getValue() << std::endl;
  delete array;
  HashMap<std::string,std::string> hm;
  hm.put("A","XYZ");
  Application app (argc, argv);
  /*QPalette pal = app.palette();
  pal.setColor(QPalette::Window, Qt::white);
  app.setPalette(pal);
  QPushButton *quitButton = new QPushButton("Login");
  quitButton->setMinimumWidth(60);
  quitButton->setMinimumHeight(50);
  quitButton->setStyle (new PushButtonStyle(QColor(91,116,168)));
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
  AppWindow window;
  window.initSize();
  window.initColor(QColor(208,205,204));
  window.firstShow();*/
  return app.exec ();
}

