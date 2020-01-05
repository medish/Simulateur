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
    std::vector<panne*> pannes;
public:
    xmlparser();
    xmlparser(QString filepath);
    ~xmlparser();
    //Getters
    Systeme* GetSysteme() {return sys;}
    //Retourner le tableau de pannes
    std::vector<panne*> * getPannes()  {return &pannes;};
    //Retourne un systeme initialisé et une structure de stockage des pannes
    void parseXmlFile();
    static std::vector<panne*> GetRandomPannes(int nb, int duree);
};
#endif
