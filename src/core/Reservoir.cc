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

Pompe* Reservoir::GetDispoPompe(){
	for (int i = 0; i < 2; ++i)
	{
		if(pompes[i]->GetEtat() == ARRET)
			return pompes[i];
	}
	return NULL;
}

void Reservoir::SetEtat(tank_etat _etat){
	etat = _etat;
}

void Reservoir::SetCapacity(double c){
	capacity = c;
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

//Fonction amies
void operator+(Reservoir& a, Reservoir& b){
	double moyenne = 0;
	if(a.capacity > 0 || b.capacity > 0){
		moyenne = (a.capacity + b.capacity)/2;
		a.capacity  = (moyenne);
		b.capacity = (moyenne);
	}
	else{
		std::cout << "Transfert impossible entre " << a.GetNum() << "et " << b.GetNum() << std::endl;
	}
}