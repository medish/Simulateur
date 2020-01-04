#include <iostream>
#include <QApplication>
#include "../include/core/Systeme.h"
#include "../include/states/State.h"
#include "../include/states/StateManager.h"
#include "../include/states/MainGState.h"
#include "../include/states/Loginstate.h"


int main(int argc, char  *argv[]){	
    if(argc > 2){
       std::cerr << "Erreure d'utilistation: ./Simulateur [Fichier XML] " << std::endl;
    }
    std::cout << "DEBUG: Parsing file" << argv[1] << std::endl;
    QApplication app(argc, argv);
    StateManager sm(argv[1]);
    Loginstate* ls = new Loginstate();
    //MainGState * m = new MainGState("");
    sm.PushState(ls);
    sm.GetCurrentState()->update();

    return app.exec();
}
