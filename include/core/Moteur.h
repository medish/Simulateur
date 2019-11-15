#ifndef H_MOTEUR
#define H_MOTEUR


#include "Reservoir.h"
#include "Pompe.h"

class Moteur{
private:
	static const double conso;
	et Etat;
	Reservoir* AlimPar; //Nom du réservoir qui l'alimente
	Pompe* Pom; //Pompe qui lui envoie du carburant
	int  Numero; //Numero du moteur

public:
	Moteur(et Etat, Reservoir& Tank, Pompe& P, int n);
	~Moteur();
	//Getters
	et GetEtat();
	Pompe* GetPompe();
	Reservoir* GetTank();
	int GetNumero(); 
	//Setters
	void SetPompe(Pompe& po);
	void SetEtat(const et etat);
	void SetReservoir(Reservoir& res);
	void SetNumero(int nb);
 	//Affiche information
 	void GetInfo(); 
};



#endif