#include "../../include/gui/VResWidget.h"

VResWidget::VResWidget(MainGui * _mainGui, ValveRes * v): VWidget(_mainGui, v){
    vres = v;

}

VResWidget::~VResWidget(){

}

void VResWidget::showInfos(){
   // qDebug("vreswidget");
}
