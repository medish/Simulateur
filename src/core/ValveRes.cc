#include "../../include/core/ValveRes.h"

void ValveRes::transfer(){
	*reservoirs[0] + *reservoirs[1];
}

bool ValveRes::setEtat(const of _etat){
    etat = _etat;
    switch (_etat) {
    case FERME: {
        reservoirs[0]->SetEtat(PLEIN);
        reservoirs[1]->SetEtat(PLEIN);
        return true;
    }
    case OUVERT: {
        reservoirs[0]->SetEtat(REMPLISSAGE);
        reservoirs[1]->SetEtat(REMPLISSAGE);
        return true;
    }
    default: return true;
    }
}
