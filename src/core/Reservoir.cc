#include <iostream>
#include "../../include/core/Reservoir.h"


//Construit un réservoir et ses deux pompes
Reservoir::Reservoir(int _num, double c){
	num= _num;
	capacity = c;
	etat = PLEIN;
	pompes.push_back(new Pompe(1,*this,MARCHE, PRIMAIRE));
	pompes.push_back(new Pompe(1,*this,ARRET, SECONDAIRE));
}

Reservoir::~Reservoir(){
	pompes.resize(0);
	moteurs.resize(0);
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

void Reservoir::vidange(){
	SetEtat(VIDANGE);
	for (int i = 0; i < 2; ++i)
	{	
		if((pompes[i]->GetEtat()) == MARCHE){
			pompes[i]->SetEtat(ARRET);
			pompes[i]->GetMoteur()->SetEtat(ARRET);
		}
	}
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