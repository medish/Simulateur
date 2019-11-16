
#include "../../include/core/Valve.h"

Valve::Valve(of _etat, std::string _nom){
	etat = _etat;
	nom = _nom;
}
Valve::~Valve(){

}
	

void Valve::ChangerEtat(){
	etat = static_cast<of>(1-etat);
}

void Valve::printInfos(){
	std::cout << GetNom()<<"/"<<GetEtat()<<"/";
}
  
