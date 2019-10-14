#pragma once
#include "Ensemble.hh"

class EnsembleTableau: public Ensemble{
  public:
    /*fonctions*/

    /*constructeurs*/
    EnsembleTableau():Ensemble();
    EnsembleTableau(Ensemble const & copied):Ensemble(copied);

  private:
    /*variables*/
};
