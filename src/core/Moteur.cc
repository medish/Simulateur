#include "../../include/core/Moteur.h"
#include "../../include/core/Reservoir.h"
#include "../../include/core/Pompe.h"

const double conso = 1.9;

Moteur::Moteur(et Etat, Reservoir& Tank, Pompe& P, int n){
	this->Etat = Etat;
	AlimPar = &Tank;
	Pom = &P;
	Numero = n;
} 

Moteur::~Moteur(){

}
et Moteur::GetEtat(){
	return Etat;
}
Pompe* Moteur::GetPompe(){
	return Pom;
}
Reservoir* Moteur::GetTank(){
	return AlimPar;
}
int Moteur::GetNumero(){
	return Numero;
}

void Moteur::SetPompe(Pompe& po){ 
	Pom = &po;
}
void Moteur::SetEtat(const et etat){
	Etat = etat;
}
void Moteur::SetReservoir(Reservoir& res){
	AlimPar = &res;
}
void Moteur::SetNumero(int nb){
	Numero = nb;
}
void Moteur::GetInfo(){
	cout << "Moteur: "<< GetNumero() << "/" << GetEtat() << "/" << GetTank() << "/" << GetPompe() << endl; 
}  