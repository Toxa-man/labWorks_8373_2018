LIBS += -L"/home/jordano/Downloads/SFML-master"
LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system


INCLUDEPATH += "/home/jordano/Downloads/SFML-master/include"
DEPENDPATH += "/home/jordano/Downloads/SFML-master/include"

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
