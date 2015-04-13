#############################################################################
# Makefile for building: gdrive
# Generated by qmake (3.0) (Qt 5.3.0)
# Project:  gdrive.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt5/bin/qmake -o Makefile gdrive.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -D_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -m64 -pipe -g -Wall -W -D_REENTRANT -fPIE $(DEFINES)
CXXFLAGS      = -m64 -pipe -g -std=c++0x -Wall -W -D_REENTRANT -fPIE $(DEFINES)
INCPATH       = -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I. -Iinclude -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -IGenFiles/Debug
LINK          = g++
LFLAGS        = -m64
LIBS          = $(SUBLIBS) -L/usr/X11R6/lib64 -lQt5Widgets -L/usr/lib/x86_64-linux-gnu -lQt5Gui -lQt5Core -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt5/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = DebugIntermediate/

####### Files

SOURCES       = main.cpp \
		BaseAppWindow.cpp \
		AppWindow.cpp \
		Application.cpp \
		gui/style/BaseStyle.cpp \
		gui/style/PushButtonStyle.cpp \
		gui/style/LineEditStyle.cpp \
		gui/Animation.cpp \
		gui/InputField.cpp \
		gui/Button.cpp \
		gui/style/CheckBoxStyle.cpp \
		gui/BaseWidget.cpp \
		gui/LoginWidget.cpp \
		util/utils.cpp \
		util/HashCode.cpp \
		gjson/gjson_reader.cpp GenFiles/Debug/moc_BaseStyle.cpp \
		GenFiles/Debug/moc_PushButtonStyle.cpp \
		GenFiles/Debug/moc_LineEditStyle.cpp \
		GenFiles/Debug/moc_Animation.cpp \
		GenFiles/Debug/moc_CheckBoxStyle.cpp \
		GenFiles/Debug/moc_BaseWidget.cpp \
		GenFiles/Debug/moc_LoginWidget.cpp \
		GenFiles/Debug/moc_InputField.cpp \
		GenFiles/Debug/moc_Button.cpp \
		GenFiles/Debug/moc_BaseApplication.cpp \
		GenFiles/Debug/moc_BaseAppWindow.cpp \
		GenFiles/Debug/moc_AppWindow.cpp \
		GenFiles/Debug/moc_Application.cpp
OBJECTS       = DebugIntermediate/main.o \
		DebugIntermediate/BaseAppWindow.o \
		DebugIntermediate/AppWindow.o \
		DebugIntermediate/Application.o \
		DebugIntermediate/BaseStyle.o \
		DebugIntermediate/PushButtonStyle.o \
		DebugIntermediate/LineEditStyle.o \
		DebugIntermediate/Animation.o \
		DebugIntermediate/InputField.o \
		DebugIntermediate/Button.o \
		DebugIntermediate/CheckBoxStyle.o \
		DebugIntermediate/BaseWidget.o \
		DebugIntermediate/LoginWidget.o \
		DebugIntermediate/utils.o \
		DebugIntermediate/HashCode.o \
		DebugIntermediate/gjson_reader.o \
		DebugIntermediate/moc_BaseStyle.o \
		DebugIntermediate/moc_PushButtonStyle.o \
		DebugIntermediate/moc_LineEditStyle.o \
		DebugIntermediate/moc_Animation.o \
		DebugIntermediate/moc_CheckBoxStyle.o \
		DebugIntermediate/moc_BaseWidget.o \
		DebugIntermediate/moc_LoginWidget.o \
		DebugIntermediate/moc_InputField.o \
		DebugIntermediate/moc_Button.o \
		DebugIntermediate/moc_BaseApplication.o \
		DebugIntermediate/moc_BaseAppWindow.o \
		DebugIntermediate/moc_AppWindow.o \
		DebugIntermediate/moc_Application.o
DIST          = /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/shell-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/c++11.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		gdrive.pro main.cpp \
		BaseAppWindow.cpp \
		AppWindow.cpp \
		Application.cpp \
		gui/style/BaseStyle.cpp \
		gui/style/PushButtonStyle.cpp \
		gui/style/LineEditStyle.cpp \
		gui/Animation.cpp \
		gui/InputField.cpp \
		gui/Button.cpp \
		gui/style/CheckBoxStyle.cpp \
		gui/BaseWidget.cpp \
		gui/LoginWidget.cpp \
		util/utils.cpp \
		util/HashCode.cpp \
		gjson/gjson_reader.cpp
QMAKE_TARGET  = gdrive
DESTDIR       = #avoid trailing-slash linebreak
TARGET        = gdrive


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: gdrive.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/shell-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/c++11.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		gdrive.pro \
		/usr/lib/x86_64-linux-gnu/libQt5Widgets.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Gui.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Core.prl
	$(QMAKE) -o Makefile gdrive.pro
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/shell-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/c++11.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
gdrive.pro:
/usr/lib/x86_64-linux-gnu/libQt5Widgets.prl:
/usr/lib/x86_64-linux-gnu/libQt5Gui.prl:
/usr/lib/x86_64-linux-gnu/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile gdrive.pro

qmake_all: FORCE

dist: 
	@test -d DebugIntermediate/gdrive1.0.0 || mkdir -p DebugIntermediate/gdrive1.0.0
	$(COPY_FILE) --parents $(DIST) DebugIntermediate/gdrive1.0.0/ && $(COPY_FILE) --parents include/gui/style/BaseStyle.h include/gui/style/PushButtonStyle.h include/gui/style/LineEditStyle.h include/gui/Animation.h include/gui/style/CheckBoxStyle.h include/gui/BaseWidget.h include/gui/LoginWidget.h include/gui/InputField.h include/gui/Button.h include/BaseApplication.h include/BaseAppWindow.h include/AppWindow.h include/Application.h include/StyleAttribute.h include/util/utils.h include/util/HashCode.h include/util/HashMap.h include/gjson/gjson_type.h include/gjson/gjson_reader.h include/gjson/gjson_value.h DebugIntermediate/gdrive1.0.0/ && $(COPY_FILE) --parents main.cpp BaseAppWindow.cpp AppWindow.cpp Application.cpp gui/style/BaseStyle.cpp gui/style/PushButtonStyle.cpp gui/style/LineEditStyle.cpp gui/Animation.cpp gui/InputField.cpp gui/Button.cpp gui/style/CheckBoxStyle.cpp gui/BaseWidget.cpp gui/LoginWidget.cpp util/utils.cpp util/HashCode.cpp gjson/gjson_reader.cpp DebugIntermediate/gdrive1.0.0/ && (cd `dirname DebugIntermediate/gdrive1.0.0` && $(TAR) gdrive1.0.0.tar gdrive1.0.0 && $(COMPRESS) gdrive1.0.0.tar) && $(MOVE) `dirname DebugIntermediate/gdrive1.0.0`/gdrive1.0.0.tar.gz . && $(DEL_FILE) -r DebugIntermediate/gdrive1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all: GenFiles/Debug/moc_BaseStyle.cpp GenFiles/Debug/moc_PushButtonStyle.cpp GenFiles/Debug/moc_LineEditStyle.cpp GenFiles/Debug/moc_Animation.cpp GenFiles/Debug/moc_CheckBoxStyle.cpp GenFiles/Debug/moc_BaseWidget.cpp GenFiles/Debug/moc_LoginWidget.cpp GenFiles/Debug/moc_InputField.cpp GenFiles/Debug/moc_Button.cpp GenFiles/Debug/moc_BaseApplication.cpp GenFiles/Debug/moc_BaseAppWindow.cpp GenFiles/Debug/moc_AppWindow.cpp GenFiles/Debug/moc_Application.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) GenFiles/Debug/moc_BaseStyle.cpp GenFiles/Debug/moc_PushButtonStyle.cpp GenFiles/Debug/moc_LineEditStyle.cpp GenFiles/Debug/moc_Animation.cpp GenFiles/Debug/moc_CheckBoxStyle.cpp GenFiles/Debug/moc_BaseWidget.cpp GenFiles/Debug/moc_LoginWidget.cpp GenFiles/Debug/moc_InputField.cpp GenFiles/Debug/moc_Button.cpp GenFiles/Debug/moc_BaseApplication.cpp GenFiles/Debug/moc_BaseAppWindow.cpp GenFiles/Debug/moc_AppWindow.cpp GenFiles/Debug/moc_Application.cpp
GenFiles/Debug/moc_BaseStyle.cpp: include/gui/style/BaseStyle.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/sudipta/gdrive -I/home/sudipta/gdrive/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/4.9 -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9/backward -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/gui/style/BaseStyle.h -o GenFiles/Debug/moc_BaseStyle.cpp

GenFiles/Debug/moc_PushButtonStyle.cpp: include/gui/style/BaseStyle.h \
		include/gui/style/PushButtonStyle.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/sudipta/gdrive -I/home/sudipta/gdrive/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/4.9 -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9/backward -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/gui/style/PushButtonStyle.h -o GenFiles/Debug/moc_PushButtonStyle.cpp

GenFiles/Debug/moc_LineEditStyle.cpp: include/gui/style/BaseStyle.h \
		include/gui/style/LineEditStyle.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/sudipta/gdrive -I/home/sudipta/gdrive/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/4.9 -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9/backward -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/gui/style/LineEditStyle.h -o GenFiles/Debug/moc_LineEditStyle.cpp

GenFiles/Debug/moc_Animation.cpp: include/gui/Animation.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/sudipta/gdrive -I/home/sudipta/gdrive/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/4.9 -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9/backward -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/gui/Animation.h -o GenFiles/Debug/moc_Animation.cpp

GenFiles/Debug/moc_CheckBoxStyle.cpp: include/gui/style/BaseStyle.h \
		include/gui/style/CheckBoxStyle.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/sudipta/gdrive -I/home/sudipta/gdrive/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/4.9 -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9/backward -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/gui/style/CheckBoxStyle.h -o GenFiles/Debug/moc_CheckBoxStyle.cpp

GenFiles/Debug/moc_BaseWidget.cpp: include/gui/BaseWidget.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/sudipta/gdrive -I/home/sudipta/gdrive/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/4.9 -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9/backward -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/gui/BaseWidget.h -o GenFiles/Debug/moc_BaseWidget.cpp

GenFiles/Debug/moc_LoginWidget.cpp: include/gui/BaseWidget.h \
		include/gui/InputField.h \
		include/gui/Button.h \
		include/gui/style/PushButtonStyle.h \
		include/gui/style/BaseStyle.h \
		include/gui/Animation.h \
		include/StyleAttribute.h \
		include/gui/LoginWidget.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/sudipta/gdrive -I/home/sudipta/gdrive/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/4.9 -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9/backward -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/gui/LoginWidget.h -o GenFiles/Debug/moc_LoginWidget.cpp

GenFiles/Debug/moc_InputField.cpp: include/gui/InputField.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/sudipta/gdrive -I/home/sudipta/gdrive/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/4.9 -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9/backward -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/gui/InputField.h -o GenFiles/Debug/moc_InputField.cpp

GenFiles/Debug/moc_Button.cpp: include/gui/style/PushButtonStyle.h \
		include/gui/style/BaseStyle.h \
		include/gui/Button.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/sudipta/gdrive -I/home/sudipta/gdrive/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/4.9 -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9/backward -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/gui/Button.h -o GenFiles/Debug/moc_Button.cpp

GenFiles/Debug/moc_BaseApplication.cpp: include/BaseApplication.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/sudipta/gdrive -I/home/sudipta/gdrive/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/4.9 -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9/backward -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/BaseApplication.h -o GenFiles/Debug/moc_BaseApplication.cpp

GenFiles/Debug/moc_BaseAppWindow.cpp: include/BaseAppWindow.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/sudipta/gdrive -I/home/sudipta/gdrive/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/4.9 -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9/backward -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/BaseAppWindow.h -o GenFiles/Debug/moc_BaseAppWindow.cpp

GenFiles/Debug/moc_AppWindow.cpp: include/gui/LoginWidget.h \
		include/gui/BaseWidget.h \
		include/gui/InputField.h \
		include/gui/Button.h \
		include/gui/style/PushButtonStyle.h \
		include/gui/style/BaseStyle.h \
		include/gui/Animation.h \
		include/StyleAttribute.h \
		include/BaseAppWindow.h \
		include/AppWindow.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/sudipta/gdrive -I/home/sudipta/gdrive/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/4.9 -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9/backward -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/AppWindow.h -o GenFiles/Debug/moc_AppWindow.cpp

GenFiles/Debug/moc_Application.cpp: include/BaseApplication.h \
		include/AppWindow.h \
		include/gui/LoginWidget.h \
		include/gui/BaseWidget.h \
		include/gui/InputField.h \
		include/gui/Button.h \
		include/gui/style/PushButtonStyle.h \
		include/gui/style/BaseStyle.h \
		include/gui/Animation.h \
		include/StyleAttribute.h \
		include/BaseAppWindow.h \
		include/Application.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/sudipta/gdrive -I/home/sudipta/gdrive/include -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/4.9 -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9/backward -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/4.9/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include include/Application.h -o GenFiles/Debug/moc_Application.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

DebugIntermediate/main.o: main.cpp include/gui/style/PushButtonStyle.h \
		include/gui/style/BaseStyle.h \
		include/gui/style/LineEditStyle.h \
		include/gui/style/CheckBoxStyle.h \
		include/gui/InputField.h \
		include/BaseApplication.h \
		include/AppWindow.h \
		include/gui/LoginWidget.h \
		include/gui/BaseWidget.h \
		include/gui/Button.h \
		include/gui/Animation.h \
		include/StyleAttribute.h \
		include/BaseAppWindow.h \
		include/Application.h \
		include/util/HashMap.h \
		include/util/HashCode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/main.o main.cpp

DebugIntermediate/BaseAppWindow.o: BaseAppWindow.cpp include/BaseAppWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/BaseAppWindow.o BaseAppWindow.cpp

DebugIntermediate/AppWindow.o: AppWindow.cpp include/AppWindow.h \
		include/gui/LoginWidget.h \
		include/gui/BaseWidget.h \
		include/gui/InputField.h \
		include/gui/Button.h \
		include/gui/style/PushButtonStyle.h \
		include/gui/style/BaseStyle.h \
		include/gui/Animation.h \
		include/StyleAttribute.h \
		include/BaseAppWindow.h \
		include/util/utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/AppWindow.o AppWindow.cpp

DebugIntermediate/Application.o: Application.cpp include/Application.h \
		include/BaseApplication.h \
		include/AppWindow.h \
		include/gui/LoginWidget.h \
		include/gui/BaseWidget.h \
		include/gui/InputField.h \
		include/gui/Button.h \
		include/gui/style/PushButtonStyle.h \
		include/gui/style/BaseStyle.h \
		include/gui/Animation.h \
		include/StyleAttribute.h \
		include/BaseAppWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/Application.o Application.cpp

DebugIntermediate/BaseStyle.o: gui/style/BaseStyle.cpp include/gui/style/BaseStyle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/BaseStyle.o gui/style/BaseStyle.cpp

DebugIntermediate/PushButtonStyle.o: gui/style/PushButtonStyle.cpp include/gui/style/PushButtonStyle.h \
		include/gui/style/BaseStyle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/PushButtonStyle.o gui/style/PushButtonStyle.cpp

DebugIntermediate/LineEditStyle.o: gui/style/LineEditStyle.cpp include/gui/style/LineEditStyle.h \
		include/gui/style/BaseStyle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/LineEditStyle.o gui/style/LineEditStyle.cpp

DebugIntermediate/Animation.o: gui/Animation.cpp include/gui/Animation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/Animation.o gui/Animation.cpp

DebugIntermediate/InputField.o: gui/InputField.cpp include/gui/InputField.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/InputField.o gui/InputField.cpp

DebugIntermediate/Button.o: gui/Button.cpp include/gui/Button.h \
		include/gui/style/PushButtonStyle.h \
		include/gui/style/BaseStyle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/Button.o gui/Button.cpp

DebugIntermediate/CheckBoxStyle.o: gui/style/CheckBoxStyle.cpp include/gui/style/CheckBoxStyle.h \
		include/gui/style/BaseStyle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/CheckBoxStyle.o gui/style/CheckBoxStyle.cpp

DebugIntermediate/BaseWidget.o: gui/BaseWidget.cpp include/gui/BaseWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/BaseWidget.o gui/BaseWidget.cpp

DebugIntermediate/LoginWidget.o: gui/LoginWidget.cpp include/gui/LoginWidget.h \
		include/gui/BaseWidget.h \
		include/gui/InputField.h \
		include/gui/Button.h \
		include/gui/style/PushButtonStyle.h \
		include/gui/style/BaseStyle.h \
		include/gui/Animation.h \
		include/StyleAttribute.h \
		include/util/utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/LoginWidget.o gui/LoginWidget.cpp

DebugIntermediate/utils.o: util/utils.cpp include/util/utils.h \
		include/StyleAttribute.h \
		include/Application.h \
		include/BaseApplication.h \
		include/AppWindow.h \
		include/gui/LoginWidget.h \
		include/gui/BaseWidget.h \
		include/gui/InputField.h \
		include/gui/Button.h \
		include/gui/style/PushButtonStyle.h \
		include/gui/style/BaseStyle.h \
		include/gui/Animation.h \
		include/BaseAppWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/utils.o util/utils.cpp

DebugIntermediate/HashCode.o: util/HashCode.cpp include/util/HashCode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/HashCode.o util/HashCode.cpp

DebugIntermediate/gjson_reader.o: gjson/gjson_reader.cpp include/gjson/gjson_reader.h \
		include/gjson/gjson_type.h \
		include/gjson/gjson_value.h \
		include/util/HashMap.h \
		include/util/HashCode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/gjson_reader.o gjson/gjson_reader.cpp

DebugIntermediate/moc_BaseStyle.o: GenFiles/Debug/moc_BaseStyle.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/moc_BaseStyle.o GenFiles/Debug/moc_BaseStyle.cpp

DebugIntermediate/moc_PushButtonStyle.o: GenFiles/Debug/moc_PushButtonStyle.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/moc_PushButtonStyle.o GenFiles/Debug/moc_PushButtonStyle.cpp

DebugIntermediate/moc_LineEditStyle.o: GenFiles/Debug/moc_LineEditStyle.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/moc_LineEditStyle.o GenFiles/Debug/moc_LineEditStyle.cpp

DebugIntermediate/moc_Animation.o: GenFiles/Debug/moc_Animation.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/moc_Animation.o GenFiles/Debug/moc_Animation.cpp

DebugIntermediate/moc_CheckBoxStyle.o: GenFiles/Debug/moc_CheckBoxStyle.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/moc_CheckBoxStyle.o GenFiles/Debug/moc_CheckBoxStyle.cpp

DebugIntermediate/moc_BaseWidget.o: GenFiles/Debug/moc_BaseWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/moc_BaseWidget.o GenFiles/Debug/moc_BaseWidget.cpp

DebugIntermediate/moc_LoginWidget.o: GenFiles/Debug/moc_LoginWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/moc_LoginWidget.o GenFiles/Debug/moc_LoginWidget.cpp

DebugIntermediate/moc_InputField.o: GenFiles/Debug/moc_InputField.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/moc_InputField.o GenFiles/Debug/moc_InputField.cpp

DebugIntermediate/moc_Button.o: GenFiles/Debug/moc_Button.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/moc_Button.o GenFiles/Debug/moc_Button.cpp

DebugIntermediate/moc_BaseApplication.o: GenFiles/Debug/moc_BaseApplication.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/moc_BaseApplication.o GenFiles/Debug/moc_BaseApplication.cpp

DebugIntermediate/moc_BaseAppWindow.o: GenFiles/Debug/moc_BaseAppWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/moc_BaseAppWindow.o GenFiles/Debug/moc_BaseAppWindow.cpp

DebugIntermediate/moc_AppWindow.o: GenFiles/Debug/moc_AppWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/moc_AppWindow.o GenFiles/Debug/moc_AppWindow.cpp

DebugIntermediate/moc_Application.o: GenFiles/Debug/moc_Application.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DebugIntermediate/moc_Application.o GenFiles/Debug/moc_Application.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

