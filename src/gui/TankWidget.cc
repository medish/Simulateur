#include "../../include/gui/TankWidget.h"

TankWidget::TankWidget(){
    init();
}

TankWidget::TankWidget(Reservoir & r){
    init();
    showInfos(r.num, r.etat, r.capacity);



}

TankWidget::~TankWidget(){

}

void TankWidget::init(){
    setStyleSheet("background-color:red;");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMaximumHeight(130);
    setLayout(&tank_layout);

    label_name.setAlignment(Qt::AlignCenter);

    // Capacity progress bar

    progress_c.setTextVisible(true);
    progress_c.setFormat("%p% (%v/%m)");

    // layout
    tank_layout.addWidget(&label_name);
    tank_layout.addWidget(&progress_c);
    tank_layout.addWidget(&label_etat);
}

void TankWidget::showInfos(int num_t, int num_etat, double cap){
    QString title = "Reservoir"+ QString::number(num_t);
    label_name.setText(title);
    QString etat = "Etat: "+ QString::number(num_etat);
    label_etat.setText(etat);
    //progress_c.setValue();
    progress_c.setRange(0,(int)cap);

}
