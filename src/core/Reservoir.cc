#include "../../include/core/Reservoir.h"


//Construit un réservoir et ses deux pompes
Reservoir::Reservoir(int num, double c){
	this->num= num;
	p.push_back(new Pompe(1,num,this, MARCHE, PRIMAIRE));
	p.push_back(new Pompe(1,num,this, ARRET, SECONDAIRE));
	cap = c;
	et = PLEIN;
}

Reservoir::~Reservoir(){
	for (int i = 0; i < p.size(); ++i)
	{
		delete p[i];
	}
}

Tanket Reservoir::GetEt(){
	return et;
	
}
double Reservoir::GetCap(){
	return cap;
}

void Reservoir::SetEt(Tanket etat){
	et = etat;
}

int Reservoir::GetNum(){
	return num;
}
 
Pompe* Reservoir::GetPompe(int i){
	if(i >= 0 && i < 2)
		return p[i];
	else
		return p[2];
}

bool Reservoir::estVide(){
	if(cap){
		std::cout << "Le Reservoir " << GetNum() << " est encore plein : " << GetCap() << "L" << std::endl;
		return false;
	} else{
		SetEt(VIDE);
		std::cout << "Le Reservoir " << GetNum() << " est vide" << std::endl;
		return true;
	}
}

void Reservoir::AfficherEtat(){
	estVide();
}