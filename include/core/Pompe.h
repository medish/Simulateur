#ifndef H_POMPE
#define H_POMPE

#include <iostream>

#include "Moteur.h"
#include "Reservoir.h"

using namespace std;

enum et{
	ARRET = 0,
	MARCHE,
	PANNE
};

enum nb{
	PRIMAIRE = 1,
	SECONDAIRE
};

enum Tanket{
	VIDE = 0,
	PLEIN,
	VIDANGE,
	REMPLISSAGE
};

class Pompe{

private:
	int Num;
	nb Type;
	et Etat;
	Moteur* Alimente; //Le moteur qu'elle alimente
	Reservoir* Appartient; //Le reservoir auquel elle appartient 

public:
 
	//Constructeur
	Pompe(int nom,Reservoir &tank, Moteur &moteur, et et, nb nb);
	~Pompe();
	//Getters
	et GetEtat();
	Moteur* GetMoteur();
	Reservoir* GetReservoir();
	nb GetType();
	int GetNum();
	//Setters
	void SetMoteur(Moteur & m);
	void SetEtat(const et etat);
	void SetReservoir(Reservoir& res);
	void SetType(const nb nb);

};


#endif