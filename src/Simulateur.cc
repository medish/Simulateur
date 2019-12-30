#include <QApplication>

#include "../include/core/Systeme.h"
#include "../include/states/State.h"
#include "../include/states/StateManager.h"
#include "../include/states/MainGState.h"
#include "../include/states/Loginstate.h"

int main(int argc, char  *argv[]){	

    QApplication app(argc, argv);
    StateManager sm;
    Loginstate* ls = new Loginstate();
    std::cout << "Before Push" << ls << std::endl;
    sm.PushState(ls);
    sm.GetCurrentState()->update();

    return app.exec();
}
