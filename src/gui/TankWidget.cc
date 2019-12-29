#include "../../include/gui/TankWidget.h"

TankWidget::TankWidget(){
    init();
}

TankWidget::TankWidget(Reservoir * r){
    init();
    showInfos(r->num, r->etat, r->capacity);



}

TankWidget::~TankWidget(){

}

void TankWidget::init(){
    //setStyleSheet("background-color:red; ");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMaximumHeight(130);
    setLayout(&tank_layout);

    label_name.setAlignment(Qt::AlignCenter);
    label_name.setStyleSheet("font-weight: bold; font-size:16px;");

    // Capacity progress bar
    progress_c.setValue(50);
    progress_c.setTextVisible(true);
    progress_c.setFormat("%p% (%v/%m)");

    // layout
    tank_layout.addWidget(&label_name);
    tank_layout.addWidget(&progress_c);
    tank_layout.addWidget(&label_etat);
}

void TankWidget::showInfos(int num_t, int num_etat, double cap){
    QString title = "Reservoir "+ QString::number(num_t);
    label_name.setText(title);
    QString etat = "Etat: "+ getEtatName(num_etat);
    label_etat.setText(etat);
     setEtatColor(num_etat);
    //progress_c.setValue();
    progress_c.setRange(0,(int)cap);

}


void TankWidget::setEtatColor(int e_color){
    switch (e_color) {
        case VIDE: {setStyleSheet("background-color:red; "); break;}
        case PLEIN: {setStyleSheet("background-color:green;"); break;}
        case VIDANGE: {setStyleSheet("background-color:blue;"); break;}
        case REMPLISSAGE: {setStyleSheet("background-color:orange;"); break;}
    }
}

QString TankWidget::getEtatName(int e_num){

    switch (e_num) {
        case VIDE: { return "VIDE";}
        case PLEIN: {return "PLEIN";}
        case VIDANGE: {return "VIDANGE";}
        case REMPLISSAGE: {return "REMPLISSAGE";}
        default: return "N/A";
    }
}
