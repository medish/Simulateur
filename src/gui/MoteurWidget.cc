#include "../../include/gui/MoteurWidget.h"

MoteurWidget::MoteurWidget(){
    init();
}

MoteurWidget::MoteurWidget(Moteur & m ){
    init();
    showInfos(m.num,
              m.res_linked->GetNum(),
              m.pompe_linked->GetNum(),
              m.etat);
}

MoteurWidget::~MoteurWidget(){

}

void MoteurWidget::init(){
    setLayout(&m_layout);
    setStyleSheet("background-color: gray;");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMaximumHeight(120);

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
    QString etat = "Etat: "+ QString::number(num_etat);
    label_etat.setText(etat);
}
