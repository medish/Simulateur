#ifndef H_XMLPARSER
#define H_XMLPARSER

#include "../core/Systeme.h"
#include <QFile>
#include <QMessageBox>
#include <iostream>
#include <QWidget>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>
#include <QtXml/QDomElement>

class xmlparser: public QWidget{
private:
    QFile* file;
    QDomDocument* dom;
    Systeme* sys;
    //Ajouter le tableau de pannes

public:
    xmlparser();
    xmlparser(const char* filepath);
    ~xmlparser();
    //Getters
    Systeme* GetSysteme() const{return this->sys;}
    //Retourner le tableau de pannes

    //Retourne un systeme initialisé et une structure de stockage des pannes
    void parseXmlFile();
};
#endif
