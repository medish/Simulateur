#ifndef MOTEURWIDGET_H
#define MOTEURWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "../core/Moteur.h"

class MoteurWidget : public QWidget {
private:
    QVBoxLayout m_layout;
    QLabel label_name, label_tank, label_pompe, label_etat;
    void init();

public:
    MoteurWidget();
    MoteurWidget(Moteur &);
    ~MoteurWidget();
    void showInfos(int, int, int, int);
};

#endif
