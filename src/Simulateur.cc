#include <iostream>

#include "../include/core/Systeme.h"
#include "../include/states/State.h"
#include "../include/states/StateManager.h"
#include "../include/states/MainGState.h"
#include "../include/states/Loginstate.h"

int main(int argc, char const *argv[])
{	
	StateManager sm ;
	Loginstate* ls = new Loginstate();
	sm.PushState(ls);
	sm.GetCurrentState()->update();
	//Régler la transition entre les states
	sm.PushState(new MainGState());
	sm.GetCurrentState()->update();
    return 0;
} 
