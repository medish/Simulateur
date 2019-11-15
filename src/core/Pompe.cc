#include <iostream>
#include "../../include/core/Moteur.h"
#include "../../include/core/Reservoir.h"
#include "../../include/core/Pompe.h"

 
//Initialise une pompe (avec un type un moteur un tank et un état )
//Dans le cas ou c'est une pompe de secours pas de moteur assigné etat arret et type secondaire
Pompe::Pompe(int _num, Reservoir &res, etat_t _etat, nb _type){
	num = _num;
	res_linked = &res;
	etat = _etat;
	type = _type;
}

Pompe::~Pompe(){
	delete res_linked;
	delete mot_linked;
}

  
void Pompe::SetMoteur(Moteur& m){
	mot_linked = &m;
} 
void Pompe::SetEtat(const etat_t _etat){
	etat = _etat;
}
void Pompe::SetReservoir(Reservoir& res){
	res_linked = &res;
}
void Pompe::SetType(const nb _type){
	type = _type;
}  
void Pompe::printInfos(){
	std::cout << "Pompe: "<< GetNum() << "/" << GetEtat() << "/" << GetType() << "/"<<GetReservoir()->GetNum()<<"/" << GetMoteur()->GetNumero() << std::endl; 
} 