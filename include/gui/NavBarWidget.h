#ifndef NAVBARWIDGET_H
#define NAVBARWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "MyQWidget.h"
class NavBarWidget : public QWidget, public MyQWidget{
private:
    QVBoxLayout v_layout;
    QPushButton btn1, btn2;
public:
    NavBarWidget();
    ~NavBarWidget();
    void showInfos() override;
};
#endif
