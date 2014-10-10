TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    celestialbody.cpp \
    solarsystem.cpp \
    vec3.cpp \
    rk4.cpp

HEADERS += \
    celestialbody.h \
    solarsystem.h \
    vec3.h \
    rk4.h

