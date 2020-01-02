#include <iostream>

#include "../../include/core/Moteur.h"
#include "../../include/core/Reservoir.h"
#include "../../include/core/Pompe.h"

const double consomation = 1.6;

Moteur::Moteur(int _num){
    num = _num;
    etat = ARRET;
    res_linked = nullptr;
} 

Moteur::~Moteur(){
	delete res_linked;
	delete pompe_linked;
}

void Moteur::SetPompe(Pompe * p){
//    if(pompe_linked)
//        if(pompe_linked != p)
//            pompe_linked->SetMoteur(nullptr);
    pompe_linked = p;
    res_linked = p ->GetReservoir();
}
bool Moteur::SetEtat(etat_t _etat){
    if(pompe_linked){
        etat = _etat;
        return true;
    }
    etat = ARRET;
    return false;
}
void Moteur::SetReservoir(Reservoir * res){
    res_linked = res;
}
void Moteur::printInfos(){
	std::cout << "Moteur: "<< GetNumero() << "/" << GetEtat() << "/" << GetReservoir()->GetNum() << "/" << GetPompe()->GetNum() << std::endl; 
}  

void consomme(Reservoir& r, Moteur& m){
		if(r.GetCapacity() > 0 ){
			//std::cout << "Debug " << consomation << std::endl;
			double nvcap = r.GetCapacity() - consomation;
			r.SetCapacity(nvcap);	
		}
		else{
			r.SetCapacity(0.0);
		}
}   
