#include "../../include/core/Systeme.h"
#include "../../include/states/MainGState.h"
#include "../../include/gui/MainGui.h"


MainGState::MainGState(const char* infile){
    init(infile);
}

MainGState::~MainGState(){
        free();
}

void MainGState::init(){
  sys = new Systeme(400);
  mainGui = new MainGui(sys);
}

void MainGState::init(const char* infile){
    //Appel au Parser pour charger un fichier
   // std::cout << "DEBUG: Loading simulation file" << std::endl;
    xmlparser parser(infile);
    parser.parseXmlFile();
    sys = parser.GetSysteme();
    mainGui = new MainGui(sys);
    //mainGui->show();

}

void MainGState::free(){
        delete sys;
        delete mainGui;
}

void MainGState::update(){
	/**
	 * Délplacer dans une classe
	 */
    display();
    //time_t starttime;
    //time(&starttime);
    //time_t endtime;

    //std::cout << starttime << std::endl;

    //sys->AfficherEtat();

        //Boucle de jeu de la simulation (Ajouter le sortie forcée par l'utilisateur comme condition d'arrêt)

    while(sys->GetCapacity() > 0){
                std::cout<<"debug::while_boucle "<<sys->GetCapacity()<<std::endl;
                sys->updateconso();
                mainGui->updateGui();
                sleep(1);//Consommation du moteur par seconde
    }


    //sys->AfficherEtat();

    //time(&endtime);

    //std::cout << starttime << std::endl;
    //std::cout << "La simulation à duré "<< endtime - starttime << " Secondes" << std::endl;

}

void MainGState::display(){
    mainGui->show();
}
