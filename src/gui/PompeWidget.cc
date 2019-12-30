#include "../../include/gui/PompeWidget.h"


PompeWidget::PompeWidget(Pompe * _p){
    p = _p;
    init();
    if(_p->mot_linked == nullptr)
        showInfos(_p->num, _p->etat, 0);
    else
        showInfos(_p->num, _p->etat, _p->mot_linked->GetNumero());

}

PompeWidget::~PompeWidget(){

}

void PompeWidget::init(){
    setLayout(&p_layout);
    setMaximumHeight(80);
    setMinimumSize(140,80);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    combo_m.addItem("N/A");
    combo_m.addItem("1", QVariant(1));
    combo_m.addItem("2", QVariant(2));
    combo_m.addItem("3", QVariant(3));



    combo_etat.addItem("ARRET");
    combo_etat.addItem("MARCHE");
    combo_etat.addItem("PANNE");

    label_name.setAlignment(Qt::AlignCenter);
    label_name.setStyleSheet("font-weight: bold; font-size:14px; background-color: rgba(0,0,0,0)");
    label_name.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    // Form layout
    f_layout.addRow("Moteur", &combo_m);
    f_layout.addRow("Etat", &combo_etat);

    p_layout.addWidget(&label_name);
    p_layout.addLayout(&f_layout);


}

void PompeWidget::showInfos(int num_p, int num_etat, int num_m){
    QString title = "Pompe "+ QString::number(num_p);
    label_name.setText(title);

    combo_m.setCurrentIndex(num_m);
    //qDebug()<<"Moteur-"<<num_m<<" Pompe-"<<num_etat;
    combo_etat.setCurrentIndex(num_etat);

    setEtatColor(num_etat);

}

void PompeWidget::setEtatColor(int e_color){
    switch (e_color) {
        case ARRET: {setStyleSheet("background-color:red;"); break;}
        case MARCHE: {setStyleSheet("background-color:green;"); break;}
        case PANNE: {setStyleSheet("background-color:orange;"); break;}
    }
}

