#ifndef H_XMLPARSER
#define H_XMLPARSER

#include "../core/Systeme.h"
#include "panne.h"
#include <iostream>
#include <vector>
#include <QVector>
#include <QFile>
#include <QMessageBox>
#include <QWidget>
#include <QDebug>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>
#include <QtXml/QDomElement>

class xmlparser: public QWidget{
private:
    QFile* file;
    QDomDocument* dom;
    Systeme* sys;
    //Ajouter le tableau de pannes
    QVector<panne*> pannes;
public:
    xmlparser();
    xmlparser(QString filepath);
    ~xmlparser();
    //Getters
    Systeme* GetSysteme() {return sys;}
    //Retourner le tableau de pannes
    QVector<panne*> * getPannes() {return &pannes;};
    static QVector<panne*> * sortedPannes(QVector<panne*> *);
    //Retourne un systeme initialisé et une structure de stockage des pannes
    void parseXmlFile();
    static panne* GetRandomPannes(int nb, int duree);
};
#endif
