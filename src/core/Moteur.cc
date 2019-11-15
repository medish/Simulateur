#include <iostream>
#include "../../include/core/Moteur.h"
#include "../../include/core/Reservoir.h"
#include "../../include/core/Pompe.h"

const double conso = 1.9;

Moteur::Moteur(int _num, etat_t _etat, Reservoir& res){

	etat = _etat;
	res_linked = &res;
	num = _num;
} 

Moteur::~Moteur(){
	delete res_linked;
	delete pompe_linked;
}

void Moteur::SetPompe(Pompe& p){ 
	pompe_linked = &p;
}
void Moteur::SetEtat(const etat_t _etat){
	etat = _etat;
}
void Moteur::SetReservoir(Reservoir& res){
	res_linked = &res;
}
void Moteur::printInfos(){
	std::cout << "Moteur: "<< GetNumero() << "/" << GetEtat() << "/" << GetReservoir()->GetNum() << "/" << GetPompe()->GetNum() << std::endl; 
}  