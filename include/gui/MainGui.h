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

class MainGui : public QWidget{
private :
    QGridLayout  main_layout;
    QWidget * middle_w;
public:
    MainGui();
    ~MainGui();
protected:
    void paintEvent(QPaintEvent *event);
};


#endif
