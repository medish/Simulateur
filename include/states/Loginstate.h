#ifndef H_LOGINSTATE
#define H_LOGINSTATE 

#include <sqlite3.h>
#include <iostream>
#include <cstring>
#include "State.h"

class State;

class Loginstate : public State {
private:
	sqlite3* db;
	//Informations récupérés depuis la base de donnée
	char* Login;
	char* Password;
	//
	
	//Ajouter le GUI
public:
	Loginstate();
	~Loginstate();
	void init();
	void free();
	void update();
	void display();

	bool checkcred();
};

#endif