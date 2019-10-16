#include <iostream>
#include <string>
#include <sstream>
#include "EnsembleTableau.hh"
#include "EnsembleVector.hh"
/** \author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */

void testEnsemble(Ensemble & e1, Ensemble & e2){
  std::cout << "1. 0->" << e1.appartient(12) << std::endl;
  std::cout << "2. 1->" << e1.estVide() << std::endl;
}


int main(int argc,char * argv[]){
  //en fonction du num d'exercice, on change l'execution
  if(argc!=2){
      std::cout<<"utilisation:"<<std::endl;
      std::cout<<"./exe [numero de la partie du TP à tester]"<<std::endl;
  }else{
    switch(std::stoi(argv[1])){

      case(1): { // Partie 1 du TP
        std::ostringstream out;
        int entier(42);
        out << entier; // fonctionne avec tout type pouvant être envoyé sur flux
        std::string s(out.str());
        std::cout << s << std::endl;
        return 0;
        break;}

      case(2):{ // partie 2 du TP
        break;}

      case(3):{ // partie 3 du TP
        EnsembleTableau et1, et2;
        testEnsemble(et1, et2);
        break;}

      case(4):{ // partie 4 du TP
        break;}

      default:{ // cas erreur
        std::cout<<"entrez le numero d'un exercice existant"<<std::endl;
        break;}
    }//fin switch-case
  }//fin else
  return 0;
}