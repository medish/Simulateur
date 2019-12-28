#ifndef TANKWIDGET_H
#define TANKWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include "../core/Reservoir.h"
#include "PompeWidget.h"

class TankWidget : public QWidget {
private:
    QVBoxLayout tank_layout;
    QHBoxLayout p_layout;
    QProgressBar progress_c;
    QLabel label_name, label_etat;
    void init();

public:
    TankWidget();
    TankWidget(Reservoir &);
    ~TankWidget();
    void showInfos(int, int, double);

};
#endif // TANKWIDGET_H
