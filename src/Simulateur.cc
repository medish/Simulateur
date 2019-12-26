#include <iostream>
#include <QApplication>

#include "../include/core/Systeme.h"
#include "../include/states/State.h"
#include "../include/states/StateManager.h"
#include "../include/states/MainGState.h"
#include "../include/gui/MainGui.h"

int main(int argc, char  *argv[]){
	/*StateManager sm ;
	sm.PushState(new MainGState());

	sm.GetCurrentState()->update();
	*/
   // MainGState gstate;
    QApplication a(argc, argv);
    MainGui m;

    m.show();

    return a.exec();
} 
