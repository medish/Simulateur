#include "../../include/gui/VMRWidget.h"

VMRWidget::VMRWidget(MainGui * _mainGui, ValveMr * v): VWidget(_mainGui,v){
    vmr = v;

}

VMRWidget::~VMRWidget(){

}

void VMRWidget::showInfos(){
    qDebug("vmrwidget");
}
