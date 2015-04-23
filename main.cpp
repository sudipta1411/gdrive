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
#include "gjson/gjson_reader.h"
#include "util/HashMap.h"
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace GJSON;
using namespace std;
using namespace std::chrono;

string getFileContent(const string file_name)
{
  std::ifstream file(file_name);
  std::string str;
  std::string file_contents;
  while (std::getline(file, str))
  {
      file_contents += str;
      file_contents.push_back('\n');
  }
  file.close();
  return file_contents;
}

int
main (int argc, char **argv)
{
    std::string t = string("{'ab':[1,2,3,false,{'ef' : 'sudipta','gh':'roy'},42],\n") 
          + "'cd': ' Hello world '" + "}";
    t = getFileContent("test.json");
    cout << t << endl;
    GJsonReader reader(t);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    reader.parse();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << duration << std::endl;
    string key = "required";
    string value;
    GenericValue* s = reader.getValue(key);
    /*if(s==nullptr)
        cout<<"opps"<<endl;
    getValue(s,value);*/
    if(s->getType() == array_value)
    {
      GJsonArray* arr = gjson_cast<GJsonArray*>(s);
      GJsonString* m = gjson_cast<GJsonString*>(arr->get(1));
      //key = "gh";
      //getValue((*m)[key],value);
      cout << "at 4 : " << m->getValue()<<endl;//gjson_cast<GJsonLong*>(arr->get(4))->getValue()<<endl;
    }
    cout<<"Value XX: "<<value<<endl;
    cout << "ok : " << reader.ok()<<endl;
  Application app (argc, argv);
  return app.exec ();
}

