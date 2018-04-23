include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     

libutilities = ../utilities

INCLUDEPATH += . $$libutilities 

SOURCES += main.cpp textutils_ut.cpp 

LIBS += -L$$libutilities -lutilities -lpthread
