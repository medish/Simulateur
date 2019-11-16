#include "../../include/core/Systeme.h"

Systeme::Systeme(double cap){ 
	cap_max = cap;

	//Crée les 3 réservoirs avec la configuration de base	
	reservoirs.push_back(new Reservoir(1, (2*cap/3)));
 	reservoirs.push_back(new Reservoir(2, (cap/3)));
 	reservoirs.push_back(new Reservoir(3, (2*cap/3)));
 

 	//Initialise les 3 moteurs
	for (int i = 0; i < 3; ++i) 
	{	
	 	moteurs.push_back( new Moteur(i+1,MARCHE,*reservoirs[i]));
	}
	//Relier les pompes avec leur réservoirs et moteurss
	for (int i = 0; i < reservoirs.size() ; ++i) 
	{
	 	reservoirs[i]->GetPompe(0)->SetMoteur(*moteurs[i]);
	}

	for (int i = 0; i < 3; ++i)
	{
	   moteurs[i]->SetPompe(*(reservoirs[i]->GetPompe(0)));
	   reservoirs[i]->GetPompe(0)->SetMoteur(*moteurs[i]);
	}

	//Ajout des vannes toutes dans l'état fermé
	vannes.push_back(new Valve(FERME, "VT12"));
	vannes.push_back(new Valve(FERME, "VT23"));
	vannes.push_back(new Valve(FERME, "V12"));
	vannes.push_back(new Valve(FERME, "V13"));
	vannes.push_back(new Valve(FERME, "V23"));
}


Systeme::~Systeme(){
	reservoirs.resize(0);
	vannes.resize(0);
	moteurs.resize(0);
	
}

void Systeme::AfficherEtat(){
	
	for (int i = 0; i  < reservoirs.size(); ++i)
	{
		reservoirs[i]->printInfos();
	}
	for (int i = 0; i < reservoirs.size();++i)
	{
		reservoirs[i]->GetPompe(0)->printInfos();
		//reservoirs[i]->GetPompe(1)->printInfos();
	}
	for (int i = 0;  i < reservoirs.size(); ++i)
	{
		moteurs[i]->printInfos();
	}
	for (int i = 0; i < 5; ++i)
	{
		vannes[i]->printInfos();
		//vannes[i]->ChangerEtat();
		//vannes[i]->printInfos();
	}
} 

