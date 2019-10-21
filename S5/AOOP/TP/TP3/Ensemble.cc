#include "Ensemble.hh"


void Ensemble::ajouter(int e){
  if (!appartient(e)){
    ajouterSansVerif(e);
  }
}

Parcours Ensemble::commencer() const{
  parcours p;
  return p;
}

void Ensemble::suivant(parcours & p) const{
  p.suivant();
}

void Ensemble::afficher() const{
  for(parcours p=commencer();!estFini(p);suivant(p)){
    std::cout << acces(p);
  }
}
