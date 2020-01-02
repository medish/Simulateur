#include <QApplication>

#include "../include/core/Systeme.h"
#include "../include/states/State.h"
#include "../include/states/StateManager.h"
#include "../include/states/MainGState.h"
#include "../include/states/Loginstate.h"
#include "../include/utils/xmlparser.h"

int main(int argc, char  *argv[]){	
  /*
  if(argc > 2){
       std::cerr << "Erreure d'utilistation: ./Simulateur [Fichier XML] " << std::endl;
    }
    */
   QApplication app(argc, argv);
   xmlparser parser("../../assets/pannes/pannes1.xml");
   parser.parseXmlFile();
    StateManager sm;
    Loginstate* ls = new Loginstate();
    sm.PushState(ls);
    sm.GetCurrentState()->update();

    return app.exec();
}
