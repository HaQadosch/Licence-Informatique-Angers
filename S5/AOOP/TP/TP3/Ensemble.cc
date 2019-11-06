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

void Ensemble::calculerUnion(ensemble const & e1, ensemble const & e2){
    vider();
    for(parcours p=e1.commencer();. . . suivant(p))
      ajouter(e1.acces(p));
    for(parcours p=e2.commencer();. . . suivant(p))
      ajouter(e2.acces(p));
}

void Ensemble::calculerIntersetion(ensemble const & e1, ensemble const & e2){
  vider();
  for ( parcours )
    if(e2.appartient(e1.acces(p)))
      ajouter(e1.acces(p));
}

void Ensemble::calculerDifference(ensemble const & e1, ensemble const & e2){
  vider();
  for ( parcours )
    if(!e2.appartient(e1.acces(p)))
      ajouter(e1.acces(p));
}
