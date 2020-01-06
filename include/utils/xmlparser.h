#ifndef H_XMLPARSER
#define H_XMLPARSER

#include "../core/Systeme.h"
#include "panne.h"
#include <iostream>
#include <vector>
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
    xmlparser(const char* filepath);
    ~xmlparser();
    //Getters
    Systeme* GetSysteme() {return sys;}
    //Retourner le tableau de pannes
    QVector<panne*> * getPannes() {return &pannes;};
    //Retourne un systeme initialisé et une structure de stockage des pannes
    void parseXmlFile();
};
#endif
