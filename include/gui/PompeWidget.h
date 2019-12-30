#ifndef POMPEWIDGET_H
#define POMPEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QFormLayout>
#include <QDebug>
#include "../core/Pompe.h"

class PompeWidget : public QLabel{
    Q_OBJECT
private:
    Pompe * p;
    QVBoxLayout p_layout;
    QFormLayout f_layout;
    QComboBox combo_etat, combo_m;
    QLabel label_name;
    void init();
public:
    PompeWidget(Pompe *);
    ~PompeWidget();
    void showInfos(int, int, int);
public slots:
    void setEtatColor(int = 0);
};

#endif
