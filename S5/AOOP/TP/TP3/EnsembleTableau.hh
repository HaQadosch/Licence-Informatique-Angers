#pragma once
#include "Ensemble.hh"
#include <stdio.h>

class EnsembleTableau: public Ensemble{
  public:
    /*fonctions*/
    bool appartient(int e) const override;
    bool estVide() const override;
    /*constructeurs*/
    EnsembleTableau()=default;
    EnsembleTableau(EnsembleTableau const & copied)/*:Ensemble(copied){}*/;
    ~EnsembleTableau()=default;
//    EnsembleTableau(Ensemble const & copied):Ensemble(copied);

  private:
    /*variables*/
    int * elem;
    std::size_t taille;
};
