#ifndef VMRWIDGET_H
#define VMRWIDGET_H

#include "VWidget.h"
#include "../core/ValveMR.h"

class VMRWidget : public VWidget {
private:

public:
    VMRWidget(ValveMr &);
    ~VMRWidget();
};

#endif
