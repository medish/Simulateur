#ifndef H_STATEMANAGER
#define H_STATEMANAGER 

#include <stack>
#include <QObject>
#include "State.h"
class State;

class StateManager: public QObject{
    Q_OBJECT
private:
	std::stack<State*> SStack;
protected:
    bool status;
public:
	StateManager();
	~StateManager(); 
	
	//Getters 
	//Retoune le sommet de la pile
	State* GetCurrentState() { return ( !SStack.empty() ) ? SStack.top() : NULL; }
 	
	//Operations
	//Ajoute un nouvel état à la pile
	void PushState(State* state);
	//Lie un etat au gestionnaire d'etat
	void SetState(State* state );

	//Retire l'état courant du sommet de la pile
	void PopState();

};

#endif
