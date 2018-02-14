TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:\opencv\build\include"

LIBS += -L"C:\opencv\build\lib\Release" -lopencv_highgui330 \
                                        -lopencv_core330 \
                                        -lopencv_imgproc330 \
                                        -lopencv_imgcodecs330

SOURCES += main.cpp
