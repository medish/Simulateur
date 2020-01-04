#include "../../include/gui/MainGui.h"


MainGui::MainGui(Systeme * _sys){
    sys = _sys;

    init();

    //updateGuiThread();



    //timer.setInterval(150);
}

MainGui::~MainGui(){

}

void MainGui::init(){
    resize(1000,600);
    setLayout(&main_layout);


    // Time
    time.setHMS(0,0,0);
    time = time.addSecs(sys->duree);
    //timer.start(1000);

    middle_w = new QWidget();
    middle_w->setMinimumHeight(200);
    middle_w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   // middle_w->setStyleSheet("background-color:yellow;");

    // Reservoirs
    main_layout.addWidget(new TankWidget(this, sys->reservoirs[0]), 0, 0 , 1, 2);
    main_layout.addWidget(new TankWidget(this, sys->reservoirs[1]), 0, 3 , 1 , 2);
    main_layout.addWidget(new TankWidget(this, sys->reservoirs[2]), 0, 6 , 1, 2);

    // Pompes
    main_layout.addWidget(new PompeWidget(this, sys->reservoirs[0]->pompes[0]), 1, 0);
    main_layout.addWidget(new PompeWidget(this, sys->reservoirs[0]->pompes[1]), 1, 1);
    main_layout.addWidget(new PompeWidget(this, sys->reservoirs[1]->pompes[0]), 1, 3);
    main_layout.addWidget(new PompeWidget(this, sys->reservoirs[1]->pompes[1]), 1, 4);
    main_layout.addWidget(new PompeWidget(this, sys->reservoirs[2]->pompes[0]), 1, 6);
    main_layout.addWidget(new PompeWidget(this, sys->reservoirs[2]->pompes[1]), 1, 7);

    // Vannes reservoirs
    main_layout.addWidget(new VWidget(this, sys->vannes[0]), 0, 2);
    main_layout.addWidget(new VWidget(this, sys->vannes[1]), 0, 5);

    // Navigateur de droit
    main_layout.addWidget(new NavBarWidget(this), 0, 8 ,4, 1);

    // Vannes moteurs-pompes
    main_layout.addWidget(middle_w, 2, 0, 1, 8);
    main_layout.addWidget(new VWidget(this, sys->vannes[2]), 2, 2);
    main_layout.addWidget(new VWidget(this, sys->vannes[3]), 2, 3 , 1, 2, Qt::AlignCenter);
    main_layout.addWidget(new VWidget(this, sys->vannes[4]), 2, 5);
    // Moteurs
    main_layout.addWidget(new MoteurWidget(this, sys->moteurs[0]), 3, 0, 1, 2);
    main_layout.addWidget(new MoteurWidget(this, sys->moteurs[1]), 3, 3, 1, 2);
    main_layout.addWidget(new MoteurWidget(this, sys->moteurs[2]), 3, 6, 1, 2);

    // Stretch
    main_layout.setColumnStretch(0,1);
    main_layout.setColumnStretch(1,1);
    main_layout.setColumnStretch(3,1);
    main_layout.setColumnStretch(4,1);
    main_layout.setColumnStretch(6,1);
    main_layout.setColumnStretch(7,1);
    main_layout.setColumnStretch(8,2);

    // Connect signals
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(updateConsommation()));

}

void MainGui::updateGui(){
    int count = main_layout.count();
    for (int i =0;i<count;i++) {
        QWidget * w = main_layout.itemAt(i)->widget();
        if(MyQWidget * mw = dynamic_cast<MyQWidget*>(w))
            mw->showInfos();
    }
}

void MainGui::updateConsommation(){
    time = time.addSecs(-1);
    if(sys->cap_max >0){
        sys->updateconso();
        updateGui();
        return;
    }
    sys->updateconso();
    updateGui();
    timer.stop();
}
void MainGui::startSimulation(){
    timer.singleShot(QTime(0,0).secsTo(time), this, SLOT(stopSimulation()));
    timer.start(1000);
}

void MainGui::stopSimulation(){
    timer.setSingleShot(false);
    timer.stop();
    qDebug("stopped");
}
