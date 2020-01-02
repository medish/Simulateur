#include "../../include/gui/NavBarWidget.h"


NavBarWidget::NavBarWidget(): btn1("Button1"), btn2("Button2"){
    setLayout(&v_layout);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setStyleSheet("background-color : purple");
    setMaximumWidth(300);
    setMinimumWidth(200);
    v_layout.setAlignment(Qt::AlignTop);

    v_layout.addWidget(&btn1);
    v_layout.addWidget(&btn2);
}

NavBarWidget::~NavBarWidget(){

}

void NavBarWidget::showInfos(){
    //qDebug("navbar");
}
