#ifndef MAINGUI_H
#define MAINGUI_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QPainter>
#include "TankWidget.h"
#include "PompeWidget.h"
#include "MoteurWidget.h"
#include "NavBarWidget.h"
#include "VWidget.h"
#include "../core/Systeme.h"

class MainGui : public QWidget{
private :
    QGridLayout  main_layout;
    QWidget * middle_w;
    void init(std::vector<Reservoir*>, std::vector<Moteur*>, std::vector<Valve*>);
public:
    MainGui(Systeme *);
    ~MainGui();
protected:
    void paintEvent(QPaintEvent *);
};


#endif
