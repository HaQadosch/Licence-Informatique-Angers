#include "Ensemble.hh"


void Ensemble::ajouter(int e){
  if (!appartient(e)){
    ajoutersansverif(e);
  }
}
