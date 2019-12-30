#include "../../include/gui/VMRWidget.h"

VMRWidget::VMRWidget(ValveMr * v): VWidget(v){
    vmr = v;
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setMaximumSize(30,30);

}

VMRWidget::~VMRWidget(){

}
