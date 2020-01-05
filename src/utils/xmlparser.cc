#include "../../include/utils/xmlparser.h"


xmlparser::xmlparser(){

}

xmlparser::xmlparser(const char* filepath){
    file = new QFile(filepath);
    if(!(file->open(QIODevice::ReadOnly))){
         QMessageBox::warning(this, "Erreur à l'ouverture du document XML",
                              "Le document XML n'a pas pu être ouvert.");
    }
    dom = new QDomDocument();
    QString errorStr;
    int errorLine;
    int errorColumn;
    //Récuperation des éléments du fichiers XML
    if (!dom->setContent(file, false, &errorStr, &errorLine, &errorColumn))
            qDebug() << errorStr << errorLine << errorColumn;
    }

xmlparser::~xmlparser(){
    file->close();
    delete file;
}

void xmlparser::parseXmlFile(){
      int tab[7];
      int i = 0;
      QDomElement docElem = dom->documentElement();//Simulateur
      sys = new Systeme(docElem.attributeNode("capacite").value().toDouble(),
                        docElem.attributeNode("consomation").value().toDouble(),
                        docElem.attributeNode("duree").value().toInt(),
                        docElem.attributeNode("tempsactuel").value().toInt());

      QDomNode n = docElem.firstChild();//Pannes
      QDomNode nn = n.firstChild(); //Panne

/*
 *     std::cout << "DEBUG: " << docElem.nodeName().toStdString() << std::endl;
 *     std::cout << "DEBUG: " <<n.nodeName().toStdString() << std::endl;
 *     std::cout << "DEBUG: " <<docElem.attributeNode("consomation").value().toStdString() << std::endl;
 *     std::cout << "DEBUG: " <<docElem.attributeNode("duree").value().toStdString() << std::endl;
 *     std::cout << "DEBUG: " <<docElem.attributeNode("capacite").value().toStdString() << std::endl;
*/
      while (!nn.isNull() ) {
          QDomNode panelem = nn.firstChild();
          i = 2;
           while(!panelem.isNull()){
/*
 *     std::cout << nn.toElement().attribute("id", "").toInt() << std::endl;
 *     std::cout << panelem.toElement().tagName().toStdString() << std::endl;
 *     std::cout << panelem.toElement().text().toStdString() << std::endl <<"*********" << std::endl;
*/
               tab[0] = nn.toElement().attribute("id", "").toInt();
               tab[1] = nn.toElement().attribute("idparent", "").toInt();
               tab[i] = panelem.toElement().text().toInt();
               i++;
               panelem = panelem.nextSibling();
             }

           pannes.push_back(new panne(tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6]));

          nn = nn.nextSibling();
      }
     /*for (int z= 0; z < 7; z++) {
            std::cout << tab[z] << std::endl;
        }

*/
}
