#include "../../include/gui/MenuGui.h"


MenuGui::MenuGui(MenuState* state): QWidget(){
    menu = state;
    this->setStyleSheet("background-color:white;");
    this->setWindowIcon(QIcon("../../assets/simulator.png"));
    this->setFixedSize(QSize(500, 250));
    this->setCursor(QCursor());
    mainlayout = new QVBoxLayout();
    setLayout(mainlayout);
    newgame = new QPushButton("Nouvelle Simulation");
    charger = new QPushButton("Charger Simulation");
    libre = new QPushButton("Simulation Libre");
    quit = new QPushButton("Quitter");
    mainlayout->addWidget(newgame);
    mainlayout->addWidget(charger);
    mainlayout->addWidget(libre);
    mainlayout->addWidget(quit);

    //Connecter les signaux
    QObject::connect(newgame, SIGNAL(clicked()), this, SLOT(GenerateFromFile()));
    QObject::connect(charger, SIGNAL(clicked()), this, SLOT(GenerateFromFile()));
  //  QObject::connect(quit, SIGNAL(clicked()), this, SLOT(quit()));
    QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}


MenuGui::~MenuGui(){
  delete mainlayout;
  delete newgame;
  delete charger;
  delete libre;
  delete quit;
}

void MenuGui::GenerateFromFile(){
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Choisir fichier de configuration"), "../../assets/pannes",
            tr("XML file (*.xml);;All Files (*)"));

      if(fileName.toStdString().substr(fileName.toStdString().find_last_of(".") + 1) == "xml") {
                    MainGState * ms = new MainGState(fileName);
                    menu->GetManager()->PopState();
                    menu->GetManager()->PushState(ms);
                    menu->GetManager()->GetCurrentState()->update();
      } else {
               QMessageBox::warning(this, "Erreur fichier", "Le fichier séléctionné ne correspond pas ");
      }
}

void MenuGui::GenerateRandom(){

}
