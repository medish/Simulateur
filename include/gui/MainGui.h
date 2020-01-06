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
    QVector<panne*>  pannes;
    int size_p_vector;
    QGridLayout  main_layout;
    QWidget * middle_w;
    QTimer timerSim, timerRept, timerPanne;
    QTime time;
    void init();
public:
    MainGui(Systeme *, QVector<panne *> *);
    ~MainGui();
    void updateGui();
    void preparePanne();
    void evaluatePanne();
    Systeme * getSysteme(){return sys;}
    QString getTime(){return time.toString("hh:mm:ss");}
public slots:
    void updateConsommation();
    void startSimulation();
    void stopSimulation();
    void applyPanne();

};


#endif
