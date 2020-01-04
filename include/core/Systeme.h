#ifndef H_SYSTEME
#define H_SYSTEME


#include "Pompe.h"
#include "Moteur.h"
#include "Valve.h"
#include "Reservoir.h"
#include "ValveRes.h"
#include "ValveMR.h"
#include "../utils/panne.h"

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
class panne;
 
class Systeme{
    friend class MainGui;
private:
	double cap_max;
	int duree; //Durée de la simulation en secondes
	vector<Moteur*> moteurs;
	vector<Reservoir*> reservoirs;
 	vector<Valve*> vannes;
 	
public:
	Systeme(double cap);
	Systeme(double cap, int dur , double consomation);
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
	//Injecter une panne dans le systeme
	friend void apply(Systeme &s);
};
#endif
