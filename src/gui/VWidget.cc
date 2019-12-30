#include "../../include/gui/VWidget.h"




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
    if(etat == FERME)
        setStyleSheet("background-color : red;");
    else setStyleSheet("background-color : green;");
}

