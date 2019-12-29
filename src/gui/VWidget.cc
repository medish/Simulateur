#include "../../include/gui/VWidget.h"




VWidget::VWidget(Valve * v)  {
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setMaximumSize(40,30);
    setText(QString::fromStdString(v->nom));
    setCheckable(true);
    setVanne(v->etat);
    QObject::connect(this, SIGNAL(toggled(bool)), this, SLOT(setVanne(bool)));

}

VWidget::~VWidget(){

}


void VWidget::setVanne(bool etat){
    if(etat == FERME)
        setStyleSheet("background-color : red;");
    else setStyleSheet("background-color : green;");
}

