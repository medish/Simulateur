#include "../../include/gui/NavBarWidget.h"


NavBarWidget::NavBarWidget(): btn1("Button1"), btn2("Button2"){
    setLayout(&v_layout);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setStyleSheet("background-color : purple");
    setMaximumWidth(300);
    setMinimumWidth(200);
    v_layout.setAlignment(Qt::AlignTop);

    f_layout.addRow("Temps restant",&label_time);
    f_layout.addRow("Capacité", &label_cap);
    f_layout.addRow("Consommation",&label_conso);

    v_layout.addLayout(&f_layout);
    v_layout.addWidget(&btn1);
    v_layout.addWidget(&btn2);
}

NavBarWidget::~NavBarWidget(){

}

void NavBarWidget::showInfos(){
    //qDebug("navbar");
}
