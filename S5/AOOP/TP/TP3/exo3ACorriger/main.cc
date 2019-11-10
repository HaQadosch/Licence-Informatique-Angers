#include <iostream>
#include <string>
#include <sstream>
//#include "EnsembleTableau.hh"
#include "EnsembleVector.hh"
/** \author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */

void testEnsemble(Ensemble & e1, Ensemble & e2, Ensemble & e3){
  std::cout << "1. 0->" << e1.appartient(12) << std::endl;
  std::cout << "2. 1->" << e1.estVide() << std::endl;
  e1.ajouter(4);e1.ajouter(5);e1.ajouter(4);
  std::cout << "3. 1->" << e1.appartient(5) << std::endl;
  std::cout << "4. 0->" << e1.appartient(6) << std::endl;
  std::cout <<"5. 4 5->"; e1.afficher1()
  std::cout <<"5b. 4 5->"; e1.afficher1()
  for(parcours p=e1.commencer();!e1.estFini(p);e1.suivant(p)){
    std::cout << e1.acces(p)<<" ";
  }
  std::cout<<std::endl;
  std::cout <<"5c 4 5->";e1.afficher();
  e1.enlever(6);e1.enlever(4);
  std::cout <<"6. 5->" ; e1.afficher1();
  e1.enlever(5);
  e1.ajouter(6);e2.ajouter(12;) e2.ajouter(5);
  e3.ajouter(50);
  e3.calculerUnion(e1,e2);
  std::cout <<"7. 5 6 12->"; e3.afficher();
  e3.calculerIntersetion(e1,e2);
  std::cout <<"8. ?->"; e3.afficher();
  e3.calculerDifference(e1,e2);
  std::cout <<"9.6->"; e3.afficher();
}


int main(){
// partie 3 du TP
  EnsembleVector ev1, ev2, ev3;
  testEnsemble(ev1, ev2, ev3);
/*EnsembleTableau et1;
testEnsemble(ev1, ev2, et1);*/
  return 0;
}
