#include "../../include/core/Moteur.h"
#include "../../include/core/Reservoir.h"
#include "../../include/core/Pompe.h"

 
//Initialise une pompe (avec un type un moteur un tank et un état )
//Dans le cas ou c'est une pompe de secours pas de moteur assigné etat arret et type secondaire
Pompe::Pompe(int nom, Reservoir &tank, Moteur& moteur, et etat, nb type){
	Num = nom;
	Alimente = &moteur;
	Appartient = &tank;	
	Etat = etat;
	Type = type;
}

Pompe::~Pompe(){
	delete Alimente;
	delete Appartient;
}

et Pompe::GetEtat(){
	return Etat;
}

Moteur* Pompe::GetMoteur(){
	return Alimente;
}

Reservoir* Pompe::GetReservoir(){ 
	return Appartient;
}

nb Pompe::GetType(){
	return Type;
}
int Pompe::GetNum(){
	return Num;
}
  
void Pompe::SetMoteur(Moteur& m){
	Alimente = &m;
} 
void Pompe::SetEtat(const et etat){
	Etat = etat;
}
void Pompe::SetReservoir(Reservoir& res){
	Appartient = &res;
}
void Pompe::SetType(const nb nb){
	Type = nb;
}  
