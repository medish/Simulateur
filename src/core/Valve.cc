#include "../../include/core/Valve.h"

Valve::Valve(of o, string nom){
	Ouverture = o;
	Nom = nom;
}
Valve::~Valve(){

}
	

string Valve::GetNom(){
	return Nom;
}

void Valve::ChangerEtat(){
	if(of){
		of = FERME;
	}else{
		
	}
}