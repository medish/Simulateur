#include "../../include/gui/MoteurWidget.h"



MoteurWidget::MoteurWidget(Moteur * m ){
    init();
    showInfos(m->num,
              m->res_linked->GetNum(),
              m->pompe_linked->GetNum(),
              m->etat);
}

MoteurWidget::~MoteurWidget(){

}

void MoteurWidget::init(){
    setLayout(&m_layout);
    setStyleSheet("background-color: gray;");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMaximumHeight(120);


    label_name.setAlignment(Qt::AlignCenter);
    label_name.setStyleSheet("font-weight: bold; font-size:16px; background-color: rgba(0,0,0,0)");
    label_tank.setStyleSheet("background-color: rgba(0,0,0,0)");
    label_pompe.setStyleSheet("background-color: rgba(0,0,0,0)");
    label_etat.setStyleSheet("background-color: rgba(0,0,0,0)");


    m_layout.addWidget(&label_name);
    m_layout.addWidget(&label_tank);
    m_layout.addWidget(&label_pompe);
    m_layout.addWidget(&label_etat);

}
void MoteurWidget::showInfos(int num_m, int num_r, int num_p, int num_etat ){
    QString title = "Moteur"+ QString::number(num_m);
    label_name.setText(title);
    QString res = "Reservoir: "+ QString::number(num_r);
    label_tank.setText(res);
    QString pompe = "Pompe: "+ QString::number(num_p);
    label_pompe.setText(pompe);
    QString etat = "Etat: "+ getEtatName(num_etat);
    label_etat.setText(etat);

    setEtatColor(num_etat);
}

void MoteurWidget::setEtatColor(int e_color){
    switch (e_color) {
        case ARRET: {setStyleSheet("background-color:red;"); break;}
        case MARCHE: {setStyleSheet("background-color:green;"); break;}
        case PANNE: {setStyleSheet("background-color:orange;"); break;}
    }
}

QString MoteurWidget::getEtatName(int e_num){

    switch (e_num) {
        case ARRET: { return "ARRET";}
        case MARCHE: {return "MARCHE";}
        case PANNE: {return "EN PANNE";}
        default: return "N/A";
    }
}
