#ifndef MAINGUI_H
#define MAINGUI_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QPainter>
#include <QList>
#include "TankWidget.h"
#include "PompeWidget.h"
#include "MoteurWidget.h"
#include "NavBarWidget.h"
#include "VWidget.h"
#include "../core/Systeme.h"
#include "MyQWidget.h"

class MainGui : public QWidget{
private :
    Systeme * sys;
    QGridLayout  main_layout;
    QWidget * middle_w;
    void init(std::vector<Reservoir*>, std::vector<Moteur*>, std::vector<Valve*>);
public:
    MainGui(Systeme *);
    ~MainGui();
    void updateGui();
    Systeme * getSysteme(){return sys;}
protected:
    void paintEvent(QPaintEvent *);
};


#endif
