#pragma once
#include "Ensemble.hh"
#include <cstddef>

class EnsembleTableau: public Ensemble{
  public:
    /*fonctions*/
    bool appartient(int e) const override;
    bool estVide() const override;
    void ajouter(int e);
    void afficher1() const override;
    /*constructeurs*/
    EnsembleTableau()=default;
    EnsembleTableau(EnsembleTableau const & copied)/*:Ensemble(copied){}*/;
    ~EnsembleTableau()=default;
//    EnsembleTableau(Ensemble const & copied):Ensemble(copied);

  protected:
    void ajoutersansverif(int e) override;

  private:
    /*variables*/
    int * elem;
    std::size_t taille;
};
