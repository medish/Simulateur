#ifndef H_MOTEUR
#define H_MOTEUR


#include "Reservoir.h"
#include "Pompe.h"


class Pompe;
class Reservoir;

class Moteur{
    friend class MoteurWidget;
private:
	int  num; //Numero du moteur
	etat_t etat;
	Reservoir* res_linked; //Nom du réservoir qui l'alimente
	Pompe* pompe_linked; //Pompe qui lui envoie du carburant
	static const double consomation;

public:
    Moteur(int n);
	~Moteur();
	//Getters
	int GetNumero(){return num;}; 
	etat_t GetEtat(){return etat;};
	Pompe* GetPompe(){return pompe_linked;};
	Reservoir* GetReservoir(){return res_linked;};
	//Setters
    bool SetEtat(etat_t etat);
    void SetPompe(Pompe * po);
    void SetReservoir(Reservoir * res);
    void consomme( Reservoir& r);
	//Affiche information
 	void printInfos(); 
};

 
#endif
