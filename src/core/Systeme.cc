#include "../../include/core/Systeme.h"

Systeme::Systeme(double cap){ 
	cap_max = cap;
	//Crée les 3 réservoirs avec la configuration de base	
	Tanks.push_back(new Reservoir(1, (2*cap/3)));
 	Tanks.push_back(new Reservoir(2, (1*cap/3)));
 	Tanks.push_back(new Reservoir(3, (2*cap/3)));
 	//Initialise les 3 moteurs
	for (int i = 0; i < Tanks.size(); ++i) 
	{	std::stringstream ss;
		ss << i+1;
	 	Moteurs.push_back( new Moteur(MARCHE,Tanks[i]->GetNum(), Tanks[i]->GetPompe(0)->GetNom(),ss.str()));
	}


	//Relier les pompes avec leur réservoirs et moteurss
	for (int i = 0; i < Tanks.size() ; ++i) 
	{
	 	Tanks[i]->GetPompe(0)->SetMoteur(Moteurs[i]->GetNumero());
	 	Tanks[i]->GetPompe(0)->SetTank(Tanks[i]->GetNum());
	}

	//Ajout des vannes toutes dans l'état fermé
	Vannes.push_back(new Valve(FERME, "VT12"));
	Vannes.push_back(new Valve(FERME, "VT23"));
	Vannes.push_back(new Valve(FERME, "V12"));
	Vannes.push_back(new Valve(FERME, "V13"));
	Vannes.push_back(new Valve(FERME, "V23"));
}


Systeme::~Systeme(){
	for (int i = 0; i < Tanks.size(); ++i)
	{
		delete Tanks[i];
	}
	for (int i = 0; i < Vannes.size(); ++i)
	{
		delete Vannes[i];
	}
	for (int i = 0; i < Moteurs.size(); ++i)
	{
		delete Moteurs[i];
	}
	
}

void Systeme::AfficherEtat(){
	//Affiche l'état des réservoirs
	for (int i = 0; i  < Tanks.size(); ++i)
	{
		Tanks[i]->AfficherEtat();
	}
	for (int i = 0; i < Tanks.size();++i)
	{
		Tanks[i]->GetPompe(0)->AfficherEtat();
		Tanks[i]->GetPompe(1)->AfficherEtat();
	}
	for (int i = 0;  i < Tanks.size(); ++i)
	{
		Moteurs[i]->GetInfo();
	}
	for (int i = 0; i < 5; ++i)
	{
		//Ajouter l'affichage des vannes 
	}
} 

vector<Moteur *> Systeme::GetMoteurs(){
	return Moteurs;
}

vector<Reservoir *> Systeme::GetReservoirs(){
	return Tanks;
}

vector<Valve *> Systeme::GetVannes(){
	return Vannes;
}
