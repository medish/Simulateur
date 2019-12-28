#include "../../include/gui/VWidget.h"

VWidget::VWidget() : QPushButton("V"){
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setMaximumSize(30,30);

}

VWidget::~VWidget(){

}
