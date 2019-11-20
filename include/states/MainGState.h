#ifndef H_MAINGSTATE
#define H_MAINGSTATE

#include <ctime>
#include <unistd.h>

#include "State.h"
#include "../core/Systeme.h"

class State;

class MainGState : public State {
private:
	Systeme* sys;
public:

	MainGState();
	~MainGState();
	void init();
	void free();
	void display(){};
	void update();
};


#endif