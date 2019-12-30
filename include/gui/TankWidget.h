#ifndef TANKWIDGET_H
#define TANKWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QFormLayout>
#include <QComboBox>
#include <QPainter>
#include "../core/Reservoir.h"

class TankWidget : public QLabel {
    Q_OBJECT
private:
    Reservoir * r;
    QVBoxLayout tank_layout;
    QHBoxLayout p_layout;
    QFormLayout f_layout;
    QProgressBar progress_c;
    QComboBox combo_etat;
    QLabel label_name;
    void init();

public:
    TankWidget(Reservoir *);
    ~TankWidget();
    void showInfos(int, int, double);

public slots:
    void setEtatColor(int = 0);


};
#endif // TANKWIDGET_H
