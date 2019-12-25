#include "../../include/core/Systeme.h"
#include "../../include/states/MainGState.h"
#include "../../include/gui/MainGui.h"

MainGState::MainGState(){
	init();
}

MainGState::~MainGState(){
	free();
}

void MainGState::init(){
	sys = new Systeme(400);
	

}

void MainGState::free(){
	delete sys;
}

void MainGState::update(){
	/**
	 * Délplacer dans une classe
	 */
	time_t starttime;
	time(&starttime);
	time_t endtime;

	std::cout << starttime << std::endl;

	sys->AfficherEtat();

	//Boucle de jeu de la simulation (Ajouter le sortie forcée par l'utilisateur comme condition d'arrêt)	
	while(sys->GetCapacity() > 0){
		sys->updateconso();
		sleep(1);//Consommation du moteur par seconde
	}

	sys->AfficherEtat();
	
	time(&endtime);

	std::cout << starttime << std::endl;
	std::cout << "La simulation à duré "<< endtime - starttime << " Secondes" << std::endl; 	

}