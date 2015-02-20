CONFIG += debug
TEMPLATE = app
TARGET = gdrive
INCLUDEPATH += ./include
QT += core gui widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
# Input
CONFIG(debug, debug|release) {
    DEFINES += _DEBUG
    OBJECTS_DIR = ./DebugIntermediate
    MOC_DIR = ./GenFiles/Debug
    #RCC_DIR = ./GenFiles
    #DESTDIR = ./Debug
}
#RESOURCES     = gdrive.qrc
HEADERS += ./include/gui/style/BaseStyle.h \
		   ./include/gui/style/PushButtonStyle.h \
		   ./include/gui/style/LineEditStyle.h \
		   ./include/gui/Animation.h \
		   ./include/gui/style/CheckBoxStyle.h \
		   ./include/gui/BaseWidget.h \
		   ./include/gui/LoginWidget.h \
		   ./include/gui/InputField.h \
		   ./include/BaseApplication.h\ 
		   ./include/BaseAppWindow.h \
		   ./include/AppWindow.h \
		   ./include/Application.h \
		   ./include/StyleAttribute.h \
		   ./include/util/utils.h
SOURCES += main.cpp \
		   BaseAppWindow.cpp \
		   AppWindow.cpp \
		   Application.cpp \
		   ./gui/style/BaseStyle.cpp \
		   ./gui/style/PushButtonStyle.cpp \
		   ./gui/style/LineEditStyle.cpp \
		   ./gui/Animation.cpp\
		   ./gui/InputField.cpp\
		   ./gui/style/CheckBoxStyle.cpp \
		   ./gui/BaseWidget.cpp \
		   ./gui/LoginWidget.cpp \
		   ./util/utils.cpp
