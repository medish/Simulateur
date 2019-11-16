#ifndef H_SYSTEME
#define H_SYSTEME
#pragma once


#include "Pompe.h"
#include "Moteur.h"
#include "Valve.h"
#include "Reservoir.h"
#include "ValveRes.h"
#include "ValveMR.h"

#include <vector>
#include <set>
#include <sstream>

using namespace std;

class Pompe;
class Moteur;
class Valve;
class Reservoir;
class ValveMr;
class ValveRes;
 
class Systeme{
private:
	double cap_max;

	vector<Moteur*> moteurs;
	vector<Reservoir*> reservoirs;
 	vector<Valve*> vannes;
 	

public:
	Systeme(double cap);
	~Systeme();
	void AfficherEtat();

	//Getters
	double GetCapacity(){return cap_max;};
	vector<Moteur *> GetMoteurs(){return moteurs;};
	vector<Valve *> GetVannes(){return vannes;};
	vector<Reservoir *> GetReservoirs(){return reservoirs;};
	
	//Setters
	void setCapacity(double c);
	
		

};
#endif