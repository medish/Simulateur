#ifndef H_VALVE
#define H_VALVE
#pragma once


#include <string>

enum of{
	FERME = 0,
	OUVERT,
};

class Valve{
private: 
	of etat;
	std::string nom;

public:
	Valve(of o, std::string nom);
	~Valve();
	
	std::string GetNom(){return nom;};
	of getEtat(){return etat;};
	void ChangerEtat();

};

#endif