#ifndef TANKWIDGET_H
#define TANKWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
class TankWidget : public QWidget {
private:
    QVBoxLayout tank_layout;
    QHBoxLayout p_layout;

public:
    TankWidget();
    ~TankWidget();
};
#endif // TANKWIDGET_H
