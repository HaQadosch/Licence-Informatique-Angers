#include <iostream>
#include <stdlib.h>
#include "TaillePosition.hh"
#include "Sequence.hh"

/** \author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */

int main(int argc,char * argv[]){
  //en fonction du num d'exercice, on change l'execution
  if(argc!=2){
      std::cout<<"utilisation:"<<std::endl;
      std::cout<<"./nomprog [numero de la partie du TP à tester]"<<std::endl;
  }else{
    switch(std::stoi(argv[1])){

      case(1): { // Partie 1 du TP
        Position pos1(22,05);
        Position pos2(pos1);
        if(pos2.comparaison(pos1)){
          std::cout<<"nice, sucess, ça marche!"<<std::endl;
        }
        break;}

      case(2):{ // partie 2 du TP
        Sequence a;
      	a.ajouter(couleur::rouge);
      	a.ajouter(couleur::bleu);
      	a.ajouter(couleur::rouge);
      	a.ajouter(couleur::vert);
        Sequence b(a); // voir question 3
      	a.afficher(a.acces(0)); std::cout << "\n";
      	for (indiceSequence i=0; i<a.getTaille(); ++i)
      		a.afficher(a.acces(i));
      	std::cout << "\n";
      	a.vider();
      	std::cout << "A: "; a.afficher(std::cout); // voir question 4
      	std::cout << "B: "; b.afficher(std::cout);
      	std::cout << a.comparer(b) << "\n";
      	a.copier(b); // voir question 5
      	std::cout << a.comparer(b) << "\n";
        break;}

      case(3):{ // partie 3 du TP
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
