#ifndef POMPEWIDGET_H
#define POMPEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QMenu>
#include "../core/Pompe.h"

class PompeWidget : public QPushButton{
    Q_OBJECT
private:
    QVBoxLayout p_layout;
    QToolButton qbtn;
    QLabel label_name, label_etat, label_m;
    void init();
public:
    PompeWidget();
    PompeWidget(Pompe *);
    ~PompeWidget();
    void showInfos(int, int, int);
public slots:
    void setEtatColor(int = 0);
    QString getEtatName(int);
};

#endif
