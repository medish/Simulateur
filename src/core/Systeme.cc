#include "../../include/core/Systeme.h"

Systeme::Systeme(double cap){ 
	cap_max = cap;
 	//Initialise les 3 moteurs
	for (int i = 0; i < 3; ++i) 
	{	
	 	moteurs.push_back( new Moteur(i+1,MARCHE,*reservoirs[i], *(reservoirs[i]->GetPompe(0))));
	}
	//Crée les 3 réservoirs avec la configuration de base	
	reservoirs.push_back(new Reservoir(1, (2*cap/3), moteurs[0]));
 	reservoirs.push_back(new Reservoir(2, (1*cap/3), moteurs[1]));
 	reservoirs.push_back(new Reservoir(3, (2*cap/3), moteurs[2]));
 //Moteur(int n, etat_t Etat, Reservoir& Tank, Pompe& P);

	//Relier les pompes avec leur réservoirs et moteurss
	for (int i = 0; i < reservoirs.size() ; ++i) 
	{
	 	reservoirs[i]->GetPompe(0)->SetMoteur(*moteurs[i]);
	 	reservoirs[i]->GetPompe(0)->SetReservoir(*reservoirs[i]);
	}

	//Ajout des vannes toutes dans l'état fermé
	vannes.push_back(new Valve(FERME, "VT12"));
	vannes.push_back(new Valve(FERME, "VT23"));
	vannes.push_back(new Valve(FERME, "V12"));
	vannes.push_back(new Valve(FERME, "V13"));
	vannes.push_back(new Valve(FERME, "V23"));
}


Systeme::~Systeme(){
	for (int i = 0; i < reservoirs.size(); ++i)
	{
		delete reservoirs[i];
	}
	for (int i = 0; i < vannes.size(); ++i)
	{
		delete vannes[i];
	}
	for (int i = 0; i < moteurs.size(); ++i)
	{
		delete moteurs[i];
	}
	
}

void Systeme::AfficherEtat(){
	//Affiche l'état des réservoirs
	for (int i = 0; i  < reservoirs.size(); ++i)
	{
		reservoirs[i]->printInfos();
	}
	for (int i = 0; i < reservoirs.size();++i)
	{
		reservoirs[i]->GetPompe(0)->printInfos();
		reservoirs[i]->GetPompe(1)->printInfos();
	}
	for (int i = 0;  i < reservoirs.size(); ++i)
	{
		moteurs[i]->printInfos();
	}
	for (int i = 0; i < 5; ++i)
	{
		//Ajouter l'affichage des vannes 
	}
} 

