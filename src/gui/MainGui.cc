#include "../../include/gui/MainGui.h"

MainGui::MainGui() : QWidget(){
    setFixedSize(1000,600);

    // Reservoirs
    main_layout.addWidget(new TankWidget(), 0, 0);
    main_layout.addWidget(new TankWidget(), 0, 2);
    main_layout.addWidget(new TankWidget(), 0, 4);

    // Vannes reservoirs
    main_layout.addWidget(new QPushButton("Button"), 0, 1);
    main_layout.addWidget(new QPushButton("Button"), 0, 3);
    // Navigateur de droit
    main_layout.addWidget(new TankWidget(), 0, 5 , 3 , 3); //aa

    // Vannes moteurs - reservoirs
    main_layout.addWidget(new QPushButton("Button"), 1, 1);
    main_layout.addWidget(new QPushButton("Button"), 1, 2);
    main_layout.addWidget(new QPushButton("Button"), 1, 3);
    // Moteurs
    main_layout.addWidget(new TankWidget(), 2, 0);
    main_layout.addWidget(new TankWidget(), 2, 2);
    main_layout.addWidget(new TankWidget(), 2, 4);

    setLayout(&main_layout);

}

MainGui::~MainGui(){

}

