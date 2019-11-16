#ifndef H_VALVEMR
#define H_VALVEMR
#pragma once

#include "Valve.h"

class Reservoir;
class Moteur;

class ValveMr : public Valve{
private:
	std::vector<Reservoir*> reservoirs;
	std::vector<Moteur*> moteurs;

public:
	ValveMr(std::string _nom,of _etat, std::vector<Reservoir*> r, std::vector<Moteur*> m):
			Valve(_etat,_nom){reservoirs =r; moteurs = m;};
	~ValveMr(){reservoirs.resize(0); moteurs.resize(0);};
	bool alimente(Moteur& m,  Reservoir& r);
	void printInfos(){
		Valve::printInfos();
		std::cout << reservoirs[0]->GetNum() << "/" << reservoirs[1]->GetNum() << "/" << moteurs[0]->GetNumero() << "/" << moteurs[1]->GetNumero() << std::endl;
	} 
};



#endif

