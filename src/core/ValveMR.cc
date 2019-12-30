#include "../../include/core/ValveMR.h"

bool ValveMr::alimente(Moteur& m,  Reservoir& r){
	Pompe* tmp;	
	if(m.GetReservoir() != &r){ 
		tmp =  r.GetDispoPompe();
		if(tmp){
			m.SetReservoir(r);
			m.SetPompe(*(tmp));
			return true;
		}
	}
	return false;
}


bool ValveMr::setEtat(const of _etat){

    // Verifier si Moteur est en ARRET , et S'il existe au moins une pompe en ARRET
    if((moteurs[0]->GetEtat() == ARRET
            && (reservoirs[1]->GetPompe(0)->GetEtat()== ARRET
                || reservoirs[1]->GetPompe(1)->GetEtat() == ARRET)
        )
       || (moteurs[1]->GetEtat() == ARRET
           && (reservoirs[0]->GetPompe(0)->GetEtat()== ARRET
               || reservoirs[0]->GetPompe(1)->GetEtat() == ARRET)
           )
       )
    {
        return true;
        etat = _etat;
    }
    return false;
}
/*
void ValveMr::printInfos(){
	Valve::printInfos();
	std::cout << reservoirs[0] << "/" << reservoirs[1] << "/" << moteurs[0] << "/" << moteurs[1] << std::endl;
} 
*/
