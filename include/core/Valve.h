#ifndef H_VALVE
#define H_VALVE

#include <vector>
#include <string>
#include "Reservoir.h"
#include "Moteur.h"
#include <iostream>

enum of{
	FERME = 0,
	OUVERT,
};

class Valve{
    friend class VWidget;
protected: 
	of etat;
	std::string nom;


public:
	Valve(of o, std::string nom);
	~Valve();
	
	std::string GetNom(){return nom;};
	of GetEtat(){return etat;};
	void ChangerEtat();
	virtual void printInfos();

};

#endif
