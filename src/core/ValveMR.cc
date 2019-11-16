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
/*
void ValveMr::printInfos(){
	Valve::printInfos();
	std::cout << reservoirs[0] << "/" << reservoirs[1] << "/" << moteurs[0] << "/" << moteurs[1] << std::endl;
} 
*/