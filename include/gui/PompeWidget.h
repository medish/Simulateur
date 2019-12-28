#ifndef POMPEWIDGET_H
#define POMPEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "../core/Pompe.h"

class PompeWidget : public QPushButton{
private:
    QVBoxLayout p_layout;
    QLabel label_name, label_etat, label_m;
    void init();
public:
    PompeWidget();
    PompeWidget(Pompe &);
    ~PompeWidget();
    void showInfos(int, int, int);
};

#endif
