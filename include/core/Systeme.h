#ifndef H_SYSTEME
#define H_SYSTEME


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

	//Getters
	double GetCapacity(){return cap_max;};
	vector<Moteur *> GetMoteurs(){return moteurs;};
	vector<Valve *> GetVannes(){return vannes;};
	vector<Reservoir *> GetReservoirs(){return reservoirs;};
	//Setters
	void setCapacity(double c);
	
		
	//Operations
	void AfficherEtat();
	//Ajouter une mise à jour de la capacite max 
	void UpdateCapaciteMax();
	void updateconso();
};
#endif
