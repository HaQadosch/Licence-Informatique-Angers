#include "EnsembleTableau.hh"
#include <stdio.h>
/** \author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */

/*constructeurs*/
EnsembleTableau::EnsembleTableau()
  : elem(nullptr){};

EnsembleTableau::EnsembleTableau(EnsembleTableau const & copied)
  :elem((e.elem==nullptr) ? nullptr : new int[e.taille]), taille(e.taille){
  for(std::size_t i=0;i<taille;i++){
    elem[i]=e.elem[i];
  }

}

/*fonctions*/
bool EnsembleTableau::appartient(int e) const {
  for (std::size_t i;i<taille;i++){
    if(e==elem[i])return true;
  }
  return false;
}

bool EnsembleTableau::estVide() const {
  return(taille==0);
}
