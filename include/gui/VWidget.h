#ifndef VWIDGET_H
#define VWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "../core/Valve.h"

class VWidget : public QPushButton {
private:

public:
    VWidget(Valve &);
    ~VWidget();
};
#endif
