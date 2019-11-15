#ifndef H_RESERVOIR
#define H_RESERVOIR

#include <vector>
#include <iostream>


#include "Pompe.h"
#include "Moteur.h"

using namespace std;

class Reservoir{
private:
	vector<Pompe*> p; //Les deux pompes de chaque réservoir
	double cap; //La capacité du réservoir
	int num; //Le numéro du réservoir
	Tanket et; //Vide ou plein

public:
	Reservoir(int num, double c);
	~Reservoir();
	Pompe* GetPompe(int i);
	vector<Pompe*> GetPompes(){return p;}
	Tanket GetEt();
	double GetCap();
	int GetNum();
	void SetEt(Tanket etat);
	bool estVide();
	void AfficherEtat(); //Debug

};


#endif