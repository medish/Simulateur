#include "../../include/states/Loginstate.h"


Loginstate::Loginstate(){
	init();
}

Loginstate::~Loginstate(){
	free();
}

void Loginstate::init(){
	//Accéde à la base de donnée
	int code  = sqlite3_open("../simulateur.db", &db);
    std::cout << code << std::endl;
    if(code){
		std::cout << "Erreur Sqlite3 :" << sqlite3_errmsg(db) << std::endl;
		std::cout << "Impossible d'acceder à la base de donnée, fermeture du programme" << std::endl;
		free();  
		exit(1);
	}
}	

void Loginstate::free(){
	sqlite3_close(db);
}

void Loginstate::update(){
	std::cout << "Updating Login state" << std::endl;
	
}

void Loginstate::display(){
	//Affiche son GUI
}

bool Loginstate::checkcred(){
	return true;
}
