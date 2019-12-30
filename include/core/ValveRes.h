#ifndef H_VALVERES
#define H_VALVERES

#include "Valve.h"


class Reservoir;

class ValveRes : public Valve{
private:
	std::vector<Reservoir*> reservoirs; //taille 2
public:
	ValveRes(std::string _nom,of _etat, std::vector<Reservoir*> r):Valve(_etat,_nom){reservoirs =r;};
	~ValveRes(){reservoirs.resize(0);};
	void transfer();
	void printInfos(){
		Valve::printInfos();
		std::cout << reservoirs[0]->GetNum() << "/" << reservoirs[1]->GetNum() << std::endl;
	}
    bool setEtat(const of);

};



#endif

