#ifndef MAINGUI_H
#define MAINGUI_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QPainter>
#include <QList>
#include <QTimer>
#include <QTime>
#include <QtConcurrent/QtConcurrent>
#include "TankWidget.h"
#include "PompeWidget.h"
#include "MoteurWidget.h"
#include "NavBarWidget.h"
#include "VWidget.h"
#include "../core/Systeme.h"
#include "MyQWidget.h"

class MainGui : public QWidget{
    Q_OBJECT
private :
    Systeme * sys;
    QGridLayout  main_layout;
    QWidget * middle_w;
    QTimer timerSim, timerRept;
    QTime time;
    void init();
public:
    MainGui(Systeme *);
    ~MainGui();
    void updateGui();
    Systeme * getSysteme(){return sys;}
    QString getTime(){return time.toString("hh:mm:ss");}
public slots:
    void updateConsommation();
    void startSimulation();
    void stopSimulation();

};


#endif
