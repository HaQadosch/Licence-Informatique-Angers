#pragma once
#include "Ensemble.hh"

class EnsembleTableau: public Ensemble{
  public:
    /*fonctions*/

    /*constructeurs*/
    EnsembleTableau():Ensemble();
    EnsembleTableau(EnsembleTableau const & copied):Ensemble(copied);
//    EnsembleTableau(Ensemble const & copied):Ensemble(copied);

  private:
    /*variables*/
    int elem[];
};
