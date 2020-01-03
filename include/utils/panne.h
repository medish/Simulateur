#ifndef H_PANNE
#define H_PANNE

#include <iostream>

class panne{
private:
        int id;
        int piece;//0 pour le réservoir 1 pour la pompe
        int idobjet;
	int note;
	int duree;
	int isdone;


public:
	//Construit une panne aléatoire
	panne();
	//Construit une panne depuis le fichier de configuration
	panne(int _id, int _note, int _duree, int _ido, int p);
	~panne();
	void affiche() const;
};
#endif
