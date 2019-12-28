#ifndef NAVBARWIDGET_H
#define NAVBARWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class NavBarWidget : public QWidget{
private:
    QVBoxLayout v_layout;
    QPushButton btn1, btn2;
public:
    NavBarWidget();
    ~NavBarWidget();
};
#endif
