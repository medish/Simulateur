#include <iostream>
#include "../../include/core/Moteur.h"
#include "../../include/core/Reservoir.h"
#include "../../include/core/Pompe.h"

 
//Initialise une pompe (avec un type un moteur un tank et un état )
//Dans le cas ou c'est une pompe de secours pas de moteur assigné etat arret et type secondaire
Pompe::Pompe(int _num, Reservoir &res, Moteur * m, nb _type){
	num = _num;
	res_linked = &res;
    SetMoteur(m);
    type = _type;
}

Pompe::~Pompe(){
	delete res_linked;
	delete mot_linked;
}

  
void Pompe::SetMoteur(Moteur * m){
    if(m){
        if(m->GetEtat() == ARRET){
            mot_linked = m;
            SetEtat(MARCHE);
            m->SetPompe(this);
        }
    }else{
        mot_linked = nullptr;
        SetEtat(ARRET);
    }
} 
bool Pompe::SetEtat(const etat_t _etat){
    switch (_etat) {
    case ARRET:{
        if( etat == PANNE)
            return false;
        if(mot_linked != nullptr)
            mot_linked->SetEtat(ARRET);
        etat=_etat;
        return true;
    }
    case MARCHE:{

        if(etat != PANNE && res_linked->GetEtat() == PLEIN && mot_linked != nullptr){
            mot_linked->SetEtat(MARCHE);
            etat=_etat;
            return true;
        }
        SetEtat(ARRET);
        return false;
    }
    case PANNE:{
        if(mot_linked != nullptr)
            mot_linked->SetEtat(ARRET);
        etat=_etat;
        return true;
    }
    default: return false;
    }
}
void Pompe::SetReservoir(Reservoir * res){
    res_linked = res;
}
void Pompe::SetType(const nb _type){
	type = _type;
}  

void Pompe::switchPanne(){
	SetEtat(PANNE);
	std::cout<<"Pompe:"<<GetNum()<<"dans l'état"<<GetEtat()<<std::endl;
}

bool Pompe::switchOnOff(){
	if(etat != PANNE){
		etat = static_cast<etat_t>(1-etat);
		std::cout<<"Pompe:"<<GetNum()<<"dans l'état"<<GetEtat()<<std::endl;
		return true;
	}
	std::cout<<"Pompe:"<<GetNum()<<"dans l'état"<<GetEtat()<<std::endl;
	return false;
}

void Pompe::printInfos(){
	std::cout << "Pompe: "<< GetNum() << "/" << GetEtat() << "/" << GetType() << "/"<<GetReservoir()->GetNum()<<"/" << GetMoteur()->GetNumero() << std::endl; 
} 
