#include <iostream>
#include "../../include/core/Reservoir.h"


//Construit un réservoir et ses deux pompes
Reservoir::Reservoir(int _num, double c, Moteur * m){
	num= _num;
	capacity = c;
	etat = PLEIN;
	moteurs.push_back(m);
	pompes.push_back(new Pompe(1,*this,m, MARCHE, PRIMAIRE));
	pompes.push_back(new Pompe(1,*this,NULL, ARRET, SECONDAIRE));
}
//Pompe(int nom,Reservoir &tank, Moteur &moteur, etat_t et, nb nb);
Reservoir::~Reservoir(){
	for (int i = 0; i < pompes.size(); ++i)
	{
		delete pompes[i];
	}
}

/* 
Pompe* Reservoir::GetPompe(int i){
	if(i >= 0 && i < 2)
		return pompes[i];
	else
		return pompes[2];
}*/

void Reservoir::SetEtat(tank_etat _etat){
	etat = _etat;
}


bool Reservoir::estVide(){
	if(capacity){
		std::cout << "Le Reservoir " << GetNum() << " est encore plein : " << GetCapacity() << "L" << std::endl;
		return false;
	} else{
		this->SetEtat(VIDE);
		std::cout << "Le Reservoir " << GetNum() << " est vide" << std::endl;
		return true;
	}
}

void Reservoir::printInfos(){
	estVide();
}