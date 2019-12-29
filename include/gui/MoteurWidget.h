#ifndef MOTEURWIDGET_H
#define MOTEURWIDGET_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "../core/Moteur.h"

class MoteurWidget : public QPushButton {
    Q_OBJECT
private:
    QVBoxLayout m_layout;
    QLabel label_name, label_tank, label_pompe, label_etat;
    void init();

public:
    MoteurWidget(Moteur *);
    ~MoteurWidget();
    void showInfos(int, int, int, int);
public slots:
    void setEtatColor(int = 0);
    QString getEtatName(int);
};

#endif
