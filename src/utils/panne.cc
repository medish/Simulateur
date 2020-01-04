#include "../../include/utils/panne.h"

panne::panne(int i){
    srand(time(NULL));
    id = i;
    piece = getNumberInRange(2);
    idobjet = getNumberInRange(3);
     if(piece == 0)
           parent = idobjet;
     else
            parent = getNumberInRange(3);
    note = 0;
    duree = getNumberInRange(180);
    isdone = false;
}
panne::panne(int _id ,int _idp,int _p, int _ido,int _note, int _duree) {
	id = _id;
	parent = _idp;
	note = _note;
	duree = _duree;
	idobjet = _ido;
	piece = _p;
	isdone = false;
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
    s.GetReservoirs()[idobjet]->SetEtat(VIDANGE);
     for(int i = 0; i < 2; i++){
      s.GetReservoirs()[idobjet]->GetPompe(i)->SetEtat(ARRET);
      }
    }
  if(piece == 1){ //Dans le cas d'une panne pompe
      if(parent != -1){
        s.GetReservoirs()[parent]->GetPompe(piece)->SetEtat(PANNE);
         s.GetReservoirs()[parent]->GetPompe(piece)->GetMoteur()->SetPompe(NULL);
          s.GetReservoirs()[parent]->GetPompe(piece)->SetMoteur(NULL);
      }
    }
}

int panne::getNumberInRange(int max){
    return (rand()%max);
}
