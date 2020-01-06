#include "../../include/gui/NavBarWidget.h"


NavBarWidget::NavBarWidget(MainGui * _mainGui){
    mainGui = _mainGui;
    init();
    showInfos();
}

NavBarWidget::~NavBarWidget(){
    delete mainGui;
}

void NavBarWidget::init(){
    setLayout(&v_layout);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setStyleSheet("background-color : purple");
    setMaximumWidth(300);
    setMinimumWidth(200);
    v_layout.setAlignment(Qt::AlignTop);

    btnStart.setText("Start");
    btnPause.setText("Pause");

    label_time.setDigitCount(8);
    label_time.setMinimumHeight(50);

    label_cap.setMinimumHeight(25);
    label_conso.setMinimumHeight(25);

    v_layout.addWidget(&label_time);
    f_layout.addRow("Capacité", &label_cap);
    f_layout.addRow("Consommation",&label_conso);

    v_layout.addLayout(&f_layout);
    v_layout.addWidget(&btnStart);
    v_layout.addWidget(&btnPause);

    QObject::connect(&btnPause, SIGNAL(clicked()), mainGui, SLOT(stopSimulation()));
    QObject::connect(&btnStart, SIGNAL(clicked()), mainGui, SLOT(startSimulation()));
}
void NavBarWidget::showInfos(){
    qDebug()<<mainGui->getTime();
    label_time.display(mainGui->getTime());
    label_cap.display(mainGui->getSysteme()->GetCapacity());
    label_conso.display(mainGui->getSysteme()->getConsoMot());
}
