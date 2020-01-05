#include "../../include/gui/MenuGui.h"


MenuGui::MenuGui(MenuState* state): QWidget(){
    menu = state;
    this->setStyleSheet("background-color:white;");
    this->setWindowIcon(QIcon("../../assets/simulator.png"));
    this->setFixedSize(QSize(250, 500));
    this->setCursor(QCursor());
    mainlayout = new QVBoxLayout();
    newgame = new QPushButton();
    charger = new QPushButton();
    libre = new QPushButton();
    quit = new QPushButton();
    mainlayout->addWidget(newgame);
    mainlayout->addWidget(charger);
    mainlayout->addWidget(libre);
    mainlayout->addWidget(quit);

    //Connecter les signaux
    QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}


MenuGui::~MenuGui(){
  delete mainlayout;
  delete newgame;
  delete charger;
  delete libre;
  delete quit;
}
