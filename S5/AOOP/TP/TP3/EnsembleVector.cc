#include "EnsembleVector.hh"
#include <iostream>
#include <algorithm>
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


void EnsembleVector::ajouterSansVerif(int e){
  elem.push_back(e);
}

void EnsembleVector::afficher1() const{
  for(auto i: elem)
    std::cout << i << " ";
  std::cout << std::endl;
}

void EnsembleVector::enlever(int e){
  auto it=std::find(elem.begin(), elem.end(),e );
  if(it != elem.end()){
    elem.erase(it);
  }/* autre code possible, plus long :
  for(auto i =elem.begin(); i!= elem.end();++i){
    if((*i)==e){
      elem.erase(i);
      return;
    }
  }*/
}

/*methodes de parcours */

bool EnsembleVector::estFini(parcours const & p) const{
  return p.position>=elem.size();
}

int EnsembleVector::acces(parcours const & p) const{
  return elem[p.position()];
}
