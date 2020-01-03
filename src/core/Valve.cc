
#include "../../include/core/Valve.h"

Valve::Valve(of _etat, std::string _nom){
	etat = _etat;
	nom = _nom;
}

Valve::~Valve(){

}
bool Valve::setEtat(of){
    std::cout<<"setEtat from Valve class"<<std::endl;
    return false;
}
	

void Valve::printInfos(){
	std::cout << GetNom()<<"/"<<GetEtat()<<"/";
}
  
