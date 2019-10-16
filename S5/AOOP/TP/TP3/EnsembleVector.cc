#include "EnsembleVector.hh"
/** \author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */

/*constructeurs*/

/*fonctions */
bool EnsembleVector::appartient(int e) const {
  for(auto i: elem){
    if(i==e)return true;
  }
  return false;
}


bool EnsembleVector::estVide() const {
  return elem.empty();
}
