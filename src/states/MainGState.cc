#include "../../include/core/Systeme.h"
#include "../../include/states/MainGState.h"


MainGState::MainGState(){
	init();
}

MainGState::~MainGState(){
	free();
}

void MainGState::init(){
	sys = new Systeme(400);

}

void MainGState::free(){
	delete sys;
}

void MainGState::update(){
	time_t starttime;
	time(&starttime);
	time_t endtime;

	std::cout << starttime << std::endl;

	sys->AfficherEtat();
	sys->updateconso();
	sys->AfficherEtat();

	time(&endtime);

	std::cout << starttime << std::endl;
	std::cout << "La simulation à duré "<< endtime - starttime << std::endl; 	

}