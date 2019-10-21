#pragma once
#include "Ensemble.hh"
#include <vector>

class EnsembleVector: public Ensemble{
  public:
    /*fonctions*/
    bool appartient(int e) const override;
    bool estVide() const override;
    void afficher1() const override;
    /*constructeurs*/
    EnsembleVector()=default;
    EnsembleVector(EnsembleVector const & copied)=default;
    ~EnsembleVector()=default;

  protected:
    void ajoutersansverif(int e)override;

  private:
    /*variables*/
    std::vector<int> elem;
};
