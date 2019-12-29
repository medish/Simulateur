#include "../../include/gui/MainGui.h"


MainGui::MainGui(Systeme * sys){
    std::vector<Reservoir*> tanks = sys->reservoirs;
    std::vector<Moteur*> moteurs = sys->moteurs;
    std::vector<Valve*> vannes = sys->vannes;
    init(tanks, moteurs, vannes);
}

MainGui::~MainGui(){

}

void MainGui::init(std::vector<Reservoir*> tanks, std::vector<Moteur*> moteurs, std::vector<Valve*> vannes){
    resize(1000,500);
    setLayout(&main_layout);

    middle_w = new QWidget();
    middle_w->setMinimumHeight(200);
    middle_w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   // middle_w->setStyleSheet("background-color:yellow;");

    // Reservoirs
    main_layout.addWidget(new TankWidget(tanks[0]), 0, 0 , 1, 2);
    main_layout.addWidget(new TankWidget(tanks[1]), 0, 3 , 1 , 2);
    main_layout.addWidget(new TankWidget(tanks[2]), 0, 6 , 1, 2);

    // Pompes
    main_layout.addWidget(new PompeWidget(tanks[0]->pompes[0]), 1, 0);
    main_layout.addWidget(new PompeWidget(tanks[0]->pompes[1]), 1, 1);
    main_layout.addWidget(new PompeWidget(tanks[1]->pompes[0]), 1, 3);
    main_layout.addWidget(new PompeWidget(tanks[1]->pompes[1]), 1, 4);
    main_layout.addWidget(new PompeWidget(tanks[2]->pompes[0]), 1, 6);
    main_layout.addWidget(new PompeWidget(tanks[2]->pompes[1]), 1, 7);

    // Vannes reservoirs
    main_layout.addWidget(new VWidget(vannes[0]), 0, 2);
    main_layout.addWidget(new VWidget(vannes[1]), 0, 5);

    // Navigateur de droit
    main_layout.addWidget(new NavBarWidget(), 0, 8 ,4, 1);

    // Vannes moteurs-pompes
    main_layout.addWidget(middle_w, 2, 0, 1, 8);
    main_layout.addWidget(new VWidget(vannes[2]), 2, 2);
    main_layout.addWidget(new VWidget(vannes[3]), 2, 3 , 1, 2, Qt::AlignCenter);
    main_layout.addWidget(new VWidget(vannes[4]), 2, 5);
    // Moteurs
    main_layout.addWidget(new MoteurWidget(moteurs[0]), 3, 0, 1, 2);
    main_layout.addWidget(new MoteurWidget(moteurs[1]), 3, 3, 1, 2);
    main_layout.addWidget(new MoteurWidget(moteurs[2]), 3, 6, 1, 2);

    // Stretch
    main_layout.setColumnStretch(0,1);
    main_layout.setColumnStretch(1,1);
    main_layout.setColumnStretch(3,1);
    main_layout.setColumnStretch(4,1);
    main_layout.setColumnStretch(6,1);
    main_layout.setColumnStretch(7,1);
    main_layout.setColumnStretch(8,2);

}

void MainGui::paintEvent(QPaintEvent* p){
   QPainter painter(this);
   QPoint one = main_layout.itemAtPosition(2,2)->widget()->pos();
   QPoint two = main_layout.itemAtPosition(2,3)->widget()->pos();
   std::cout<<one.x()<<std::endl;
   painter.drawLine(one, two);
}
