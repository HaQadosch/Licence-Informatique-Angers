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

void Ensemble::suivant(Parcours & p) const{
  p.suivant();
}

void Ensemble::afficher() const{
  for(Parcours p=commencer();!estFini(p);suivant(p)){
    std::cout << acces(p);
  }
}

void Ensemble::calculerUnion(Ensemble const & e1, Ensemble const & e2){
    vider();
    for(Parcours p=commencer();!estFini(p);suivant(p))
      ajouter(e1.acces(p));
    for(Parcours p=commencer();!estFini(p);suivant(p))
      ajouter(e2.acces(p));
}

void Ensemble::calculerIntersection(ensemble const & e1, ensemble const & e2){
  vider();
  for(Parcours p=commencer();!estFini(p);suivant(p))
    if(e2.appartient(e1.acces(p)))
      ajouter(e1.acces(p));
}

void Ensemble::calculerDifference(ensemble const & e1, ensemble const & e2){
  vider();
  for(Parcours p=commencer();!estFini(p);suivant(p))
    if(!e2.appartient(e1.acces(p)))
      ajouter(e1.acces(p));
}
