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
#include "gjson/gjson_value.h"
#include "util/HashMap.h"
#include <string>
#include <iostream>
using namespace gjson;

int
main (int argc, char **argv)
{
  /*XXX TEST MAIN FILE*/
  /*std::string s("hello world");
  GJsonInt *j_int = new GJsonInt(10);
  std::cout << "stringify : " << j_int->stringify()<< std::endl;
  GJsonString *j_string = new GJsonString(s);*/
  //std::cout << j_string->getValue() << std::endl;
  /*GJsonArray *array = new GJsonArray();
  array->add(j_int);
  array->add(j_string);
  GenericValue* v = array->get(0);
  GJsonInt* j = dynamic_cast<GJsonInt*>(v);gjson_cast<GJsonInt*>(v);
  v = array->get(1);
  GJsonString* js = gjson_cast<GJsonString*>(v);//dynamic_cast<GJsonString*>(v);
  if(!js)
    std::cout<<"Invalid conversion" << std::endl;
  else
  	std::cout << j->getValue() << "," << js->getValue() << std::endl;
  delete array;*/
  /*GJsonMap *map = new GJsonMap();
  map->put("A",j_string);
  map->put("B",j_int);
  GenericValue* val = map->get("A");
  GJsonString* s1 = gjson_cast<GJsonString*>(val);
  std::cout << "MAP : " << s1->getValue() << std::endl;
  val = map->get("B");
  GJsonInt *i1 = gjson_cast<GJsonInt*>(val);
  std::cout << "MAP : " << i1->getValue() << std::endl;
  delete map;*/
  {
    std::string s("hello world");
    Node* root;
    GJsonString *j_str = new GJsonString(s);
    GJsonMap* map1 = new GJsonMap("A",j_str);
    root = new Node(map1);
    std::string s1("Hello World");
    GJsonMap* map2 = new GJsonMap("B",new GJsonString(s1));
    root->addNode(map2);
    GenericValue* v = root->findValueInNode("A");
    if(!v)
    {
        std::cout << "Not found" << std::endl;
        return -1;
    }
    GJsonMap* m = gjson_cast<GJsonMap*>(v);
    Node* n = m->getNode();
    GJsonString* str = gjson_cast<GJsonString*>(n->value);
    std::cout << str->getValue() << std::endl;
    delete root;
  }
  Application app (argc, argv);
  return app.exec ();
}

