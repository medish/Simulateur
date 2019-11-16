#ifndef H_VALVE
#define H_VALVE
#pragma once

#include <vector>
#include <string>
#include "Reservoir.h"
#include "Moteur.h"

enum of{
	FERME = 0,
	OUVERT,
};

class Valve{
protected: 
	of etat;
	std::string nom;


public:
	Valve(of o, std::string nom);
	~Valve();
	
	std::string GetNom(){return nom;};
	of GetEtat(){return etat;};
	void ChangerEtat();
	void printInfos();

};

#endif