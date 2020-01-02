#ifndef MYQWIDGET_H
#define MYQWIDGET_H
#include <QWidget>

class MyQWidget : public QWidget {
public:
    virtual void showInfos()=0;
};

#endif
