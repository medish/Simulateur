#include "../../include/utils/panne.h"

panne::panne(int i, int duree){
    srand(time(NULL));
    id = i;
    piece = getNumberInRange(2);
     if(piece == 0){
           idobjet = 1 + getNumberInRange(3);
           parent = -1;
     }
     else{
           idobjet = 1 + getNumberInRange(2);
           parent = 1 + getNumberInRange(3);
     }
    note = 0;
    duree = getNumberInRange(duree);
    isdone = false;
}
panne::panne(int _id ,int _idp,int _p, int _ido,int _note, int _duree, int _passe) {
	id = _id;
	parent = _idp;
	note = _note;
	duree = _duree;
	idobjet = _ido;
	piece = _p;
	isdone = _passe;
}

panne::~panne(){

}


void panne::affiche() const {
    std::cout << id<< std::endl;
    std::cout << piece << std::endl;
    std::cout << idobjet << std::endl;
    std::cout << note << std::endl;
    std::cout << duree << std::endl;
    std::cout << isdone << std::endl;

}

void panne::apply(Systeme& s){
  if(piece == 0){ // Dans le cas d'une panne réservoir
    s.GetReservoirs()[idobjet-1]->SetEtat(VIDANGE);
    }
  if(piece == 1){ //Dans le cas d'une panne pompe
      if(parent != -1){
        s.GetReservoirs()[parent-1]->GetPompe(idobjet-1)->SetEtat(PANNE);
      }
    }
}

int panne::getNumberInRange(int max){
    return (rand()%max);
}
