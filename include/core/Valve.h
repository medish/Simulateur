#ifndef H_VALVE
#define H_VALVE

#include <string>
#include <iostream>

using namespace std;
enum of{
	FERME = 0,
	OUVERT,
};

class Valve{
private: 
	of Ouverture;
	string Nom;

public:
	Valve(of o, string nom);
	~Valve();
	
	void ChangerEtat();
	string GetNom();

};

#endif