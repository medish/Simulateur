#include <iostream>
#include <QApplication>

#include "../include/core/Systeme.h"
#include "../include/states/State.h"
#include "../include/states/StateManager.h"
#include "../include/states/MainGState.h"

int main(int argc, char  *argv[]){
    QApplication a(argc, argv);

    StateManager sm ;
    MainGState * gstate = new MainGState();

    sm.PushState(gstate);
    sm.GetCurrentState()->update();

    return a.exec();
} 
