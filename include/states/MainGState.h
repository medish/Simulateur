#ifndef H_MAINGSTATE
#define H_MAINGSTATE

#include <ctime>
#include <unistd.h>

#include "State.h"
#include "../core/Systeme.h"
#include "../gui/MainGui.h"

class State;

class MainGState : public State {
private:
	Systeme* sys;
    MainGui * mainGui;
public:

	MainGState();
	~MainGState();
    //Getters
    MainGui * getMainGui(){return mainGui;}
	void init();
	void free();
    void display();
	void update();
};


#endif
