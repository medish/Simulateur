#include <iostream>
#include "../include/core/Systeme.h"
#include "../include/states/State.h"
#include "../include/states/StateManager.h"
#include "../include/states/MainGState.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char  *argv[]){
	/*StateManager sm ;
	sm.PushState(new MainGState());

	sm.GetCurrentState()->update();
	*/
   // MainGState gstate;
    QApplication a(argc, argv);
    QPushButton bouton("Salut les Zéros, la forme ?");
    bouton.show();
    return a.exec();
} 
