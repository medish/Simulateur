#include "../../include/gui/MainGui.h"

MainGui::MainGui() : QWidget(){
    //setFixedSize(1000,600);
    //showMaximized();
    resize(1000,500);
    middle_w = new QWidget();
    middle_w->setMinimumHeight(200);
    middle_w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    middle_w->setStyleSheet("background-color:yellow;");

    // Reservoirs
    main_layout.addWidget(new TankWidget(), 0, 0 , 1, 2);
    main_layout.addWidget(new TankWidget(), 0, 3 , 1 , 2);
    main_layout.addWidget(new TankWidget(), 0, 6 , 1, 2);

    // Pompes
    main_layout.addWidget(new PompeWidget(), 1, 0);
    main_layout.addWidget(new PompeWidget(), 1, 1);
    main_layout.addWidget(new PompeWidget(), 1, 3);
    main_layout.addWidget(new PompeWidget(), 1, 4);
    main_layout.addWidget(new PompeWidget(), 1, 6);
    main_layout.addWidget(new PompeWidget(), 1, 7);

    // Vannes reservoirs
    main_layout.addWidget(new VWidget(), 0, 2);
    main_layout.addWidget(new VWidget(), 0, 5);

    // Navigateur de droit
    main_layout.addWidget(new NavBarWidget(), 0, 8 ,4, 1);

    // Vannes moteurs-pompes
    main_layout.addWidget(middle_w, 2, 0, 1, 8);
    main_layout.addWidget(new VWidget(), 2, 2);
    main_layout.addWidget(new VWidget(), 2, 3 , 1, 2, Qt::AlignCenter);
    main_layout.addWidget(new VWidget(), 2, 5);
    // Moteurs
    main_layout.addWidget(new MoteurWidget(), 3, 0, 1, 2);
    main_layout.addWidget(new MoteurWidget(), 3, 3, 1, 2);
    main_layout.addWidget(new MoteurWidget(), 3, 6, 1, 2);

    // Stretch
    main_layout.setColumnStretch(0,1);
    main_layout.setColumnStretch(1,1);
    main_layout.setColumnStretch(3,1);
    main_layout.setColumnStretch(4,1);
    main_layout.setColumnStretch(6,1);
    main_layout.setColumnStretch(7,1);
    main_layout.setColumnStretch(8,2);


    setLayout(&main_layout);


}

MainGui::~MainGui(){

}


void MainGui::paintEvent(QPaintEvent* p){
   /* QPainter painter(this);
   painter.drawLine(30, 40, 80, 90);
   painter.drawLine(QPoint(80, 100), QPoint(200, 300));*/
}
