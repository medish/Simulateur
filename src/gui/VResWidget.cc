#include "../../include/gui/VResWidget.h"

VResWidget::VResWidget(ValveRes * v): VWidget(v){
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setMaximumSize(30,30);

}

VResWidget::~VResWidget(){

}
