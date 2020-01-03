#include "../../include/utils/panne.h"

panne::panne(){

}
panne::panne(int _id, int _note, int _duree, int _ido, int p) {
	id = _id;
	note = _note;
	duree = _duree;
	idobjet = _ido;
	piece = p;
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
