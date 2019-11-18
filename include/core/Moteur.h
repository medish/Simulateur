
#ifndef H_MOTEUR
#define H_MOTEUR
#pragma once


#include "Reservoir.h"
#include "Pompe.h"


class Pompe;
class Reservoir;

class Moteur{
private:
	int  num; //Numero du moteur
	etat_t etat;
	Reservoir* res_linked; //Nom du réservoir qui l'alimente
	Pompe* pompe_linked; //Pompe qui lui envoie du carburant
	static const double consomation;

public:
	Moteur(int n, etat_t etat, Reservoir& r);
	~Moteur();
	//Getters
	int GetNumero(){return num;}; 
	etat_t GetEtat(){return etat;};
	Pompe* GetPompe(){return pompe_linked;};
	Reservoir* GetReservoir(){return res_linked;};
	//Setters
	void SetEtat(const etat_t etat);
	void SetPompe(Pompe& po);
	void SetReservoir(Reservoir& res);
	friend void consomme( Reservoir& r, Moteur& m);
	//Affiche information
 	void printInfos(); 
};

 
#endif