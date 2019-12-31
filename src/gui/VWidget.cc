﻿#include "../../include/gui/VWidget.h"




VWidget::VWidget(Valve * _v)  {
    v = _v;
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setMaximumSize(40,30);
    setText(QString::fromStdString(_v->nom));
    setCheckable(true);
    setVanne(_v->etat);
    QObject::connect(this, SIGNAL(toggled(bool)), this, SLOT(setVanne(bool)));

}

VWidget::~VWidget(){

}


void VWidget::setVanne(bool etat){
    if(etat)
        if(v->setEtat(OUVERT)){
             setStyleSheet("background-color : green;");

        }else {
            setChecked(!etat);
        }
   else
        if(v->setEtat(FERME)){
             setStyleSheet("background-color : red;");
        }else {
           setChecked(!etat);
        }

}

