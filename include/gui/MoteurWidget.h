#ifndef MOTEURWIDGET_H
#define MOTEURWIDGET_H

#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QFormLayout>
#include "../core/Moteur.h"

class MoteurWidget : public QLabel {
    Q_OBJECT
private:
    Moteur * m;
    QVBoxLayout m_layout;
    QFormLayout f_layout;
    QComboBox combo_t_p, combo_etat;
    QLabel label_name;
    void init();

public:
    MoteurWidget(Moteur *);
    ~MoteurWidget();
    void showInfos(int, int, int, int);
public slots:
    void setEtatColor(int = 0);
};

#endif
