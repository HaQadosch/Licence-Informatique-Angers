#include "EnsembleTableau.hh"
#include <cstddef>
#include <iostream>
/** \author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */

/*constructeurs*/
/*
EnsembleTableau::EnsembleTableau()
  : elem(nullptr){};
*/
EnsembleTableau::EnsembleTableau(EnsembleTableau const & copied)
  :elem((copied.elem==nullptr) ? nullptr : new int[copied.taille]), taille(copied.taille){
  for(std::size_t i=0;i<taille;i++){
    elem[i]=copied.elem[i];
  }

}

/*méthodes*/
bool EnsembleTableau::appartient(int e) const {
  for (std::size_t i=0;i<taille;i++){
    if(e==elem[i])return true;
  }
  return false;
}

bool EnsembleTableau::estVide() const {
  return(taille==0);
}

void EnsembleTableau::ajouterSansVerif(int e){
  int * nouv = new int[taille + 1];
  for (std::size_t i=0; i<taille; ++i){
    nouv[i]=elem[i];
  }
  nouv[taille]=e;
  delete [] elem;
  elem=nouv;
  ++taille;
}

void EnsembleTableau::afficher1() const{
  for (std::size_t i=0; i<taille; ++i){
    std::cout << elem[i]<<" ";
  }
  std::cout << std::endl;
}

void EnsembleTableau::enlever(int e){
  for(size_t i=0;i<taille;++i){
    if( elem[i]==e){
      if(taille==1){
          delete [] elem;
          elem = nullptr;
      }
      else { // on prends la dernière valeur, et on la place à l'emplacement de celle qu'on veut supprimer
        elem[i]=elem[taille-1];
      }
      taille --;
      return; // a la place de break;
    }
  }
}
/* méthodes de parcours */
bool EnsembleTableau::estFini(parcours const & p) const{
  return p.position>=taille;
}

int EnsembleTableau::acces(parcours const & p) const{
  return elem[p.position()];
}

void vider(){
  delete [] contenu;
  contenu =nullptr;
  taille=0;
}
