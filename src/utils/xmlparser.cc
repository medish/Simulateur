#include "../../include/utils/xmlparser.h"


xmlparser::xmlparser(){

}

xmlparser::xmlparser(const char* filepath){
    file = new QFile(filepath);
    if(!(file->open(QIODevice::ReadOnly))){
         QMessageBox::warning(this, "Erreur à l'ouverture du document XML", "Le document XML n'a pas pu être ouvert.");
    }
    dom = new QDomDocument();
    //Récuperation des éléments du fichiers XML
    if(!dom->setContent(file)){
         file->close();
         QMessageBox::warning(this, "Erreur à la lecture du document XML", "Le document XML n'a pas pu être lu.");
    }
}

xmlparser::~xmlparser(){
    file->close();
    delete file;
}

void xmlparser::parseXmlFile(){
      QDomElement docElem = dom->documentElement() ;
      QDomNode n = docElem.firstChild();
      std::cout << docElem.attributeNode("consomation").value().toStdString() << std::endl;
      QDomNode panne = docElem.firstChild().firstChild();
      std::cout <<panne.attributes().namedItem("id").toAttr().value().toStdString()<< std::endl;
      while(!n.isNull())
      {
          QDomElement e = n.toElement();
          // C'est ici que l'on va marquer le code
          n = n.nextSibling();
      }
}
