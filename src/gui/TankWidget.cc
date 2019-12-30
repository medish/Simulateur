#include "../../include/gui/TankWidget.h"


TankWidget::TankWidget(Reservoir * _r){
    r = _r;
    init();
    showInfos(_r->num, _r->etat, _r->capacity);

}

TankWidget::~TankWidget(){

}

void TankWidget::init(){
    //setStyleSheet("background-color:red; ");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMaximumHeight(120);
    setMinimumHeight(120);
    setLayout(&tank_layout);


    label_name.setAlignment(Qt::AlignCenter);
    label_name.setStyleSheet("font-weight: bold; font-size:16px;");

    // Capacity progress bar
    progress_c.setValue(50);
    progress_c.setTextVisible(true);
    progress_c.setFormat("%p% (%v/%m)");


    // Etat QTool button
    combo_etat.addItem("VIDE");
    combo_etat.addItem("PLEIN");
    combo_etat.addItem("REMPLISSAGE");
    combo_etat.addItem("VIDANGE");

    // form layout
    f_layout.addRow("Etat :", &combo_etat);

    // layout
    tank_layout.addWidget(&label_name);
    tank_layout.addWidget(&progress_c);
    tank_layout.addLayout(&f_layout);
}

void TankWidget::showInfos(int num_t, int num_etat, double cap){
    QString title = "Reservoir "+ QString::number(num_t);
    label_name.setText(title);
    combo_etat.setCurrentIndex(num_etat);
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

//void TankWidget::paintEvent(QPaintEvent * ){
//    qDebug("aa");
//    QStyleOption opt;
//    opt.init(this);
//    QPainter p(this);
//    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
//}
