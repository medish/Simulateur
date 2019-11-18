#ifndef H_RESERVOIR
#define H_RESERVOIR
#pragma once

#include <vector>

#include "Pompe.h"
#include "Moteur.h"

class Pompe;
class Moteur;

enum tank_etat{
	VIDE = 0,
	PLEIN,
	VIDANGE,
	REMPLISSAGE
};

class Reservoir{
private:
	int num; //Le numéro du réservoir
	double capacity; //La capacité du réservoir
	tank_etat etat; //Vide ou plein
	std::vector<Pompe*> pompes; //Les deux pompes de chaque réservoir
	std::vector<Moteur*> moteurs;

public:

	Reservoir(int num, double c);
	~Reservoir();

	// Getters
	int GetNum(){return num;};
	double GetCapacity(){return capacity;};
	tank_etat GetEtat(){return etat;};
	Pompe* GetPompe(int i){return pompes[i];};
	std::vector<Pompe*> GetPompes(){return pompes;}
	std::vector<Moteur*> GetMoteurs(){return moteurs;};
	Pompe* GetDispoPompe();

	// Setters
	void SetCapacity(double c);
	void SetEtat(tank_etat etat);
	
	// Others methods
	friend void operator+(Reservoir& a, Reservoir& b);
	friend void consomme(Reservoir& r, Moteur& m);
	void vidange();
	bool estVide();
	void printInfos(); //Debugger

};


#endif