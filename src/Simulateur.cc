#include <iostream>

#include "../include/core/Systeme.h"
#include "../include/states/State.h"
#include "../include/states/StateManager.h"
#include "../include/states/MainGState.h"

int main(int argc, char const *argv[])
{	
	StateManager sm ;
	sm.PushState(new MainGState());

	sm.GetCurrentState()->update();
	
	return 0; 
} 