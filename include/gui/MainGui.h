#ifndef MAINGUI_H
#define MAINGUI_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "TankWidget.h"

class MainGui : public QWidget{
private :
    QGridLayout  main_layout;
public:
    MainGui();
    ~MainGui();
};


#endif
