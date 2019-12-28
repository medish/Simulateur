#include "../../include/gui/PompeWidget.h"

PompeWidget::PompeWidget(){

}

PompeWidget::PompeWidget(Pompe & p){
    init();
    showInfos(p.num, p.etat, p.mot_linked->GetNumero());
}

PompeWidget::~PompeWidget(){

}

void PompeWidget::init(){
    setLayout(&p_layout);
    setMaximumHeight(70);
    setStyleSheet("background-color:green;");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label_name.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label_etat.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label_m.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    p_layout.addWidget(&label_name);
    p_layout.addWidget(&label_m);
    p_layout.addWidget(&label_etat);

}

void PompeWidget::showInfos(int num_p, int num_etat, int num_m){
    QString title = "Pompe "+ QString::number(num_p);
    label_name.setText(title);

    QString etat = "Etat: "+ QString::number(num_etat);
    label_etat.setText(etat);

    QString moteur = "Moteur: "+ QString::number(num_m);
    label_m.setText(moteur);

}
