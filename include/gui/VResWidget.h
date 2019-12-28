#ifndef VRESWIDGET_H
#define VRESWIDGET_H

#include "VWidget.h"
#include "../core/ValveRes.h"

class VResWidget : public VWidget {
private:

public:
    VResWidget(ValveRes &);
    ~VResWidget();
};

#endif
