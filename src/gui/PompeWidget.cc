#include "../../include/gui/PompeWidget.h"

PompeWidget::PompeWidget(){

}

PompeWidget::PompeWidget(Pompe * p){
    init();
    if(p->mot_linked == nullptr)
        showInfos(p->num, p->etat, -1);
    else
        showInfos(p->num, p->etat, p->mot_linked->GetNumero());

}

PompeWidget::~PompeWidget(){

}

void PompeWidget::init(){
    setLayout(&p_layout);
    setMaximumHeight(70);
    setStyleSheet("background-color:green;");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QMenu *menu = new QMenu("Menu");
    QAction *printAct = new QAction("aaa");
    QAction *redoAct = new QAction("bbb");
    menu->addAction(printAct);
    menu->addAction(redoAct);
    qbtn.setText("Action");
    qbtn.setMenu(menu);
    qbtn.setPopupMode(QToolButton::InstantPopup);


    //qbtn.setMinimumSize(20,20);
    qbtn.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    label_name.setAlignment(Qt::AlignCenter);
    label_name.setStyleSheet("font-weight: bold; font-size:14px; background-color: rgba(0,0,0,0)");
    label_name.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    label_etat.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label_etat.setStyleSheet("background-color: rgba(0,0,0,0)");

    label_m.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label_m.setStyleSheet("background-color: rgba(0,0,0,0)");


    p_layout.addWidget(&label_name);
    p_layout.addWidget(&label_m);
    p_layout.addWidget(&label_etat);
    p_layout.addWidget(&qbtn);


}

void PompeWidget::showInfos(int num_p, int num_etat, int num_m){
    QString title = "Pompe "+ QString::number(num_p);
    label_name.setText(title);

    QString etat = "Etat: "+ getEtatName(num_etat);
    label_etat.setText(etat);

    QString moteur = "Moteur: "+ QString::number(num_m);
    label_m.setText(moteur);
    setEtatColor(num_etat);

}

void PompeWidget::setEtatColor(int e_color){
    switch (e_color) {
        case ARRET: {setStyleSheet("background-color:red;"); break;}
        case MARCHE: {setStyleSheet("background-color:green;"); break;}
        case PANNE: {setStyleSheet("background-color:orange;"); break;}
    }
}

QString PompeWidget::getEtatName(int e_num){

    switch (e_num) {
        case ARRET: { return "ARRET";}
        case MARCHE: {return "MARCHE";}
        case PANNE: {return "EN PANNE";}
        default: return "N/A";
    }
}
