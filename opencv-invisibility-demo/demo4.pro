TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

#一般来说，一个程序都是有很多个代码文件组成的，这些文件的关系需要有一个文件来管理它们
#工程文件.pro文件

INCLUDEPATH += D:\opencv_3.4.2_Qt\opencv_3.4.2_Qt\include
LIBS += D:\opencv_3.4.2_Qt\opencv_3.4.2_Qt\x86\bin\libopencv_*.dll
