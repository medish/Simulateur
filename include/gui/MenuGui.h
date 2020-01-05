#ifndef H_MENUGUI
#define H_MENUGUI

#include "../states/Loginstate.h"
#include "../states/MainGState.h"
#include "../states/MenuState.h"

#include <iostream>
#include <string>
#include <cstring>
#include <QObject>
#include <QCursor>
#include <QApplication>
#include <QWidget>
#include <QIcon>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPixmap>
#include <QMessageBox>

class MenuState;

class MenuGui: public QWidget{
    Q_OBJECT
  private:
    MenuState* menu;
    QVBoxLayout* mainlayout;
    QPushButton* newgame;
    QPushButton* charger;
    QPushButton* libre;
    QPushButton* quit;
  public:
    MenuGui(MenuState* state);
    ~MenuGui();

};

#endif
