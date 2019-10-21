#pragma once
#include "Ensemble.hh"
#include <vector>

class EnsembleVector: public Ensemble{
  public:
    /*fonctions*/
    bool appartient(int e) const override;
    bool estVide() const override;
    void ajouter(int e);
    void afficher1() const override;
    void enlever(int e);
    /*constructeurs*/
    EnsembleVector()=default;
    EnsembleVector(EnsembleVector const & copied)=default;
    ~EnsembleVector()=default;

  protected:
    void ajouterSansVerif(int e) override;

  private:
    /*variables*/
    std::vector<int> elem;
};
