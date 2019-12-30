#include "../../include/gui/MoteurWidget.h"



MoteurWidget::MoteurWidget(Moteur * _m ){
    m = _m;
    init();
    showInfos(_m->num,
              _m->res_linked->GetNum(),
              _m->pompe_linked->GetNum(),
              _m->etat);
}

MoteurWidget::~MoteurWidget(){

}

void MoteurWidget::init(){
    setLayout(&m_layout);
    setStyleSheet("background-color: gray;");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMaximumHeight(100);
    setMinimumHeight(100);


    label_name.setAlignment(Qt::AlignCenter);
    label_name.setStyleSheet("font-weight: bold; font-size:16px; background-color: rgba(0,0,0,0)");

    combo_t_p.addItem("N/A");
    combo_t_p.addItem("Reservoir 1 Pompe 1", QVariant(QPoint(1,1)));
    combo_t_p.addItem("Reservoir 1 Pompe 2", QVariant(QPoint(1,2)));
    combo_t_p.addItem("Reservoir 2 Pompe 1", QVariant(QPoint(2,1)));
    combo_t_p.addItem("Reservoir 2 Pompe 2", QVariant(QPoint(2,2)));
    combo_t_p.addItem("Reservoir 3 Pompe 1", QVariant(QPoint(3,1)));
    combo_t_p.addItem("Reservoir 3 Pompe 2", QVariant(QPoint(3,2)));

    combo_etat.addItem("ARRET", QVariant(0));
    combo_etat.addItem("MARCHE", QVariant(1));

    //Form layout
    f_layout.addRow("", &combo_t_p);
    f_layout.addRow("Etat", &combo_etat);

    m_layout.addWidget(&label_name);
    m_layout.addLayout(&f_layout);

}
void MoteurWidget::showInfos(int num_m, int num_r, int num_p, int num_etat ){
    QString title = "Moteur"+ QString::number(num_m);
    label_name.setText(title);
    QString curr_t_p = "Reservoir "+ QString::number(num_r)+" Pompe "+ QString::number(num_p);
    combo_t_p.setCurrentText(curr_t_p);
    combo_etat.setCurrentIndex(num_etat);

    setEtatColor(num_etat);
}

void MoteurWidget::setEtatColor(int e_color){
    switch (e_color) {
        case ARRET: {setStyleSheet("background-color:red;"); break;}
        case MARCHE: {setStyleSheet("background-color:green;"); break;}
        case PANNE: {setStyleSheet("background-color:orange;"); break;}
    }
}

