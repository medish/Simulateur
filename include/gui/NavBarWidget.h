#ifndef NAVBARWIDGET_H
#define NAVBARWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QLabel>
#include "MyQWidget.h"
class NavBarWidget : public QWidget, public MyQWidget{
private:
    QVBoxLayout v_layout;
    QFormLayout f_layout;
    QLabel label_conso, label_cap, label_time;
    QPushButton btn1, btn2;
public:
    NavBarWidget();
    ~NavBarWidget();
    void showInfos() override;
};
#endif
