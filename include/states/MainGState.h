#ifndef H_MAINGSTATE
#define H_MAINGSTATE

#include <ctime>
#include <unistd.h>

#include "State.h"
#include "../core/Systeme.h"
#include "../gui/MainGui.h"
#include "../include/utils/xmlparser.h"

class State;

class MainGState : public State {
private:
    Systeme* sys;
    MainGui * mainGui;
public:
    MainGState(double cap, double consomation, int _duree, int tactuel);
    MainGState(QString);
    ~MainGState();
    //Getters
    MainGui * getMainGui(){return mainGui;}
    void init(){};
    void init(double cap, double consomation, int _duree, int tactuel);
    void init(QString);
    void free();
    void display();
    void update();
};


#endif
