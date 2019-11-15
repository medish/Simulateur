#ifndef H_SYSTEME
#define H_SYSTEME

#include "Pompe.h"
#include "Moteur.h"
#include "Valve.h"
#include "Reservoir.h"

#include <vector>
#include <set>
#include <sstream>

using namespace std;

class Systeme{
private:
	double cap_max;

	vector<Moteur*> Moteurs;
	vector<Reservoir*> Tanks;
 	vector<Valve*> Vannes;
 	

public:
	Systeme(double cap);
	~Systeme();
	void AfficherEtat();

	//Getters
	vector<Moteur *> GetMoteurs();
	vector<Valve *> GetVannes();
	vector<Reservoir *> GetReservoirs();
	
	
		

};
#endif