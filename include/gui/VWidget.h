#ifndef VWIDGET_H
#define VWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "../core/Valve.h"

class VWidget : public QPushButton {
    Q_OBJECT
private:

public:
    VWidget(Valve *);
    ~VWidget();
public slots:
    void setVanne(bool = false);
};
#endif
