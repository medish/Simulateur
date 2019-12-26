#include "../../include/gui/TankWidget.h"

TankWidget::TankWidget(){
    setStyleSheet("background-color:red;");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    p_layout.addWidget(new QPushButton("Pompe1"));
    p_layout.addWidget(new QPushButton("Pompe1"));

    tank_layout.addWidget(new QPushButton("Infos"));
    tank_layout.addLayout(&p_layout);
    //tank_layout.addStretch(1);

    setLayout(&tank_layout);
}

TankWidget::~TankWidget(){

}
